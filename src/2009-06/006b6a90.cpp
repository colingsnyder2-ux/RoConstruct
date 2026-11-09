// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 006164a0  unit: RBX::BoxSelectCommand  size: 148 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006164a0
//
// 006164a0  83ec24               sub esp, 0x24
// 006164a3  0fbf412c             movsx eax, word ptr [ecx + 0x2c]
// 006164a7  0fbf512a             movsx edx, word ptr [ecx + 0x2a]
// 006164ab  890424               mov dword ptr [esp], eax
// 006164ae  0fbf4128             movsx eax, word ptr [ecx + 0x28]
// 006164b2  db0424               fild dword ptr [esp]
// 006164b5  0fbf4926             movsx ecx, word ptr [ecx + 0x26]
// 006164b9  83ec10               sub esp, 0x10
// 006164bc  89542410             mov dword ptr [esp + 0x10], edx
// 006164c0  8d542424             lea edx, [esp + 0x24]
// 006164c4  d95c240c             fstp dword ptr [esp + 0xc]
// 006164c8  db442410             fild dword ptr [esp + 0x10]
// 006164cc  89442410             mov dword ptr [esp + 0x10], eax
// 006164d0  d95c2408             fstp dword ptr [esp + 8]
// 006164d4  db442410             fild dword ptr [esp + 0x10]
// 006164d8  894c2410             mov dword ptr [esp + 0x10], ecx
// 006164dc  d95c2404             fstp dword ptr [esp + 4]
// 006164e0  db442410             fild dword ptr [esp + 0x10]
// 006164e4  d91c24               fstp dword ptr [esp]
// 006164e7  52                   push edx
// 006164e8  e86354e4ff           call 0x45b950
// 006164ed  83c414               add esp, 0x14
// 006164f0  e82be5efff           call 0x514a20
// 006164f5  d900                 fld dword ptr [eax]
// 006164f7  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006164fb  d95c2404             fstp dword ptr [esp + 4]
// 006164ff  d94004               fld dword ptr [eax + 4]
// 00616502  8d542404             lea edx, [esp + 4]
// 00616506  d95c2408             fstp dword ptr [esp + 8]
// 0061650a  52                   push edx
// 0061650b  d94008               fld dword ptr [eax + 8]
// 0061650e  8b01                 mov eax, dword ptr [ecx]
// 00616510  8b4028               mov eax, dword ptr [eax + 0x28]
// 00616513  d95c2410             fstp dword ptr [esp + 0x10]
// 00616517  d9e8                 fld1 
// 00616519  51                   push ecx
// 0061651a  d95c2418             fstp dword ptr [esp + 0x18]
// 0061651e  8d54241c             lea edx, [esp + 0x1c]
// 00616522  d905ac9b8100         fld dword ptr [0x819bac]
// 00616528  d91c24               fstp dword ptr [esp]
// 0061652b  52                   push edx
// 0061652c  ffd0                 call eax
// 0061652e  83c424               add esp, 0x24
// 00616531  c20400               ret 4

struct Rect {
    float x0, y0, x1, y1;
    Rect(const Rect&);
};

struct Vector3 {
    float x, y, z;
};

struct Color {
    float r, g, b, a;
};

extern Rect __cdecl makeRect(float, float, float, float);
extern const Vector3& __cdecl getColor();
extern const float depth;

struct Renderer {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void draw(const Rect&, float, const Color&);
};

struct S {
    char padding[0x26];
    short x0, y0, x1, y1;
    void draw(Renderer*);
};

void S::draw(Renderer* renderer)
{
    Rect rect = makeRect((float)x0, (float)y0, (float)x1, (float)y1);
    const Vector3& rgb = getColor();
    Color color = { rgb.x, rgb.y, rgb.z, 1.0f };
    renderer->draw(rect, depth, color);
}
