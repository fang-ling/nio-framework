/*===----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------===*
 *
 *  NIOIOEvent.h
 *  nio-framework
 *
 *  Created by Fang Ling on 2026/11/1.
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

#ifndef NIO_IO_EVENT_H
#define NIO_IO_EVENT_H

#import <CFramework/CFramework.h>
#import <ObjectiveCFramework/ObjectiveCFramework.h>

C_ASSUME_NONNULL_BEGIN

/**
 * An IO event that is dispatched to an ``NIOIOHandle`` as a result of a previous submitted ``NIOIOOperations``.
 *
 * Concrete ``NIOIOHandle`` implementations support different concrete ``NIOIOEvent`` implementations.
 */
@protocol NIOIOEvent <ObjectiveCObject>

@end

C_ASSUME_NONNULL_END

#endif
