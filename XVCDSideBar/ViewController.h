//
//  ViewController.h
//  XVCDSideBar
//
//  Created by xvxvxxx on 3/28/15.
//  Copyright (c) 2015 谢伟军. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "XVCDSideBarController.h"
@interface ViewController : UIViewController <XVCDSideBarControllerDelegate>

@property (nonatomic, strong) XVCDSideBarController *sideBarController;

@end

