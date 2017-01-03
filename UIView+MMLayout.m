

#import "UIView+MMLayout.h"
#import <objc/runtime.h>
@implementation UIView (MM)
#pragma mark - frame
- (void)setMm_x:(CGFloat)mm_x{
    CGRect frame = self.frame;
    frame.origin.x = mm_x;
    self.frame = frame;
}
- (CGFloat)mm_x{
    return self.frame.origin.x;
}
- (void)setMm_y:(CGFloat)mm_y{
    CGRect frame = self.frame;
    frame.origin.y = mm_y;
    self.frame = frame;
}
- (CGFloat)mm_y{
    return self.frame.origin.y;
}
- (void)setMm_w:(CGFloat)mm_w{
    CGRect frame = self.frame;
    frame.size.width = mm_w;
    self.frame = frame;
}
- (CGFloat)mm_w{
    return self.frame.size.width;
}
- (void)setMm_h:(CGFloat)mm_h{
    CGRect frame = self.frame;
    frame.size.height = mm_h;
    self.frame = frame;
    
}
- (CGFloat)mm_h{
    return self.frame.size.height;
}
-(CGFloat)mm_centerX{
    return self.center.x;
}
-(CGFloat)mm_centerY{
    return self.center.y;
}
- (CGFloat)mm_maxY{
    return CGRectGetMaxY(self.frame);
}
- (CGFloat)mm_minY{
    return CGRectGetMinY(self.frame);
}
- (CGFloat)mm_maxX{
    return CGRectGetMaxX(self.frame);
}
- (CGFloat)mm_minX{
    return CGRectGetMinX(self.frame);
}
- (CGFloat)mm_halfW{
    return self.mm_w / 2;
}
- (CGFloat)mm_halfH{
    return self.mm_h / 2;
}
- (CGFloat)mm_halfX{
    return self.mm_x / 2;
}
- (CGFloat)mm_halfY{
    return self.mm_y / 2;
}
-(CGFloat)mm_halfCenterX{
    return self.mm_centerX / 2;
}
-(CGFloat)mm_halfCenterY{
    return self.mm_centerY / 2;
}
-(void)setMm_size:(CGSize)mm_size{
    CGRect frame = self.frame;
    frame.size = mm_size;
    self.frame = frame;
}
-(CGSize)mm_size{
    return self.bounds.size;
}

@end
#pragma mark - MMLayout

@interface MMLayout()
@property (copy   , nonatomic) void(^updateChangeBlock)(CGRect frame);
@property (weak   , nonatomic) UIView *layoutView;
@end

@implementation MMLayout
-(instancetype)initWithLayoutView:(UIView *)LayoutView{
    if (self=[super init]) {
        self.layoutView = LayoutView;
    }
    return self;
}
-(void)setLeft:(CGFloat)left{
    _left = left;
    self.layoutView.mm_x = left;
    !self.updateChangeBlock ? : self.updateChangeBlock(self.layoutView.frame);
}
-(void)setTop:(CGFloat)top{
    _top = top;
    self.layoutView.mm_y = top;
    !self.updateChangeBlock ? : self.updateChangeBlock(self.layoutView.frame);
}
-(void)setRight:(CGFloat)right{
    _right = right;
    UIView *superview = self.layoutView.superview;
    self.layoutView.mm_x = superview.mm_w - self.layoutView.mm_w - right;
    !self.updateChangeBlock ? : self.updateChangeBlock(self.layoutView.frame);
}

-(void)setBottom:(CGFloat)bottom{
    _bottom = bottom;
    UIView *superview = self.layoutView.superview;
    self.layoutView.mm_y =  superview.mm_h - self.layoutView.mm_h - bottom;
    !self.updateChangeBlock ? : self.updateChangeBlock(self.layoutView.frame);
}

-(void)setHeight:(CGFloat)height{
    _height = height;
    self.layoutView.mm_h  = height;
    !self.updateChangeBlock ? : self.updateChangeBlock(self.layoutView.frame);
}
-(void)setWidth:(CGFloat)width{
    _width = width;
    self.layoutView.mm_w = width;
    !self.updateChangeBlock ? : self.updateChangeBlock(self.layoutView.frame);
}

-(void)setSize:(CGSize )size{
    self.layoutView.mm_size = size;
    !self.updateChangeBlock ? : self.updateChangeBlock(self.layoutView.frame);
    
}
-(CGSize)size{
    return self.layoutView.mm_size;
}

-(void)center{
    UIView *superview = self.layoutView.superview;
    self.layoutView.mm_x = superview.mm_halfW - self.layoutView.mm_halfW;
    self.layoutView.mm_y = superview.mm_halfH - self.layoutView.mm_halfH;
    !self.updateChangeBlock ? : self.updateChangeBlock(self.layoutView.frame);
    
}
@end
const void *_layoutKey;
@implementation UIView (Layout)

