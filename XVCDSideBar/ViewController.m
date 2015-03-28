//
//  ViewController.m
//  XVCDSideBar
//
//  Created by xvxvxxx on 3/28/15.
//  Copyright (c) 2015 谢伟军. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.layer.contents = (id)[UIImage imageNamed:@"content"].CGImage;
    NSArray *imageList = @[[UIImage imageNamed:@"menuPlayer"],
                           [UIImage imageNamed:@"menuChannel"],
                           [UIImage imageNamed:@"menuLogin"],
                           [UIImage imageNamed:@"menuClose.png"]];
    
    self.sideBarController = [XVCDSideBarController sharedInstanceWithImages:imageList];
    self.sideBarController.delegate = self;

    // Do any additional setup after loading the view, typically from a nib.
}

-(void)viewWillAppear:(BOOL)animated{
    [super viewWillAppear:animated];
    [_sideBarController insertMenuButtonOnView:self.view atPosition:CGPointMake(self.view.frame.size.width - 50, 40)];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark -
#pragma mark - CDSideBarController delegate

- (void)menuButtonClicked:(int)index
{
    // Execute what ever you want
    NSLog(@"%d",index);
}
@end
