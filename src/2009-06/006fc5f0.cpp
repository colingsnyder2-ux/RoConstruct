// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0066fa50  unit: RBX::AdornRbxGfx  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0066fa50
//
// 0066fa50  56                   push esi
// 0066fa51  8bf1                 mov esi, ecx
// 0066fa53  8b4604               mov eax, dword ptr [esi + 4]
// 0066fa56  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0066fa5a  8b16                 mov edx, dword ptr [esi]
// 0066fa5c  57                   push edi
// 0066fa5d  8b7814               mov edi, dword ptr [eax + 0x14]
// 0066fa60  8b4218               mov eax, dword ptr [edx + 0x18]
// 0066fa63  51                   push ecx
// 0066fa64  8bce                 mov ecx, esi
// 0066fa66  ffd0                 call eax
// 0066fa68  8b16                 mov edx, dword ptr [esi]
// 0066fa6a  48                   dec eax
// 0066fa6b  89442418             mov dword ptr [esp + 0x18], eax
// 0066fa6f  db442418             fild dword ptr [esp + 0x18]
// 0066fa73  8b442414             mov eax, dword ptr [esp + 0x14]
// 0066fa77  83ec08               sub esp, 8
// 0066fa7a  8bce                 mov ecx, esi
// 0066fa7c  d86004               fsub dword ptr [eax + 4]
// 0066fa7f  d95c2404             fstp dword ptr [esp + 4]
// 0066fa83  d900                 fld dword ptr [eax]
// 0066fa85  8b4218               mov eax, dword ptr [edx + 0x18]
// 0066fa88  d91c24               fstp dword ptr [esp]
// 0066fa8b  ffd0                 call eax
// 0066fa8d  48                   dec eax
// 0066fa8e  89442420             mov dword ptr [esp + 0x20], eax
// 0066fa92  db442420             fild dword ptr [esp + 0x20]
// 0066fa96  8b442418             mov eax, dword ptr [esp + 0x18]
// 0066fa9a  83ec08               sub esp, 8
// 0066fa9d  8bcf                 mov ecx, edi
// 0066fa9f  d86004               fsub dword ptr [eax + 4]
// 0066faa2  d95c2404             fstp dword ptr [esp + 4]
// 0066faa6  d900                 fld dword ptr [eax]
// 0066faa8  d91c24               fstp dword ptr [esp]
// 0066faab  e800360100           call 0x6830b0
// 0066fab0  5f                   pop edi
// 0066fab1  5e                   pop esi
// 0066fab2  c20c00               ret 0xc

struct Vec2 {
    float x, y;
};

struct Renderer {
    void draw(float ax, float ay, float bx, float by, unsigned color);
};

struct Context {
    char padding[48];
    Renderer* renderer;
};

struct Adorn {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual int height();

    Context* context;
    void draw(const Vec2& a, const Vec2& b, unsigned color);
};

#pragma float_control(precise, off, push)

void Adorn::draw(const Vec2& a, const Vec2& b, unsigned color)
{
    Renderer* renderer = context->renderer;
    renderer->draw(a.x, float(height() - 1) - a.y,
                   b.x, float(height() - 1) - b.y, color);
}

#pragma float_control(pop)
