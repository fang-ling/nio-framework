/*===----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------===*
 *
 *  NIODefaultSelectStrategyCalculatorProvider.m
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

#import "NIOFramework/Channel/NIODefaultSelectStrategyCalculatorProvider.h"

#import "NIOFramework/Channel/_NIODefaultSelectStrategyCalculator.h"

C_ASSUME_NONNULL_BEGIN

@implementation NIODefaultSelectStrategyCalculatorProvider

static NIODefaultSelectStrategyCalculatorProvider* __sharedProvider = nil;

+ (instancetype)sharedProvider {
  return __sharedProvider;
}

+ (void)initialize {
  __sharedProvider = [[NIODefaultSelectStrategyCalculatorProvider alloc] init];
}

- (ObjectiveCAnyObject<NIOSelectStrategyCalculating>)selectStrategyCalculator {
  return _NIODefaultSelectStrategyCalculator.sharedCalculator;
}

@end

C_ASSUME_NONNULL_END
