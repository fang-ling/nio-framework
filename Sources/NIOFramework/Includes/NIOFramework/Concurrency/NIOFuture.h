/*===----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------===*
 *
 *  NIOFuture.h
 *  nio-framework
 *
 *  Created by Fang Ling on 2026/11/7.
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

#ifndef NIO_FUTURE_H
#define NIO_FUTURE_H

#import <CFramework/CFramework.h>
#import <FoundationFramework/FoundationFramework.h>
#import <ObjectiveCFramework/ObjectiveCFramework.h>

C_ASSUME_NONNULL_BEGIN

@protocol NIOGenericFutureObserving;

/**
 * The result of an asynchronous operation.
 */
@protocol NIOFuture <ObjectiveCObject>

/**
 * A Boolean value indicating whether the I/O operation is completed.
 *
 * Completion may be due to normal termination, an exception, or cancellation -- in all of these cases, this property is ``CFramework/yes-macro``.
 */
@property (nonatomic, assign, readonly, getter=isDone) CBoolean done;

/**
 * A Boolean value indicating whether the I/O operation is completed successfully.
 */
@property (nonatomic, assign, readonly, getter=isSuccess) CBoolean success;

/**
 * A Boolean value indicating whether the I/O operation was cancelled before it completed normally.
 */
@property (nonatomic, assign, readonly, getter=isCancelled) CBoolean cancelled;

/**
 * A Boolean value indicating whether the operation can be cancelled via ``cancelWithInterruptionAllowed:``.
 */
@property (nonatomic, assign, readonly, getter=isCancellable) CBoolean cancellable;

/**
 * The cause of the failed I/O operation if the I/O operation has failed.
 *
 * This property is ``ObjectiveCFramework/naught-macro`` if succeeded or this future is not completed yet.
 */
@property (nonatomic, strong, nullable, readonly) FoundationError* failureReason;

/**
 * Adds the specified listener to this future.
 *
 * The specified listener is notified when this future is done. If this future is already completed, the specified listener is notified immediately.
 *
 * - Parameter observer: The listener to be added.
 *
 * - Returns: `self`.
 */
- (ObjectiveCAnyObject<NIOFuture>)addObserver:(ObjectiveCAnyObject<NIOGenericFutureObserving>)observer;

/**
 * Adds the specified listeners to this future.
 *
 * The specified listeners are notified when this future is done. If this future is already completed, the specified listeners are notified immediately.
 *
 * Pass comma-separated list of trailing variadic arguments as additional listeners, ending with ``ObjectiveCFramework/naught-macro``.
 *
 * - Parameter firstObserver: The first listener to be added.
 *
 * - Returns: `self`.
 */
- (ObjectiveCAnyObject<NIOFuture>)addObservers:(ObjectiveCAnyObject<NIOGenericFutureObserving>)firstObserver, ...;

/**
 * Removes the first occurrence of the specified listener from this future.
 *
 * The specified listener is no longer notified when this future is done. If the specified listener is not associated with this future, this method does nothing and returns silently.
 *
 * - Parameter observer: The listener to be removed.
 *
 * - Returns: `self`.
 */
- (ObjectiveCAnyObject<NIOFuture>)removeObserver:(ObjectiveCAnyObject<NIOGenericFutureObserving>)observer;

/**
 * Removes the first occurrence for each of the listeners from this future.
 *
 * The specified listeners are no longer notified when this future is done. If the specified listeners are not associated with this future, this method does nothing and returns silently.
 *
 * Pass comma-separated list of trailing variadic arguments as additional listeners, ending with ``ObjectiveCFramework/naught-macro``.
 *
 * - Parameter firstObserver: The first listener to be removed.
 *
 * - Returns: `self`.
 */
- (ObjectiveCAnyObject<NIOFuture>)removeObservers:(ObjectiveCAnyObject<NIOGenericFutureObserving>)firstObserver, ...;

/**
 * Waits for this future until it is done, and re-throws the cause of the failure if this future failed.
 *
 * - Parameter error: On output, a pointer to an error object that describes why the method failed, or ``ObjectiveCFramework/naught-macro`` if no error occurred. If you are not interested in the error
 *   information, pass ``ObjectiveCFramework/naught-macro`` for this parameter.
 *
 * - Returns: `self`.
 */
- (ObjectiveCAnyObject<NIOFuture>)synchronizeAndReturnError:(FoundationError**)error;

/**
 * Waits for this future until it is done, and re-throws the cause of the failure if this future failed.
 */
- (ObjectiveCAnyObject<NIOFuture>)synchronizeUninterruptibly;

/**
 * Waits for this future to be completed.
 *
 * - Parameter error: On output, a pointer to an error object that describes why the method failed, or ``ObjectiveCFramework/naught-macro`` if no error occurred. If you are not interested in the error
 *   information, pass ``ObjectiveCFramework/naught-macro`` for this parameter.
 */
- (ObjectiveCAnyObject<NIOFuture>)awaitAndReturnError:(FoundationError**)error;

/**
 * Waits for this future to be completed without interruption.
 */
- (ObjectiveCAnyObject<NIOFuture>)awaitUninterruptibly;

/**
 * Waits for this future to be completed within the specified time limit.
 *
 * - Parameters:
 *   - duration: The time limit in seconds.
 *   - error: On output, a pointer to an error object that describes why the method failed, or ``ObjectiveCFramework/naught-macro`` if no error occurred. If you are not interested in the error
 *     information, pass ``ObjectiveCFramework/naught-macro`` for this parameter.
 *
 * - Returns: ``CFramework/yes-macro`` if and only if the future was completed within the specified time limit
 */
- (CBoolean)waitForDuration:(FoundationTimeInterval)duration error:(FoundationError**)error;

/**
 * Waits for this future to be completed within the specified time limit without interruption.
 *
 * - Parameter duration: The time limit in seconds.
 *
 * - Returns: ``CFramework/yes-macro`` if and only if the future was completed within the specified time limit
 */
- (CBoolean)waitUninterruptiblyForDuration:(FoundationTimeInterval)duration;

/**
 * Returns the result without blocking.
 *
 * If the future is not done yet this will return ``ObjectiveCFramework/naught-macro``.
 *
 * As it is possible that a ``ObjectiveCFramework/naught-macro`` value is used to mark the future as successful you also need to check if the future is really done with ``done`` and not rely on the
 * returned ``ObjectiveCFramework/naught-macro`` value.
 *
 * - Returns: The result without blocking.
 */
- (nullable ObjectiveCAnyObject)resultForNow;

/**
 * Attempts to cancel execution of this task.
 *
 * This attempt will fail if the task has already completed, has already been cancelled, or could not be cancelled for some other reason. If successful, and this task has not started when cancel is
 * called, this task should never run. If the task has already started, then the `allowInterruption` parameter determines whether the thread executing this task should be interrupted in an attempt to
 * stop the task.
 *
 * After this method returns, subsequent calls to ``done`` will always return ``CFramework/yes-macro``. Subsequent calls to ``cancelled`` will always return ``CFramework/yes-macro`` if this method
 * returned ``CFramework/yes-macro``.
 *
 * If the cancellation was successful it will fail the future.
 *
 * - Parameter allowInterruption: ``CFramework/yes-macro`` if the thread executing this task should be interrupted; otherwise, in-progress tasks are allowed to complete.
 *
 * - Returns: ``CFramework/no-macro`` if the task could not be cancelled, typically because it has already completed normally; ``CFramework/yes-macro`` otherwise.
 */
- (CBoolean)cancelWithInterruptionAllowed:(CBoolean)allowInterruption;

@end

C_ASSUME_NONNULL_END

#endif
