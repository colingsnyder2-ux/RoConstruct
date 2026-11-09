// from server: 100% by colin
// from server: 95% by king_originala
// roc 2008-06 005cf770  unit: RBX::P8HopperBin::?$SetImpl  size: 236 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005cf770
//
// 005cf770  6aff                 push -1
// 005cf772  68d8557d00           push 0x7d55d8
// 005cf777  64a100000000         mov eax, dword ptr fs:[0]
// 005cf77d  50                   push eax
// 005cf77e  64892500000000       mov dword ptr fs:[0], esp
// 005cf785  83ec24               sub esp, 0x24
// 005cf788  56                   push esi
// 005cf789  8bf1                 mov esi, ecx
// 005cf78b  89742404             mov dword ptr [esp + 4], esi
// 005cf78f  e83cffffff           call 0x5cf6d0
// 005cf794  33c0                 xor eax, eax
// 005cf796  33c9                 xor ecx, ecx
// 005cf798  33d2                 xor edx, edx
// 005cf79a  c7061cab8300         mov dword ptr [esi], 0x83ab1c
// 005cf7a0  c7461010ab8300       mov dword ptr [esi + 0x10], 0x83ab10
// 005cf7a7  c7461408ab8300       mov dword ptr [esi + 0x14], 0x83ab08
// 005cf7ae  c7462000ab8300       mov dword ptr [esi + 0x20], 0x83ab00
// 005cf7b5  c74624f0aa8300       mov dword ptr [esi + 0x24], 0x83aaf0
// 005cf7bc  c74644e0aa8300       mov dword ptr [esi + 0x44], 0x83aae0
// 005cf7c3  c74664d0aa8300       mov dword ptr [esi + 0x64], 0x83aad0
// 005cf7ca  c78684000000c0aa8300 mov dword ptr [esi + 0x84], 0x83aac0
// 005cf7d4  c786a4000000b0aa8300 mov dword ptr [esi + 0xa4], 0x83aab0
// 005cf7de  c786c4000000a0aa8300 mov dword ptr [esi + 0xc4], 0x83aaa0
// 005cf7e8  c7863001000098aa8300 mov dword ptr [esi + 0x130], 0x83aa98
// 005cf7f2  89442430             mov dword ptr [esp + 0x30], eax
// 005cf7f6  66898e64010000       mov word ptr [esi + 0x164], cx
// 005cf7fd  66899666010000       mov word ptr [esi + 0x166], dx
// 005cf804  c744240802000000     mov dword ptr [esp + 8], 2
// 005cf80c  8944240c             mov dword ptr [esp + 0xc], eax
// 005cf810  66894c2410           mov word ptr [esp + 0x10], cx
// 005cf815  6689542412           mov word ptr [esp + 0x12], dx
// 005cf81a  89442414             mov dword ptr [esp + 0x14], eax
// 005cf81e  e8edb61e00           call 0x7baf10
// 005cf823  d900                 fld dword ptr [eax]
// 005cf825  d95c2418             fstp dword ptr [esp + 0x18]
// 005cf829  8bce                 mov ecx, esi
// 005cf82b  d94004               fld dword ptr [eax + 4]
// 005cf82e  d95c241c             fstp dword ptr [esp + 0x1c]
// 005cf832  d94008               fld dword ptr [eax + 8]
// 005cf835  d95c2420             fstp dword ptr [esp + 0x20]
// 005cf839  d9400c               fld dword ptr [eax + 0xc]
// 005cf83c  8d442408             lea eax, [esp + 8]
// 005cf840  50                   push eax
// 005cf841  d95c2428             fstp dword ptr [esp + 0x28]
// 005cf845  e8363cfaff           call 0x573480
// 005cf84a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005cf84e  8bc6                 mov eax, esi
// 005cf850  5e                   pop esi
// 005cf851  64890d00000000       mov dword ptr fs:[0], ecx
// 005cf858  83c430               add esp, 0x30
// 005cf85b  c3                   ret 

struct Color
{
    float x, y, z, w;
};

extern const Color& __cdecl defaultColor();

struct Value
{
    int kind;
    int flags;
    unsigned short first;
    unsigned short second;
    int reserved;
    Color color;
};

struct A0
{
    virtual void f0();
    unsigned long padding[3];
};

struct A1
{
    virtual void f1();
};

struct A2
{
    virtual void f2();
    unsigned long padding[2];
};

struct A3
{
    virtual void f3();
};

struct A4
{
    virtual void f4();
    unsigned long padding[7];
};

struct A5
{
    virtual void f5();
    unsigned long padding[7];
};

struct A6
{
    virtual void f6();
    unsigned long padding[7];
};

struct A7
{
    virtual void f7();
    unsigned long padding[7];
};

struct A8
{
    virtual void f8();
    unsigned long padding[7];
};

struct A9
{
    virtual void f9();
    unsigned long padding[26];
};

struct A10
{
    virtual void f10();
    unsigned long padding[12];
};

struct Base : A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10
{
    Base();
    ~Base();
    void setValue(const Value&);
};

struct Pair { unsigned short first, second; Pair() : first(0), second(0) {} };

struct S : Base
{
    Pair pair;

    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();

    S();
};

S::S()
{

    Value value;
    value.kind = 2;
    value.flags = 0;
    value.first = 0;
    value.second = 0;
    value.reserved = 0;

    const Color& color = defaultColor();
    value.color.x = color.x;
    value.color.y = color.y;
    value.color.z = color.z;
    value.color.w = color.w;

    setValue(value);
}
