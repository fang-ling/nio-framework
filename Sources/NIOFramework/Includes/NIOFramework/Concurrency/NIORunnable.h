/*===----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------===*
 *
 *  NIORunnable.h
 *  nio-framework
 *
 *  Created by Fang Ling on 2026/11/14.
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

#ifndef NIO_RUNNABLE_H
#define NIO_RUNNABLE_H

#import <CFramework/CFramework.h>
#import <ObjectiveCFramework/ObjectiveCFramework.h>

C_ASSUME_NONNULL_BEGIN

/**
 * A type that is intended to be executed by a thread.
 *
 * This interface is designed to provide a common protocol for objects that wish to execute code while they are active.
 */
@protocol NIORunnable <ObjectiveCObject>

/**
 * Starts the execution.
 */
- (void)run;

@end

C_ASSUME_NONNULL_END

#endif
