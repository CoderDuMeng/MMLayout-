//
//  UIView+MM.h
//  MMCocoa
//
/* 
 杜蒙 iOS开发 
 Demo du 
 
 
*/



#import <UIKit/UIKit.h>

@interface UIView (MM)
- (void)setX:(CGFloat)x;
- (CGFloat)x;
- (void)setY:(CGFloat)y;
- (CGFloat)y;
- (void)setW:(CGFloat)w;
- (CGFloat)w;
- (void)setH:(CGFloat)h;
- (CGFloat)h;
- (CGFloat)maxY;
- (CGFloat)minY;
- (CGFloat)maxX;
- (CGFloat)minX;
- (CGFloat)halfW;
- (CGFloat)halfH;
- (CGFloat)halfX;
- (CGFloat)halfY;
@end
@interface MMLayout : NSObject
-(instancetype)initWithLayoutView:(UIView *)LayoutView;
@property (assign , nonatomic) CGFloat top;    //上
@property (assign , nonatomic) CGFloat bottom; //下
@property (assign , nonatomic) CGFloat left;   //左
@property (assign , nonatomic) CGFloat right;  //右
@property (assign , nonatomic) CGFloat width;  //右
@property (assign , nonatomic) CGFloat height;  //右
@property (assign , nonatomic) CGSize  size;

//距离父控件中心  //<<调用此方法钱必须先设置自己的宽高
- (void)center;

@end

@interface UIView (Layout)

//设置自己的Layout
- (void)make_Layout:(void(^)(MMLayout * layout))layout;




- (UIView *(^)(CGFloat top))top;
- (UIView *(^)(CGFloat bottom))bottom;
- (UIView *(^)(CGFloat left))left;
- (UIView *(^)(CGFloat right))right;
- (UIView *(^)(CGFloat width))width;
- (UIView *(^)(CGFloat height))height;
- (UIView *(^)(CGSize size))size;

@end




