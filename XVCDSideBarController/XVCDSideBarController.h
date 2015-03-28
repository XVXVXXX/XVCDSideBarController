//
//  XVCDSideBarController.h
//  XVCDSideBar
//
//  Created by xvxvxxx on 3/28/15.
//  Copyright (c) 2015 谢伟军. All rights reserved.
//  Based on CDSideBarController  --https://github.com/christophedellac/CDSideBarController

//
//  CDSideBarController.h
//  CDSideBar
//
//  Created by Christophe Dellac on 9/11/14.
//  Copyright (c) 2014 Christophe Dellac. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@protocol XVCDSideBarControllerDelegate <NSObject>

- (void)menuButtonClicked:(int)index;

@end

@interface XVCDSideBarController : NSObject
{
    UIView              *_backgroundMenuView;
    UIButton            *_menuButton;
    NSMutableArray      *_buttonList;
}


@property (nonatomic, retain) UIColor *menuColor;
@property (nonatomic) BOOL isOpen;
@property (nonatomic, weak) id<XVCDSideBarControllerDelegate> delegate;

+ (XVCDSideBarController *)sharedInstanceWithImages:(NSArray*)images;
+ (XVCDSideBarController *)sharedInstance;
- (XVCDSideBarController*)initWithImages:(NSArray*)buttonList;
- (void)insertMenuButtonOnView:(UIView*)view atPosition:(CGPoint)position;
- (void)dismissMenu;

@end



