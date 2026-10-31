// from server: 99% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0066f9c0  unit: RBX::AdornRbxGfx  size: 138 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0066f9c0
//
// 0066f9c0  83ec10               sub esp, 0x10
// 0066f9c3  8b442414             mov eax, dword ptr [esp + 0x14]
// 0066f9c7  d9400c               fld dword ptr [eax + 0xc]
// 0066f9ca  56                   push esi
// 0066f9cb  d95c2404             fstp dword ptr [esp + 4]
// 0066f9cf  8bf1                 mov esi, ecx
// 0066f9d1  d94008               fld dword ptr [eax + 8]
// 0066f9d4  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0066f9d8  8b16                 mov edx, dword ptr [esi]
// 0066f9da  d95c2408             fstp dword ptr [esp + 8]
// 0066f9de  d94004               fld dword ptr [eax + 4]
// 0066f9e1  57                   push edi
// 0066f9e2  d95c2410             fstp dword ptr [esp + 0x10]
// 0066f9e6  51                   push ecx
// 0066f9e7  d900                 fld dword ptr [eax]
// 0066f9e9  8b4604               mov eax, dword ptr [esi + 4]
// 0066f9ec  8b7814               mov edi, dword ptr [eax + 0x14]
// 0066f9ef  d95c2418             fstp dword ptr [esp + 0x18]
// 0066f9f3  8b4218               mov eax, dword ptr [edx + 0x18]
// 0066f9f6  8bce                 mov ecx, esi
// 0066f9f8  ffd0                 call eax
// 0066f9fa  8b16                 mov edx, dword ptr [esi]
// 0066f9fc  48                   dec eax
// 0066f9fd  89442420             mov dword ptr [esp + 0x20], eax
// 0066fa01  db442420             fild dword ptr [esp + 0x20]
// 0066fa05  8b4218               mov eax, dword ptr [edx + 0x18]
// 0066fa08  83ec08               sub esp, 8
// 0066fa0b  8bce                 mov ecx, esi
// 0066fa0d  d8642414             fsub dword ptr [esp + 0x14]
// 0066fa11  d95c2404             fstp dword ptr [esp + 4]
// 0066fa15  d9442418             fld dword ptr [esp + 0x18]
// 0066fa19  d91c24               fstp dword ptr [esp]
// 0066fa1c  ffd0                 call eax
// 0066fa1e  48                   dec eax
// 0066fa1f  89442428             mov dword ptr [esp + 0x28], eax
// 0066fa23  db442428             fild dword ptr [esp + 0x28]
// 0066fa27  83ec08               sub esp, 8
// 0066fa2a  8bcf                 mov ecx, edi
// 0066fa2c  d8642424             fsub dword ptr [esp + 0x24]
// 0066fa30  d95c2404             fstp dword ptr [esp + 4]
// 0066fa34  d9442428             fld dword ptr [esp + 0x28]
// 0066fa38  d91c24               fstp dword ptr [esp]
// 0066fa3b  6a02                 push 2
// 0066fa3d  e8be350100           call 0x683000
// 0066fa42  5f                   pop edi
// 0066fa43  5e                   pop esi
// 0066fa44  83c410               add esp, 0x10
// 0066fa47  c20c00               ret 0xc

#pragma float_control(precise, off)

struct Rect
{
    float x, y, z, w;
};

struct Renderer
{
    void draw(int mode, float x, float y, float z, float w, unsigned int color);
};

struct Context
{
    char padding[20];
    Renderer* renderer;
};

struct S
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual int height();

    Context* context;

    void draw(const Rect* rect, unsigned int unused, unsigned int color);
};

void S::draw(const Rect* rect, unsigned int unused, unsigned int color)
{
    float w = rect->w;
    float z = rect->z;
    float y = rect->y;
    float x = rect->x;
    Renderer* renderer = context->renderer;
    renderer->draw(2, x, (height() - 1) - y,
                   z, (height() - 1) - w, color);
}
