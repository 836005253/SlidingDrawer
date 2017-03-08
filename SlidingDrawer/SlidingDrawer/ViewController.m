//
//  ViewController.m
//  SlidingDrawer
//
//  Created by 许春娜 on 2017/2/13.
//  Copyright © 2017年 XCN. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()
@property(nonatomic, strong) UIButton *openDrawerButton;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    UIImage *hamburger = [UIImage imageNamed:@"2531170_132113676001_2.jpg"];
    //    NSParameterAssert(hamburger);
    self.openDrawerButton = [UIButton buttonWithType:UIButtonTypeCustom];
    self.openDrawerButton.frame = CGRectMake(10.0f, 20.0f, 30.0f, 30.0f);
    [self.openDrawerButton setImage:hamburger forState:UIControlStateNormal];
    [self.openDrawerButton addTarget:self action:@selector(openDrawer:) forControlEvents:UIControlEventTouchUpInside];
    self.openDrawerButton.backgroundColor = [UIColor redColor];
    self.openDrawerButton.layer.cornerRadius = 15.0f;
    self.openDrawerButton.clipsToBounds = YES;
//    UIBarButtonItem *item = [[UIBarButtonItem alloc]initWithCustomView:self.openDrawerButton];
//    self.navigationItem.leftBarButtonItem = item;
    [self.view addSubview:self.openDrawerButton];
    // Do any additional setup after loading the view, typically from a nib.
}
#pragma mark - Configuring the view’s layout behavior

- (BOOL)prefersStatusBarHidden
{
    return NO;
}

- (UIStatusBarStyle)preferredStatusBarStyle
{
    return UIStatusBarStyleLightContent;
}

#pragma mark - ICSDrawerControllerPresenting

- (void)drawerControllerWillOpen:(ICSDrawerController *)drawerController
{
    self.view.userInteractionEnabled = NO;
}

- (void)drawerControllerDidClose:(ICSDrawerController *)drawerController
{
    self.view.userInteractionEnabled = YES;
}

#pragma mark - Open drawer button

- (void)openDrawer:(id)sender
{
    [self.drawer open];
    NSLog(@"11111");
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