#pragma mark - set_ frame

-(void)make_LayoutUpdateChange:(void (^)(CGRect))block{
    [self mm_selfLayout].updateChangeBlock = block;
}

-(void)make_Layout:(void (^)(MMLayout *))layout{
    if (layout) {
        MMLayout *mm_Layout = [[MMLayout alloc] initWithLayoutView:self];
        layout(mm_Layout);
    }
}

- (MMLayout *)mm_selfLayout{
    MMLayout *layout = objc_getAssociatedObject(self, &_layoutKey);
    if (layout == nil) {
        layout = [[MMLayout alloc] initWithLayoutView:self];
        objc_setAssociatedObject(self, &_layoutKey, layout, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    }
    return layout;
}


-(UIView *(^)(CGFloat))m_top{
    @m_weakify(self);
    return ^(CGFloat m_top){
        @m_strongify(self);
        [self mm_selfLayout].top = m_top;
        return self;
    };
}
-(UIView *(^)(CGFloat))m_bottom{
    @m_weakify(self);
    return ^(CGFloat m_bottom){
        @m_strongify(self);
        [self mm_selfLayout].bottom = m_bottom;
        return self;
    };
}


-(UIView *(^)(CGFloat))m_left{
    @m_weakify(self);
    return ^(CGFloat m_left){
        @m_strongify(self);
        [self mm_selfLayout].left = m_left;
        return self;
    };
}


-(UIView *(^)(CGFloat))m_right{
    @m_weakify(self);
    return ^(CGFloat m_right){
        @m_strongify(self);
        [self mm_selfLayout].right = m_right;
        return self;
    };
}
-(UIView *(^)(CGFloat))m_width{
    @m_weakify(self);
    return ^(CGFloat m_width){
        @m_strongify(self);
        [self mm_selfLayout].width = m_width;
        return self;
    };
}
-(UIView *(^)(CGFloat))m_height{
    @m_weakify(self);
    return ^(CGFloat m_height){
        @m_strongify(self);
        [self mm_selfLayout].height = m_height;
        return self;
    };
}
-(UIView *(^)(CGSize))m_size{
    @m_weakify(self);
    return ^(CGSize m_size){
        @m_strongify(self);
        [self mm_selfLayout].size = m_size;
        return self;
    };
}
-(UIView *(^)())m_center{
    @m_weakify(self);
    return ^{
        @m_strongify(self);
        [[self mm_selfLayout] center];
        return self;
    };
}

#pragma mark -  m_equalTo
-(UIView *(^)(UIView *))m_equalToFrame{
    @m_weakify(self);
    return ^(UIView *obj){
        @m_strongify(self);
        self.frame = obj.frame;
        return self;
    };
}
-(UIView *(^)(UIView *))m_equalToTop{
    @m_weakify(self);
    return ^(UIView *obj){
        @m_strongify(self);
        self.mm_selfLayout.top = obj.mm_selfLayout.top;
        return self;
    };
    
}
-(UIView *(^)(UIView *))m_equalToBottom{
    @m_weakify(self);
    return ^(UIView *obj){
        @m_strongify(self);
        self.mm_selfLayout.bottom = obj.mm_selfLayout.bottom;
        return self;
    };
}
-(UIView *(^)(UIView *))m_equalToLeft{
    @m_weakify(self);
    return ^(UIView *obj){
        @m_strongify(self);
        self.mm_selfLayout.left = obj.mm_selfLayout.left;
        return self;
    };
    
}
-(UIView *(^)(UIView *))m_equalToRight{
    @m_weakify(self);
    return ^(UIView *obj){
        @m_strongify(self);
        self.mm_selfLayout.right = obj.mm_selfLayout.right;
        return self;
    };
    
}
-(UIView *(^)(UIView *))m_equalToWidth{
    @m_weakify(self);
    return ^(UIView *obj){
        @m_strongify(self);
        self.mm_selfLayout.width = obj.mm_selfLayout.width;
        return self;
    };
}

-(UIView *(^)(UIView *))m_equalToHeight{
    @m_weakify(self);
    return ^(UIView *obj){
        @m_strongify(self);
        self.mm_selfLayout.height = obj.mm_selfLayout.height;
        return self;
    };
}
-(UIView *(^)(UIView *))m_equalToSize{
    @m_weakify(self);
    return ^(UIView *obj){
        @m_strongify(self);
        [self mm_selfLayout].size = obj.mm_selfLayout.size;
        return self;
    };
    
}



@end



