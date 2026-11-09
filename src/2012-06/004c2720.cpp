// from server: 85% by tajop
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Vector2 {
    float x;
    float y;
    Vector2() {}
};

struct Rect2D {
    float x0;
    float y0;
    float x1;
    float y1;
    Rect2D(const Vector2& s) : x0(0.0f), y0(0.0f), x1(s.x), y1(s.y) {}
};

struct Font {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual Vector2 size();
};

struct sp_counted_base {
    long use_count_;
    long weak_count_;
    virtual ~sp_counted_base();
    virtual void dispose();
    virtual void destroy();
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            if (_InterlockedDecrement(&weak_count_) == 0) {
                destroy();
            }
        }
    }
};

struct shared_count {
    sp_counted_base* pi_;
    ~shared_count() {
        if (pi_ != 0) {
            pi_->release();
        }
    }
};

struct FontPtr {
    Font* px;
    shared_count pn;
};

struct AdornRbxGfx {
    Rect2D getBounds(FontPtr font);
};

Rect2D AdornRbxGfx::getBounds(FontPtr font) {
    return Rect2D(font.px->size());
}
