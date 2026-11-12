// from server: 96% by EspClaude
// roc-flags: /O2 /GS /EHsc /MD /fp:fast
// from server: 56% by colin
// roc 2007-08 005efb50  unit: RBX::P8Script::?$GetSetImpl  size: 299 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005efb50
//
// 005efb50  83ec48               sub esp, 0x48
// 005efb53  56                   push esi
// 005efb54  8b742450             mov esi, dword ptr [esp + 0x50]
// 005efb58  8b06                 mov eax, dword ptr [esi]
// 005efb5a  8b500c               mov edx, dword ptr [eax + 0xc]
// 005efb5d  57                   push edi
// 005efb5e  8bf9                 mov edi, ecx
// 005efb60  8d4c2420             lea ecx, [esp + 0x20]
// 005efb64  51                   push ecx
// 005efb65  8bce                 mov ecx, esi
// 005efb67  ffd2                 call edx
// 005efb69  d9442420             fld dword ptr [esp + 0x20]
// 005efb6d  d90570837a00         fld dword ptr [0x7a8370]
// 005efb73  8d442418             lea eax, [esp + 0x18]
// 005efb77  dcc1                 fadd st(1), st(0)
// 005efb79  50                   push eax
// 005efb7a  d9c9                 fxch st(1)
// 005efb7c  8d4c2414             lea ecx, [esp + 0x14]
// 005efb80  51                   push ecx
// 005efb81  d9542418             fst dword ptr [esp + 0x18]
// 005efb85  8d542448             lea edx, [esp + 0x48]
// 005efb89  d944242c             fld dword ptr [esp + 0x2c]
// 005efb8d  52                   push edx
// 005efb8e  d8c2                 fadd st(2)
// 005efb90  d9542420             fst dword ptr [esp + 0x20]
// 005efb94  d9442434             fld dword ptr [esp + 0x34]
// 005efb98  d90550707800         fld dword ptr [0x787050]
// 005efb9e  dcc9                 fmul st(1), st(0)
// 005efba0  d9c9                 fxch st(1)
// 005efba2  d8c4                 fadd st(4)
// 005efba4  d9542424             fst dword ptr [esp + 0x24]
// 005efba8  d9442438             fld dword ptr [esp + 0x38]
// 005efbac  deca                 fmulp st(2)
// 005efbae  d9c9                 fxch st(1)
// 005efbb0  dec4                 faddp st(4)
// 005efbb2  d9cb                 fxch st(3)
// 005efbb4  d9542428             fst dword ptr [esp + 0x28]
// 005efbb8  d9cb                 fxch st(3)
// 005efbba  dec2                 faddp st(2)
// 005efbbc  dec2                 faddp st(2)
// 005efbbe  d9059c7e7900         fld dword ptr [0x797e9c]
// 005efbc4  dcc9                 fmul st(1), st(0)
// 005efbc6  d9c9                 fxch st(1)
// 005efbc8  d95c2414             fstp dword ptr [esp + 0x14]
// 005efbcc  dcc9                 fmul st(1), st(0)
// 005efbce  d9c9                 fxch st(1)
// 005efbd0  d95c2418             fstp dword ptr [esp + 0x18]
// 005efbd4  d954243c             fst dword ptr [esp + 0x3c]
// 005efbd8  d9542440             fst dword ptr [esp + 0x40]
// 005efbdc  d9542444             fst dword ptr [esp + 0x44]
// 005efbe0  d95c2448             fstp dword ptr [esp + 0x48]
// 005efbe4  e89705efff           call 0x4e0180
// 005efbe9  8b06                 mov eax, dword ptr [esi]
// 005efbeb  8b4028               mov eax, dword ptr [eax + 0x28]
// 005efbee  83c40c               add esp, 0xc
// 005efbf1  8d4c2430             lea ecx, [esp + 0x30]
// 005efbf5  51                   push ecx
// 005efbf6  8d542444             lea edx, [esp + 0x44]
// 005efbfa  52                   push edx
// 005efbfb  8bce                 mov ecx, esi
// 005efbfd  ffd0                 call eax
// 005efbff  e88cb5f1ff           call 0x50b190
// 005efc04  d900                 fld dword ptr [eax]
// 005efc06  d95c2430             fstp dword ptr [esp + 0x30]
// 005efc0a  d94004               fld dword ptr [eax + 4]
// 005efc0d  d95c2434             fstp dword ptr [esp + 0x34]
// 005efc11  d94008               fld dword ptr [eax + 8]
// 005efc14  d95c2438             fstp dword ptr [esp + 0x38]
// 005efc18  d9e8                 fld1 
// 005efc1a  d95c243c             fstp dword ptr [esp + 0x3c]
// 005efc1e  e8ddb5f1ff           call 0x50b200
// 005efc23  d900                 fld dword ptr [eax]
// 005efc25  8b16                 mov edx, dword ptr [esi]
// 005efc27  d95c2440             fstp dword ptr [esp + 0x40]
// 005efc2b  d94004               fld dword ptr [eax + 4]
// 005efc2e  6a00                 push 0
// 005efc30  d95c2448             fstp dword ptr [esp + 0x48]
// 005efc34  6a02                 push 2
// 005efc36  d94008               fld dword ptr [eax + 8]
// 005efc39  d95c2450             fstp dword ptr [esp + 0x50]
// 005efc3d  d9e8                 fld1 
// 005efc3f  d95c2454             fstp dword ptr [esp + 0x54]
// 005efc43  dd0568fe7b00         fld qword ptr [0x7bfe68]
// 005efc49  8b5230               mov edx, dword ptr [edx + 0x30]
// 005efc4c  6a02                 push 2
// 005efc4e  8d44243c             lea eax, [esp + 0x3c]
// 005efc52  50                   push eax
// 005efc53  8d4c2450             lea ecx, [esp + 0x50]
// 005efc57  51                   push ecx
// 005efc58  83ec08               sub esp, 8
// 005efc5b  dd1c24               fstp qword ptr [esp]
// 005efc5e  8d442424             lea eax, [esp + 0x24]
// 005efc62  50                   push eax
// 005efc63  81c7f8000000         add edi, 0xf8
// 005efc69  57                   push edi
// 005efc6a  8d4c2434             lea ecx, [esp + 0x34]
// 005efc6e  51                   push ecx
// 005efc6f  8bce                 mov ecx, esi
// 005efc71  ffd2                 call edx

