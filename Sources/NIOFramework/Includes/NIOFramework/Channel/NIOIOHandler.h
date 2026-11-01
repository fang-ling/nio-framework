/*===----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------===*
 *
 *  NIOIOHandler.h
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

#ifndef NIO_IO_HANDLER_H
#define NIO_IO_HANDLER_H

#import <NIOFramework/Channel/NIOIOHandle.h>
#import <NIOFramework/Channel/NIOIOHandlerContext.h>
#import <NIOFramework/Channel/NIOIORegistration.h>

#import <CFramework/CFramework.h>
#import <ObjectiveCFramework/ObjectiveCFramework.h>

C_ASSUME_NONNULL_BEGIN

/**
 * Handles IO dispatching for an ``NIOThreadAwareExecutor``.
 *
 * All operations except ``wakeup`` and ``isCompatibleWithClass:`` **MUST** be executed on the ``NIOThreadAwareExecutor`` thread (which means ``NIOThreadAwareExecutor/isExecutorThread:`` must return
 * ``CFramework/yes-macro``) and should never be called from the user-directly.
 *
 * Once an ``NIOIOHandle`` is registered via the ``registerIOHandle:`` method it's possible to submit ``NIOIOOperations`` related to the ``NIOIOHandle`` via ``NIOIORegistration/submitIOOperations:``.
 * These submitted ``NIOIOOperations`` are the "source" of ``NIOIOEvent``s that are dispatched to the registered ``NIOIOHandle`` via the ``NIOIOHandle/handleIOEvent:withRegistration:`` method. These
 * events must be consumed (and handled) as otherwise they might be reported again until handled.
 */
@protocol NIOIOHandler <ObjectiveCObject>

/**
 * Initialize this ``NIOIOHandler``.
 */
- (void)initialize;

/**
 * Run the IO handled by this ``NIOIOHandler``.
 *
 * The ``NIOIOHandlerContext`` should be used to ensure we not execute too long and so block the processing of other task that are scheduled on the ``NIOThreadAwareExecutor``. This is done by taking
 * ``NIOIOHandlerContext/delayNanosecondsWith:`` or ``NIOIOHandlerContext/deadlineNanoseconds`` into account.
 *
 * - Parameter context: The ``NIOIOHandlerContext``.
 *
 * - Returns: The number of ``NIOIOHandle`` for which I/O was handled. Internal events such as wake-ups and timer expirations must not be included in this count.
 */
- (CInteger)runWithContext:(ObjectiveCAnyObject<NIOIOHandlerContext>)context;

/**
 * Prepare to destroy this ``NIOIOHandler``.
 *
 * This method will be called before ``destroy`` and may be called multiple times.
 */
- (void)prepareToDestroy;

/**
 * Destroy the ``NIOIOHandler`` and free all its resources.
 *
 * Once destroyed using the ``NIOIOHandler`` will cause undefined behavior.
 */
- (void)destroy;

/**
 * Register a ``NIOIOHandle`` for IO.
 *
 * - Parameter handle: The ``NIOIOHandle`` to register.
 *
 * - Returns: The registration object.
 */
- (ObjectiveCAnyObject<NIOIORegistration>)registerIOHandle:(ObjectiveCAnyObject<NIOIOHandle>)handle; /* TODO: throws Exception. */

/**
 * Wakeup the ``NIOIOHandler``, which means if any operation blocks it should be unblocked and return as soon as possible.
 */
- (void)wakeup;

/**
 * Returns ``CFramework/yes-macro`` if the given type is compatible with this ``NIOIOHandler`` and so can be registered, ``CFramework/no-macro`` otherwise.
 *
 * - Parameter class: The class of the ``NIOIOHandle``.
 *
 * - Returns: A Boolean value indicating whether the given type is compatible of not.
 */
- (CBoolean)isCompatibleWithClass:(Class)class;

@end

C_ASSUME_NONNULL_END

#endif
