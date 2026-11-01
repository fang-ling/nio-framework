/*===----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------===*
 *
 *  NIOIOHandlerContext.h
 *  nio-framework
 *
 *  Created by Fang Ling on 2026/10/31.
 *
 *  This source file is part of the NIOFramework open source project
 *
 *  Copyright (c) 2026 Fang Ling <fangling@fangl.ing>
 *  Licensed under Apache License v2.0
 *
 *  See LICENSE for license information
 *
 *  SPDX-License-Identifier: Apache-2.0
 *
 *===----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------===*/

#ifndef NIO_IO_HANDLER_CONTEXT_H
#define NIO_IO_HANDLER_CONTEXT_H

#import <CFramework/CFramework.h>
#import <ObjectiveCFramework/ObjectiveCFramework.h>

C_ASSUME_NONNULL_BEGIN

/**
 * The context for an ``NIOIOHandler`` that is run by an ``NIOThreadAwareExecutor``.
 *
 * All methods **MUST** be executed on the ``NIOThreadAwareExecutor`` thread (which means ``NIOThreadAwareExecutor/isExecutorThread:`` must return ``CFramework/yes-macro``).
 */
@protocol NIOIOHandlerContext <ObjectiveCObject>

/**
 * ``CFramework/yes-macro`` if blocking for IO is allowed or if we should try to do a non-blocking request for IO to be ready.
 */
@property (nonatomic, assign, readonly) CBoolean canBlock;

/**
 * Returns the absolute point in time at which the next closest scheduled task should run or `-1` if nothing is scheduled to run.
 */
@property (nonatomic, assign, readonly) CInteger64 deadlineNanoseconds;

/**
 * ``CFramework/yes-macro`` if the I/O handler should measure and report its active I/O time.
 *
 * This is used as a guard to avoid the overhead of computing the uptime when the feature is not in use.
 */
@property (nonatomic, assign, readonly) CBoolean shouldReportActiveIOTime;

/**
 * Returns the amount of time left until the scheduled task with the closest deadline should run.
 *
 * - Parameter currentTimeNanoseconds: The current time in nanoseconds.
 *
 * - Returns: The delay in nanoseconds.
 */
- (CInteger64)delayNanosecondsWith:(CInteger64)currentTimeNanoseconds;

/**
 * Reports the amount of time in nanoseconds that was spent actively processing I/O events.
 *
 * This metric is needed for the dynamic, utilization-based auto-scaling feature in ``NIOMultithreadEventExecutorGroup``. The reported time allows the auto-scaler to accurately measure the I/O
 * workload of an event loop.
 *
 * ``NIOIOHandler`` subclasses should measure the time spent in their event processing logic and report the duration via this method. This should only include time spent actively handling ready I/O
 * events and should **not** include time spent blocking or waiting for I/O (e.g., in an `epoll_wait`) call.
 *
 * Failing to implement this method in an ``NIOIOHandlerContext`` that supports auto-scaling will result in the I/O utilization being perceived as zero.
 *
 * - Parameter activeNanoseconds: The duration in nanoseconds of active, non-blocking I/O work.
 */
- (void)reportActiveIOTimeWith:(CInteger64)activeNanoseconds;

@end

C_ASSUME_NONNULL_END

#endif
