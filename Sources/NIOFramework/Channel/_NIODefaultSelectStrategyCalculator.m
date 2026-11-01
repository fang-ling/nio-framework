/*===----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------===*
 *
 *  _NIODefaultSelectStrategyCalculator.m
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

#import "NIOFramework/Channel/_NIODefaultSelectStrategyCalculator.h"

C_ASSUME_NONNULL_BEGIN

@implementation _NIODefaultSelectStrategyCalculator

static _NIODefaultSelectStrategyCalculator* __sharedCalculator = nil;

+ (instancetype)sharedCalculator {
  return __sharedCalculator;
}

+ (void)initialize {
  __sharedCalculator = [[_NIODefaultSelectStrategyCalculator alloc] init];
}

- (NIOSelectStrategy)selectStrategyWithResult:(CInteger)result hasPendingTasks:(CBoolean)hasPendingTasks {
  return hasPendingTasks ? result : NIOSelectStrategySelect;
}

@end

C_ASSUME_NONNULL_END
