/*===----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------===*
 *
 *  NIOIORegistration.h
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

#ifndef NIO_IO_REGISTRATION_H
#define NIO_IO_REGISTRATION_H

#import <NIOFramework/Channel/NIOIOOperations.h>

#import <CFramework/CFramework.h>
#import <ObjectiveCFramework/ObjectiveCFramework.h>

C_ASSUME_NONNULL_BEGIN

/**
 * A registration for IO.
 */
@protocol NIOIORegistration <ObjectiveCObject>

/**
 * Implementation-specific attachment, optional.
 */
@property (nonatomic, strong, nullable, readonly) ObjectiveCAnyObject attachment;

/**
 * ``CFramework/yes-macro`` if the registration is still valid. Once ``cancelRegistration`` is called this will become ``CFramework/no-macro``.
 */
@property (nonatomic, assign, readonly, getter=isValid) CBoolean valid;

/**
 * Submits the ``NIOIOOperations`` to the registration.
 *
 * - Parameter operations: The operations.
 *
 * - Returns: An identifier for the operation, which might be unique or not (depending on the implementation).
 */
- (CInteger64)submitIOOperations:(ObjectiveCAnyObject<NIOIOOperations>)operations;

/**
 * Cancels the registration.
 *
 * - Returns: ``CFramework/yes-macro`` if cancellation was successful, ``CFramework/no-macro`` otherwise.
 */
- (CBoolean)cancelRegistration;

@end

C_ASSUME_NONNULL_END

#endif
