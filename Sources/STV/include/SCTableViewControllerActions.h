/*
 *  SCTableViewControllerActions.h
 *  Sensible TableView
 *
 *  Copyright 2011-2015 Sensible Cocoa. All rights reserved.
 *
 *
 */

#import <Foundation/Foundation.h>

@class SCTableViewController;

typedef void(^SCTableViewControllerAction_Block)(SCTableViewController *viewController);
typedef BOOL(^SCTableViewControllerButtonTappedAction_Block)(SCTableViewController *viewController);


/****************************************************************************************/
/*	class SCTableViewControllerActions	*/
/****************************************************************************************/ 
/**	This class hosts a set of view controller action blocks. Once an action is set to a desired code block, it will execute the block as soon as the action occurs.
 
 SCTableViewControllerAction_Block syntax:
    action = ^(SCTableViewController *viewController)
    {
        // Your code here
    };
 */
@interface SCTableViewControllerActions : NSObject

/** Action gets called when the view controller's view has been loaded. */
@property (nonatomic, copy) SCTableViewControllerAction_Block viewDidLoad;

/** Action gets called when the view controller is about to appear. */
@property (nonatomic, copy) SCTableViewControllerAction_Block willAppear;

/** Action gets called when the view controller has appeared. */
@property (nonatomic, copy) SCTableViewControllerAction_Block didAppear;

/** Action gets called when the view controller is about to disappear. */
@property (nonatomic, copy) SCTableViewControllerAction_Block willDisappear;

/** Action gets called when the view controller has disappeared. */
@property (nonatomic, copy) SCTableViewControllerAction_Block didDisappear;

/** Action gets called when the view controller is about to appear for the first time. */
@property (nonatomic, copy) SCTableViewControllerAction_Block willPresent;

/** Action gets called when the view controller has appeared for the first time. */
@property (nonatomic, copy) SCTableViewControllerAction_Block didPresent;

/** Action gets called when the view controller is about to be dismissed. */
@property (nonatomic, copy) SCTableViewControllerAction_Block willDismiss;

/** Action gets called when the view controller has been dismissed. */
@property (nonatomic, copy) SCTableViewControllerAction_Block didDismiss;

/** Action gets called when the view controller's Cancel button has been tapped. Return FALSE to ignore the tap, otherwise return TRUE.
 
 Example:
    action = ^BOOL(SCTableViewController *)viewController
    {
        // your code here
 
        return TRUE;    // accept the tap
    }
 */
@property (nonatomic, copy) SCTableViewControllerButtonTappedAction_Block cancelButtonTapped;

/** Action gets called when the view controller's Done button has been tapped. Return FALSE to ignore the tap, otherwise return TRUE.
 
 Example:
    action = ^BOOL(SCTableViewController *)viewController
    {
        // your code here
 
        return TRUE;    // accept the tap
    }
 */
@property (nonatomic, copy) SCTableViewControllerButtonTappedAction_Block doneButtonTapped;

/** Action gets called when the view controller's Edit button has been tapped. Return FALSE to ignore the tap, otherwise return TRUE.
 
 Example:
    action = ^BOOL(SCTableViewController *)viewController
    {
        // your code here
 
        return TRUE;    // accept the tap
    }
 */
@property (nonatomic, copy) SCTableViewControllerButtonTappedAction_Block editButtonTapped;

@end
