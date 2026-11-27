// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)
struct Vector2 { float x, y; Vector2() {} Vector2(float a,float b):x(a),y(b){} Vector2(const Vector2&o):x(o.x),y(o.y){} Vector2& operator=(const Vector2&o){x=o.x;y=o.y;return *this;} Vector2 operator+(const Vector2&o) const { return Vector2(x+o.x,y+o.y);} };
struct Rect2D { Vector2 min, max; Rect2D(){} static Rect2D xywh(const Vector2& a,const Vector2& s){ Rect2D r; r.min=a; r.max=a+s; return r; } };
struct Font {
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4();
    virtual Vector2 size();
};
struct sp_counted_base {
    long use_count_;
    long weak_count_;
    virtual ~sp_counted_base();
    virtual void dispose();
    virtual void destroy();
    void release() { if (_InterlockedDecrement(&use_count_) == 0) { dispose(); if (_InterlockedDecrement(&weak_count_) == 0) destroy(); } }
};
struct shared_count { sp_counted_base* pi_; ~shared_count() { if (pi_ != 0) pi_->release(); } };
struct FontPtr { Font* px; shared_count pn; };
struct AdornRbxGfx { Rect2D getBounds(FontPtr font); };
Rect2D AdornRbxGfx::getBounds(FontPtr font) { return Rect2D::xywh(Vector2(0,0), font.px->size()); }
