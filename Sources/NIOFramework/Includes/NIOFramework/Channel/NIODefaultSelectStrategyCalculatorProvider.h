/*===----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------===*
 *
 *  NIODefaultSelectStrategyCalculatorProvider.h
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

#ifndef NIO_DEFAULT_SELECT_STRATEGY_CALCULATOR_PROVIDER_H
#define NIO_DEFAULT_SELECT_STRATEGY_CALCULATOR_PROVIDER_H

#include <NIOFramework/Channel/NIOSelectStrategyCalculatorProviding.h>

#import <CFramework/CFramework.h>
#import <ObjectiveCFramework/ObjectiveCFramework.h>

C_ASSUME_NONNULL_BEGIN

/**
 * The interface which provides the default select strategy calculator.
 */
@interface NIODefaultSelectStrategyCalculatorProvider: ObjectiveCObject <NIOSelectStrategyCalculatorProviding>

/**
 * The shared provider object.
 */
@property (class, nonatomic, strong, nonnull, readonly) NIODefaultSelectStrategyCalculatorProvider* sharedProvider;

+ (void)initialize;

- (ObjectiveCAnyObject<NIOSelectStrategyCalculating>)selectStrategyCalculator;

@end

C_ASSUME_NONNULL_END

#endif
