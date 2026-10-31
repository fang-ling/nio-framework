/*===----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------===*
 *
 *  NIOSelectStrategyCalculatorProviding.h
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

#ifndef NIO_SELECT_STRATEGY_CALCULATOR_PROVIDING_H
#define NIO_SELECT_STRATEGY_CALCULATOR_PROVIDING_H

#include <NIOFramework/Channel/NIOSelectStrategyCalculating.h>

#import <CFramework/CFramework.h>
#import <ObjectiveCFramework/ObjectiveCFramework.h>

C_ASSUME_NONNULL_BEGIN

/**
 * An interface that creates a new object conforming to the ``NIOSelectStrategyCalculating`` protocol each time.
 */
@protocol NIOSelectStrategyCalculatorProviding <ObjectiveCObject>

/**
 * Returns the object capable of calculating the ``NIOSelectStrategy``.
 *
 * - Returns: The object capable of handling the ``NIOSelectStrategy``.
 */
- (ObjectiveCAnyObject<NIOSelectStrategyCalculating>)selectStrategyCalculator;

@end

C_ASSUME_NONNULL_END

#endif
