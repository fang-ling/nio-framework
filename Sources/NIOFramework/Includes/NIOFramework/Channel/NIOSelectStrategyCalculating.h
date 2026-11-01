/*===----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------===*
 *
 *  NIOSelectStrategyCalculating.h
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

#ifndef NIO_SELECT_STRATEGY_CALCULATING_H
#define NIO_SELECT_STRATEGY_CALCULATING_H

#import <NIOFramework/Channel/NIOSelectStrategy.h>

#import <CFramework/CFramework.h>
#import <ObjectiveCFramework/ObjectiveCFramework.h>

C_ASSUME_NONNULL_BEGIN

/**
 * A general interface for objects that calculate select strategies.
 *
 * Objects implementing this protocol provide the ability to control the behavior of the select loop. For example a blocking select operation can be delayed or skipped entirely if there are events to
 * process immediately.
 */
@protocol NIOSelectStrategyCalculating <ObjectiveCObject>

/**
 * Returns the ``NIOSelectStrategy`` can be used to steer the outcome of a potential select call.
 *
 * - Parameters:
 *   - result: The result of the select operation.
 *   - hasPendingTasks: ``CFramework/yes-macro`` if tasks are waiting to be processed, otherwise, ``CFramework/no-macro``.
 *
 * - Returns: ``NIOSelectStrategy/NIOSelectStrategySelect`` if the next step should be blocking select, ``NIOSelectStrategy/NIOSelectStrategyContinue`` if the next step should be to not select but
 *   rather jump back to the IO loop and try again. Any value greater than or equal to `0` is treated as an indicator that work needs to be done.
 */
- (NIOSelectStrategy)selectStrategyWithResult:(CInteger)result hasPendingTasks:(CBoolean)hasPendingTasks;

@end

C_ASSUME_NONNULL_END

#endif
