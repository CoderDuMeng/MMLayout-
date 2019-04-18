//
//  UIView+MM.h
/*
 杜蒙 iOS开发
 annidy
*/

#define m_weakify(object) autoreleasepool   {} __weak  typeof(object) weak##object = object;
#define m_strongify(object) autoreleasepool {} __strong  typeof(weak##object) object = weak##object;

#import <UIKit/UIKit.h>
@class MMLayout;
@interface UIView (Layout)
@property (strong , nonatomic, readonly) MMLayout *mm_selfLayout;

@property (nonatomic) CGFloat mm_x;            ///<< frame.x
@property (nonatomic) CGFloat mm_y;            ///<< frame.y
@property (nonatomic) CGFloat mm_w;            ///<< frame.bounds.size.width
@property (nonatomic) CGFloat mm_h;            ///<< frame.bounds.size.height
@property (nonatomic) CGSize mm_size;          ///<< self.bounds.size

@property (readonly) CGFloat mm_centerX;      ///<< get self.center.x
@property (readonly) CGFloat mm_centerY;      ///<< get self.center.y
@property (readonly) CGFloat mm_maxY;         ///<< get CGRectGetMaxY
@property (readonly) CGFloat mm_minY;         ///<< get CGRectGetMinY
@property (readonly) CGFloat mm_maxX;         ///<< get CGRectGetMaxX
@property (readonly) CGFloat mm_minX;         ///<< get CGRectGetMinX
@property (readonly) CGFloat mm_halfW;        ///<< get self.width / 2
@property (readonly) CGFloat mm_halfH;        ///<< get self.height / 2
@property (readonly) CGFloat mm_halfX;        ///<< get self.x / 2
@property (readonly) CGFloat mm_halfY;        ///<< get self.y / 2

@property (readonly) CGFloat mm_halfCenterX;  ///<< get self.centerX / 2
@property (readonly) CGFloat mm_halfCenterY;  ///<< get self.centerY / 2

@property (readonly) UIView *mm_sibling;  //兄弟视图
@property (readonly) UIViewController *mm_viewController;  //self Responder UIViewControler

/*
   示例链接编程
   self.m_width(100).m_height(100).m_left(10).m_top(10)
*/
- (UIView * (^)(CGFloat top))m_top;            ///< set frame y
- (UIView * (^)(CGFloat right))m_flexToTop; ///< set frame y by change height
- (UIView * (^)(CGFloat bottom))m_bottom;      ///< 底部距离，必须先设置好height
- (UIView * (^)(CGFloat right))m_flexToBottom; ///< set frame y by change height
- (UIView * (^)(CGFloat left))m_left;          ///< set frame x
- (UIView * (^)(CGFloat left))m_flexToLeft;   ///< set frame right by chang width
- (UIView * (^)(CGFloat right))m_right;        ///< 右侧距离，必须先设置好width
- (UIView * (^)(CGFloat right))m_flexToRight;  ///< set frame right by chang width
- (UIView * (^)(CGFloat width))m_width;        ///< set frame width
- (UIView * (^)(CGFloat height))m_height;      ///< set frame height
- (UIView * (^)(CGSize  size))m_size;           ///< set frame size
- (UIView * (^)(CGPoint center))m__center;      ///< set frame point
- (UIView * (^)(CGFloat x))m__centerX;      ///< set frame point
- (UIView * (^)(CGFloat y))m__centerY;      ///< set frame point

/*
    相对父View
 */
- (UIView * (^)(void))m_center;                 ///< 居中  前提是有w h
- (UIView * (^)(void))m_centerY;                ///< Y居中  前提是有h
- (UIView * (^)(void))m_centerX;                ///< X居中  前提是有w
- (UIView * (^)(void))m_superWidth;             ///< 等宽
- (UIView * (^)(void))m_superHeight;            ///< 等高
- (UIView * (^)(void))m_superSize;              ///< 等Size

/*
    相对与其它View
 */
- (UIView * (^)(UIView *obj))m_equalToTop;     ///  equalTo top
- (UIView * (^)(UIView *obj))m_equalToBottom;  ///  equalTo Bottom
- (UIView * (^)(UIView *obj))m_equalToLeft;    ///  equalTo left
- (UIView * (^)(UIView *obj))m_equalToRight;   ///  equalTo right
- (UIView * (^)(UIView *obj))m_equalToWidth;   ///  equalTo width
- (UIView * (^)(UIView *obj))m_equalToHeight;  ///  equalTo height
- (UIView * (^)(UIView *obj))m_equalToSize;    ///  equalTo size
- (UIView * (^)(UIView *obj))m_equalToCenter;  ///  equalTo center
/*
    相对与兄弟节点，线性布局
 */
- (UIView * (^)(CGFloat space))m_hstack;                 ///< 水平，居中对齐
- (UIView * (^)(CGFloat space))m_vstack;                 ///< 垂直，居中对齐


- (UIView * (^)(void))m_sizeToFit;

@end




