/*===----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------===*
 *
 *  NIOSelectStrategy.h
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

#ifndef NIO_SELECT_STRATEGY_H
#define NIO_SELECT_STRATEGY_H

#import <CFramework/CFramework.h>
#import <FoundationFramework/FoundationFramework.h>

C_ASSUME_NONNULL_BEGIN

/**
 * The options to use for customizing the behavior of the select loop.
 */
typedef FOUNDATION_ENUM(CInteger, NIOSelectStrategy) {
  /**
   * The blocking select should follow.
   */
  NIOSelectStrategySelect = -1,

  /**
   * The IO loop should be retried, no blocking select to follow directly.
   */
  NIOSelectStrategyContinue = -2,

  /**
   * The IO loop to poll for new events without blocking.
   */
  NIOSelectStrategyBusyWait = -3
};

C_ASSUME_NONNULL_END

#endif
