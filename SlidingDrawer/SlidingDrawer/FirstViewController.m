//
//  FirstViewController.m
//  SlidingDrawer
//
//  Created by 许春娜 on 2017/3/6.
//  Copyright © 2017年 XCN. All rights reserved.
//

#import "FirstViewController.h"
#import "XCNSliderDrawerView.h"
@interface FirstViewController ()

@end

@implementation FirstViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor cyanColor];
    [self createLeftItem];
    // Do any additional setup after loading the view.
}

-(void)createLeftItem
{
    UIButton *button = [UIButton buttonWithType:(UIButtonTypeCustom)];
    button.backgroundColor = [UIColor redColor];
    [button addTarget:self action:@selector(buttonClick:) forControlEvents:(UIControlEventTouchUpInside)];
    UIBarButtonItem *item = [[UIBarButtonItem alloc]initWithCustomView:button];
    self.navigationItem.leftBarButtonItem = item;
}


-(void)buttonClick:(UIButton *)sender
{
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