#include <string>

// Constants read from the exe: 0x7a8370 = 30.0f, 0x787050 = 0.25f,
// 0x797e9c = 0.5f, 0x7bfe68 = 14.0 (double).

struct Vector2 {
    float x, y;
    Vector2() {}
    Vector2(float x_, float y_) : x(x_), y(y_) {}
    Vector2 operator+(const Vector2& o) const { return Vector2(x + o.x, y + o.y); }
    Vector2 operator*(float s) const { return Vector2(x * s, y * s); }
};

struct Color3 {
    float r, g, b;
    static const Color3& white();   // 0x50b190
    static const Color3& black();   // 0x50b200
};

struct Color4 {
    float r, g, b, a;
    Color4(float r_, float g_, float b_, float a_) : r(r_), g(g_), b(b_), a(a_) {}
    Color4(const Color3& c, float a_ = 1.0f) : r(c.r), g(c.g), b(c.b), a(a_) {}
};

struct Rect2D {
    float x0, y0, x1, y1;           // 16 bytes: Color4 temp follows at +0x10
    static Rect2D xyxy(const Vector2& lo, const Vector2& hi);   // cdecl 0x4e0180
};

struct Adorn {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Rect2D getViewport() const;                                     // +0x0c
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void rect2d(const Rect2D& rect, const Color4& color);            // +0x28
    virtual void v11();
    virtual Vector2 drawFont2D(const std::string& s, const Vector2& pos, double size,
                               const Color4& color, const Color4& outline,
                               int xalign, int yalign, int spacing);        // +0x30
};

struct TextBox {
    char pad[0xf8];
    std::string text;               // this + 0xf8
    void render2d(Adorn* adorn);
};

void TextBox::render2d(Adorn* adorn)
{
    Vector2 center;
    {
        Rect2D vp = adorn->getViewport();
        Vector2 lo(vp.x0 + 30.0f, vp.y0 + 30.0f);
        Vector2 hi(vp.x1 * 0.25f + 30.0f, vp.y1 * 0.25f + 30.0f);
        Vector2 sum = lo + hi;
        center.x = sum.x * 0.5f;
        center.y = sum.y * 0.5f;
        Color4 grey(0.5f, 0.5f, 0.5f, 0.5f);
        Rect2D r = Rect2D::xyxy(lo, hi);
        adorn->rect2d(r, grey);
    }
    adorn->drawFont2D(text, center, 14.0, Color4(Color3::black()), Color4(Color3::white()), 2, 2, 0);
}
