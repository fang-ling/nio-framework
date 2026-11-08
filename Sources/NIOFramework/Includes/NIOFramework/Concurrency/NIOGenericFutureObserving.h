/*===----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------===*
 *
 *  NIOGenericFutureObserving.h
 *  nio-framework
 *
 *  Created by Fang Ling on 2026/11/7.
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

#ifndef NIO_GENERIC_FUTURE_OBSERVING_H
#define NIO_GENERIC_FUTURE_OBSERVING_H

#import <CFramework/CFramework.h>
#import <FoundationFramework/FoundationFramework.h>
#import <ObjectiveCFramework/ObjectiveCFramework.h>

C_ASSUME_NONNULL_BEGIN

@protocol NIOFuture;

/**
 * An object that listens to the result of a ``NIOFuture``.
 *
 * The result of the asynchronous operation is notified once this listener is added by calling ``NIOFuture/addObserver:``.
 */
@protocol NIOGenericFutureObserving <ObjectiveCObject>

/**
 * Invoked when the operation associated with the ``NIOFuture`` has been completed.
 *
 * - Parameters:
 *   - future: The source ``NIOFuture`` which called this callback.
 *   - error: On output, a pointer to an error object that describes why the method failed, or ``ObjectiveCFramework/naught-macro`` if no error occurred. If you are not interested in the error
 *     information, pass ``ObjectiveCFramework/naught-macro`` for this parameter.
 */
- (void)future:(ObjectiveCAnyObject<NIOFuture>)future didCompleteOperationAndReturnError:(FoundationError**)error;

@end

C_ASSUME_NONNULL_END

#endif
