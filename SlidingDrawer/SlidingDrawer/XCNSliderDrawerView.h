//
//  XCNSliderDrawerView.h
//  SlidingDrawer
//
//  Created by 许春娜 on 2017/2/13.
//  Copyright © 2017年 XCN. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface XCNSliderDrawerView : NSObject
+(instancetype)shareSliderDrawerView;
-(void)showWithLetfViewControllers;

@end


@protocol ICSDrawerControllerChild;
@protocol ICSDrawerControllerPresenting;
@interface ICSDrawerController : UIViewController

/**
 这个控制器打开抽屉时出现。添加的时候初始化抽屉对象
 @see initWithLeftViewController:centerViewController:
 */
@property(nonatomic, strong, readonly) UIViewController<ICSDrawerControllerChild, ICSDrawerControllerPresenting> *leftViewController;
/**
 主要视图控制器
 在需要的时候,可以替换当前中心与另一个视图控制器,通过调用“replaceCenterViewControllerWithViewController:”
 @see replaceCenterViewControllerWithViewController:
 */
@property(nonatomic, strong, readonly) UIViewController<ICSDrawerControllerChild, ICSDrawerControllerPresenting> *centerViewController;



/**
 初始化并返回一个新分配的抽屉对象与给定的子控制器。
 */
- (id)initWithLeftViewController:(UIViewController<ICSDrawerControllerChild, ICSDrawerControllerPresenting> *)leftViewController
            centerViewController:(UIViewController<ICSDrawerControllerChild, ICSDrawerControllerPresenting> *)centerViewController;


/**
 打开抽屉
 */
- (void)open;


/**
 关闭抽屉
 */
- (void)close;
/**
 重新加载当前中心视图控制器,然后关闭抽屉
 @param reloadBlock The reload block
 */
- (void)reloadCenterViewControllerUsingBlock:(void (^)(void))reloadBlock;
/**
 替换当前的中心视图控制器与给定viewController的视图控制器，然后关闭抽屉
 */
- (void)replaceCenterViewControllerWithViewController:(UIViewController<ICSDrawerControllerChild, ICSDrawerControllerPresenting> *)viewController;

@end




@protocol ICSDrawerControllerChild <NSObject>

/**
 The drawer object for this child controller
 */
@property(nonatomic, weak) ICSDrawerController *drawer;

@end



/**
 The `ICSDrawerControllerPresenting` protocol is used by `ICSDrawerController` to communicate changes in the open/closed
 state of the drawer to its child controllers.
 
 As an example, you may want to implement these methods in your drawer's center view controller to be able to disable/enable
 the user interaction when the drawer is open/closed.
 */
@protocol  ICSDrawerControllerPresenting <NSObject>

@optional
/**
 告诉子控制器,控制器的抽屉是打开的
 
 @param drawerController The drawer object that is about to open.
 */
- (void)drawerControllerWillOpen:(ICSDrawerController *)drawerController;
/**
 告诉子控制器,控制器的抽屉已经完成打开,现在是开着的
 
 @param drawerController The drawer object that is now open.
 */
- (void)drawerControllerDidOpen:(ICSDrawerController *)drawerController;
/**
 告诉子控制器,控制器的抽屉即将关闭
 
 @param drawerController The drawer object that is about to close.
 */
- (void)drawerControllerWillClose:(ICSDrawerController *)drawerController;
/**
 告诉子控制器,控制器的抽屉已经完成最后阶段并且已关闭。
 
 @param drawerController The drawer object that is now closed.
 */
- (void)drawerControllerDidClose:(ICSDrawerController *)drawerController;

@end


@interface LeftTableViewController : UITableViewController<ICSDrawerControllerChild,ICSDrawerControllerPresenting>

@property(nonatomic,weak)ICSDrawerController *drawer;
-(id)initWithString:(NSArray *)name picture:(NSArray *)picArray;

@end





@interface ICSDropShadowView : UIView

@end
