/*===----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------===*
 *
 *  NIOIOOperations.h
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

#ifndef NIO_IO_OPERATIONS_H
#define NIO_IO_OPERATIONS_H

#import <CFramework/CFramework.h>
#import <ObjectiveCFramework/ObjectiveCFramework.h>

C_ASSUME_NONNULL_BEGIN

/**
 * An IO operation that can be submitted to an ``NIOIORegistration`` via ``NIOIORegistration/submitIOOperations:``.
 *
 * Concrete ``NIOIORegistration`` implementations support different concrete ``NIOIOOperations`` implementations and will so also "produce" concrete ``NIOIOEvent``s.
 */
@protocol NIOIOOperations <ObjectiveCObject>

@end

C_ASSUME_NONNULL_END

#endif
