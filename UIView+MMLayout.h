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
- (void)setMm_x:(CGFloat)mm_x; ///<< set frame.x
- (CGFloat)mm_x;            ///<< get frame.x
- (void)setMm_y:(CGFloat)mm_y; ///<< set frame.y
- (CGFloat)mm_y;            ///<< get frame.y
- (void)setMm_w:(CGFloat)mm_w; ///<< set frame.bounds.size.width
- (CGFloat)mm_w;            ///<< get frame.bounds.size.width
- (void)setMm_h:(CGFloat)mm_h; ///<< set frame.bounds.size.height
- (CGFloat)mm_h;            ///<< get frame.bounds.size.height
- (CGFloat)mm_centerX;      ///<< get self.center.x
- (CGFloat)mm_centerY;      ///<< get self.center.y
- (CGFloat)mm_maxY;         ///<< get CGRectGetMaxY
- (CGFloat)mm_minY;         ///<< get CGRectGetMinY
- (CGFloat)mm_maxX;         ///<< get CGRectGetMaxX
- (CGFloat)mm_minX;         ///<< get CGRectGetMinX
- (CGFloat)mm_halfW;        ///<< get self.width / 2
- (CGFloat)mm_halfH;        ///<< get self.height / 2
- (CGFloat)mm_halfX;        ///<< get self.x / 2
- (CGFloat)mm_halfY;        ///<< get self.y / 2
- (CGFloat)mm_halfCenterX;  ///<< get self.centerX / 2
- (CGFloat)mm_halfCenterY;  ///<< get self.centerY / 2
- (void)setMm_size:(CGSize)mm_size; 
- (CGSize)mm_size;       ///<< get self.bounds.size


@end
@interface MMLayout : NSObject
/* 
  @LayoutView   传入进去  View
*/
-(instancetype)initWithLayoutView:(UIView *)LayoutView;
@property (assign , nonatomic) CGFloat top;    ///<<  frame y
@property (assign , nonatomic) CGFloat bottom; ///<<  y = super.h - LayoutView.h - bottom
@property (assign , nonatomic) CGFloat left;   ///<<  frame x
@property (assign , nonatomic) CGFloat right;  ///<<  x = super.w - LayoutView.h - right
@property (assign , nonatomic) CGFloat width;  ///<<  frame w
@property (assign , nonatomic) CGFloat height; ///<<  frame height
@property (assign , nonatomic) CGSize  size;   ///<<  frame bounds size  width height
- (void)center; ///<<调用此方法前必须先设置自己的宽高   (默认是居中父控件)
@end
@interface UIView (Layout)

@property (strong , nonatomic ,  readonly ) MMLayout *mm_selfLayout;

/*
 [self make_Layout:^(MMLayout *layout) {
 layout.width  = 100;
 layout.height = 200;
 layout.top = 10;
 layout.right = 10;
 
 }];
*/
- (void)make_Layout:(void(^)(MMLayout * layout))layout;
/*
  当frmae 将要属性发生变化的时候会调用此方法
*/
- (void)make_LayoutUpdateChange:(void(^)(CGRect frame))block;
/*
   示例链接编程
 
   self.width(100).height(100).left(10).top(10)
 
*/
- (UIView * (^)(CGFloat top))m_top;            ///< set frame y
- (UIView * (^)(CGFloat bottom))m_bottom;      ///< set frame y
- (UIView * (^)(CGFloat left))m_left;          ///< set frame x
- (UIView * (^)(CGFloat right))m_right;        ///< set frame x
- (UIView * (^)(CGFloat width))m_width;        ///< set frame width
- (UIView * (^)(CGFloat height))m_height;      ///< set frame height
- (UIView * (^)(CGSize size))m_size;           ///< set frame size
- (UIView * (^)())m_center;                    ///< set frame center  前提是有w h 调用次方法居中父类



- (UIView * (^)(UIView *obj))m_equalToFrame;   /// frame
- (UIView * (^)(UIView *obj))m_equalToTop;     /// top
- (UIView * (^)(UIView *obj))m_equalToBottom;  /// Bottom
- (UIView * (^)(UIView *obj))m_equalToLeft;    /// left
- (UIView * (^)(UIView *obj))m_equalToRight;   /// right
- (UIView * (^)(UIView *obj))m_equalToWidth;   /// width
- (UIView * (^)(UIView *obj))m_equalToHeight;  /// height
- (UIView * (^)(UIView *obj))m_equalToSize;    /// size


@end




