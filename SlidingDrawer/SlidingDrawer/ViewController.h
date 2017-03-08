//
//  ViewController.h
//  SlidingDrawer
//
//  Created by 许春娜 on 2017/2/13.
//  Copyright © 2017年 XCN. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "XCNSliderDrawerView.h"
@interface ViewController : UIViewController<ICSDrawerControllerPresenting,ICSDrawerControllerChild>

@property(nonatomic,weak)ICSDrawerController *drawer;

@end

