# MMLayout 
 - 简单的Frame 设置封装 支持链接方式编程 

###实例 
  ```objc 
    
   1.初始化一个View 使用block 块设置frame
   UIView *newView = [UIView new];
   [self.view addSubview:newView];  
   [newView make_Layout:^(MMLayout *layout) {
    layout.width = 100;
    layout.height= 200;
    layout.left = 200;
    layout.top  = 10;
    }];

  ``` 
 给View发送一个make_Layout block传入进去一个MMLayout 对象 设置相关值 



###链接方式编写 
  ```objc 
   
UIView *newView = [UIView new];
[self.view addSubview:newView];  
newView.height(50).width(100).right(10).top(10);

  ```

 以上就是简单的使用方式 链接方式 和block的方式
 其实使用frame还是可以在写代码过程中避免`aotoLayout`很多的问题,在一个`frame`的效率要同比高出很多
 这样写的方式简化了很多,也方便阅读了很多 



