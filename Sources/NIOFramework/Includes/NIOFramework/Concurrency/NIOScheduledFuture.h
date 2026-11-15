/*===----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------===*
 *
 *  NIOScheduledFuture.h
 *  nio-framework
 *
 *  Created by Fang Ling on 2026/11/8.
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

#ifndef NIO_SCHEDULED_FUTURE_H
#define NIO_SCHEDULED_FUTURE_H

#import <NIOFramework/Concurrency/NIOFuture.h>

#import <CFramework/CFramework.h>

C_ASSUME_NONNULL_BEGIN

/**
 * The result of a scheduled asynchronous operation.
 */
@protocol NIOScheduledFuture <NIOFuture>

@end

C_ASSUME_NONNULL_END

#endif
