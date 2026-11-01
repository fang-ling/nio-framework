/*===----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------===*
 *
 *  NIOIOHandlerProviding.h
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

#ifndef NIO_IO_HANDLER_PROVIDING_H
#define NIO_IO_HANDLER_PROVIDING_H

#import <NIOFramework/Channel/NIOIOHandler.h>
#import <NIOFramework/Concurrency/NIOThreadAwareExecutor.h>

#import <CFramework/CFramework.h>
#import <ObjectiveCFramework/ObjectiveCFramework.h>

C_ASSUME_NONNULL_BEGIN

/**
 * The interface for providing ``NIOIOHandler`` instances.
 */
@protocol NIOIOHandlerProviding <ObjectiveCObject>

/**
 * ``CFramework/yes-macro`` if it's supported that the ``NIOThreadAwareExecutor`` might change its thread during the life-time of the ``NIOIOHandler`` that can be created via ``handlerForExecutor:``.
 *
 * That said even if changing the thread is supported it must be guaranteed that the access rules specified by ``NIOIOHandler`` are not violated.
 */
@property (nonatomic, assign, readonly, getter=isChangingThreadSupported) CBoolean changingThreadSupported;

/**
 * Creates a new ``NIOIOHandler`` instance.
 *
 * - Parameter ioExecutor: The ``NIOThreadAwareExecutor`` for the ``NIOIOHandler``.
 *
 * - Returns: A new ``NIOIOHandler`` instance.
 */
- (ObjectiveCAnyObject<NIOIOHandler>)handlerForExecutor:(ObjectiveCAnyObject<NIOThreadAwareExecutor>)ioExecutor;

@end

C_ASSUME_NONNULL_END

#endif
