/*===----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------===*
 *
 *  _NIODefaultSelectStrategyCalculator.h
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

#ifndef _NIO_DEFAULT_SELECT_STRATEGY_CALCULATOR_H
#define _NIO_DEFAULT_SELECT_STRATEGY_CALCULATOR_H

#import "NIOFramework/Channel/NIOSelectStrategy.h"
#import "NIOFramework/Channel/NIOSelectStrategyCalculating.h"

#import <CFramework/CFramework.h>
#import <ObjectiveCFramework/ObjectiveCFramework.h>

C_ASSUME_NONNULL_BEGIN

@interface _NIODefaultSelectStrategyCalculator: ObjectiveCObject <NIOSelectStrategyCalculating>

@property (class, nonatomic, strong, nonnull, readonly) _NIODefaultSelectStrategyCalculator* sharedCalculator;

+ (void)initialize;

- (NIOSelectStrategy)selectStrategyWithResult:(CInteger)result hasPendingTasks:(CBoolean)hasPendingTasks;

@end

C_ASSUME_NONNULL_END

#endif
