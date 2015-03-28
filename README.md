# XVCDSideBarController

---

整个工程基于@[CDSideBarController](https://github.com/christophedellac/CDSideBarController) 主要修复了一些bug，设计为单例模式，以及美化了中间动画。本来应该pull request的，但是原主人好像很久不上线了。。。不merge我的，就索性自己开一个把。

###（最主要的还是CDSideBarController，我的只是修修补补，经供参考）

具体的使用工程应用可以看我的另外一个项目@[DoubanFM](https://github.com/XVXVXXX/DoubanFM)，主要就是用这个管理的。也可以看本项目的demo，或者下面CDSideBarController中的简介。
  
* 问题，因为 [sideBar insertMenuButtonOnView:self.view atPosition:CGPointMake(self.view.frame.size.width - 70, 50)];如果这个self.view是tableView的话，就会出现问题，因为他内部实现是

```
UITapGestureRecognizer *singleTap = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(dismissMenu)];
[view addGestureRecognizer:singleTap];
```

这样的话，```gesture.cancelsTouchesInView=YES```,表示当Gesture Recognizers识别到手势后，会向hit-test view发送 ```touchesCancelled:withEvent:消息来取消hit-test view对此触摸序列的处理,这样只有Gesture Recognizers能响应此触摸序列，hit-test view不再响应。```如果为NO,则不发送touchesCancelled:withEvent:消息给hit-test view,这样会使Gesture Recognizers和hit-test view同时响应触摸序列。所以

```
UITapGestureRecognizer *singleTap = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(dismissMenu)];
singleTap.cancelsTouchesInView = NO;
[view addGestureRecognizer:singleTap];
```

* 设计为单例模式（可以自己删掉就能改），通过```[XVCDSideBarController sharedInstance];```就可以得到单例实例，方便其他底层viewController获取信息。
* 美化动画，原来的动画设计有点问题，重弹出有一段往复了，加了一些代码

---

#CDSideBarController

===================

CDSideBarController is a light and easy side bar with custom iOS7 animations and actions

<strong>How does it work ?</strong>

1. Import CDSideBar/CDSideBarController in your project

2. .h file<br/>
  2.1 - #import "CDSideBarController.h" in the header file<br/>
  2.2 - Add <CDSideBarControllerDelegate> delegate<br/>
  2.3 - Add CDSideBarController *sideBar in your interface<br/>
  Should look like this: <br/>
      <strong>#import "CDSideBarController.h"</strong><br/>
  
  @interface ViewController : UIViewController <CDSideBarControllerDelegate><br/>
  {<br/>
      CDSideBarController *sideBar;<br/>
  }<br/>

3. .m file<br/>
  3.1 - In viewDidLoad, create a NSArray that contains your menu images<br/>
  3.2 - Create your instance of CDSideBarController with this array<br/>
  3.3 - Set self as a delegate to this instance<br/>
        Should look like this:<br/>
         NSArray *imageList = @[[UIImage imageNamed:@"menuChat.png"], [UIImage imageNamed:@"menuUsers.png"], [UIImage       imageNamed:@"menuMap.png"], [UIImage imageNamed:@"menuClose.png"]];
    sideBar = [[CDSideBarController alloc] initWithImages:imageList];<br/>
    sideBar.delegate = self;<br/>
  3.4 - Add the delegate method to be notified each time a menu button is clicked<br/>
      - (void)menuButtonClicked:(int)index<br/>
      {<br/>
          // Execute what ever you want<br/>
      }<br/>

  3.4 - Once you want the sidebar appear, just add :<br/>
         [sideBar insertMenuButtonOnView:self.view atPosition:CGPointMake(self.view.frame.size.width - 70, 50)];<br/>
        AtPosition correspond to the position where the show/hide menu button will be displayed<br/>

You're all set!<br/>