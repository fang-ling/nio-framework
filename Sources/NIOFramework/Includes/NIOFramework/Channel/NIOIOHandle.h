/*===----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------===*
 *
 *  NIOIOHandle.h
 *  nio-framework
 *
 *  Created by Fang Ling on 2026/11/1.
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

#ifndef NIO_IO_HANDLE_H
#define NIO_IO_HANDLE_H

#import <NIOFramework/Channel/NIOIOEvent.h>
#import <NIOFramework/Channel/NIOIORegistration.h>

#import <CFramework/CFramework.h>
#import <ObjectiveCFramework/ObjectiveCFramework.h>

C_ASSUME_NONNULL_BEGIN

/**
 * A handle that can be registered to an ``NIOIOHandler``.
 *
 * All methods must be called from the ``NIOThreadAwareExecutor`` thread (which means ``NIOThreadAwareExecutor/isExecutorThread:`` must return ``CFramework/yes-macro``).
 *
 * All the methods are expected to be called from the ``NIOIOHandler`` on which this ``NIOIOHandle`` was registered via ``NIOIOHandler/registerIOHandle:``.
 */
@protocol NIOIOHandle <ObjectiveCObject>

/**
 * Be called once there is something to handle.
 *
 * - Parameters:
 *   - ioEvent: The ``NIOIOEvent`` that must be handled. The ``NIOIOEvent`` is only valid while this method is executed and so must not escape it.
 *   - registration: The ``NIOIORegistration`` for this ``NIOIOHandle``.
 */
- (void)handleIOEvent:(ObjectiveCAnyObject<NIOIOEvent>)ioEvent withRegistration:(ObjectiveCAnyObject<NIOIORegistration>)registration;

/**
 * Called once this ``NIOIOHandle`` was registered and so will start to receive events via ``handleIOEvent:withRegistration:``.
 */
- (void)handleDidRegister;

/**
 * Called once this ``NIOIOHandle`` was unregistered and so will not receive any more events via ``handleIOEvent:withRegistration:``.
 */
- (void)handleDidUnregister;

/**
 * Called once the ``NIOIOHandle`` should be closed.
 *
 * Even once this method is called this handle might still receive events via ``handleIOEvent:withRegistration:`` (if it was previous be registered and so its ``handleDidRegister`` method was called)
 * until the ``handleDidUnregister`` method is called.
 */
- (void)closeHandle; /* TODO: throws Exception. */

@end

C_ASSUME_NONNULL_END

#endif
