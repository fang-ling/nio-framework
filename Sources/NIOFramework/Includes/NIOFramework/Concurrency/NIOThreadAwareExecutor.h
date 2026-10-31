/*===----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------===*
 *
 *  NIOThreadAwareExecutor.h
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

#ifndef NIO_THREAD_AWARE_EXECUTOR_H
#define NIO_THREAD_AWARE_EXECUTOR_H

#import <CFramework/CFramework.h>
#import <FoundationFramework/FoundationFramework.h>
#import <ObjectiveCFramework/ObjectiveCFramework.h>

C_ASSUME_NONNULL_BEGIN

/**
 * An executor that is aware its execution thread.
 */
@protocol NIOThreadAwareExecutor <ObjectiveCObject>

/**
 * Returns ``CFramework/yes-macro`` if the given ``FoundationFramework/FoundationThread`` is used by this ``NIOThreadAwareExecutor`` to execute work.
 */
- (CBoolean)isExecutorThread:(FoundationThread*)thread;

@end

C_ASSUME_NONNULL_END

#endif
