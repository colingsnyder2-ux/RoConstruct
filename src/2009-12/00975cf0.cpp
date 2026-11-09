// from server: 100% by nuck16
// roc 2009-12 00975cf0  unit: seg_00970000  size: 57 bytes
//
// 00975cf0  56                   push esi
// 00975cf1  33f6                 xor esi, esi
// 00975cf3  56                   push esi
// 00975cf4  6a0f                 push 0xf
// 00975cf6  33c9                 xor ecx, ecx
// 00975cf8  51                   push ecx
// 00975cf9  b840fe6d00           mov eax, 0x6dfe40
// 00975cfe  50                   push eax
// 00975cff  56                   push esi
// 00975d00  baa08a5200           mov edx, 0x528aa0
// 00975d05  52                   push edx
// 00975d06  6884b09b00           push 0x9bb084
// 00975d0b  68f8a49d00           push 0x9da4f8
// 00975d10  b90c34b900           mov ecx, 0xb9340c
// 00975d15  e866a2d6ff           call 0x6dff80
// 00975d1a  6870649800           push 0x986470
// 00975d1f  e805ece7ff           call 0x7f4929
// 00975d24  83c404               add esp, 4
// 00975d27  5e                   pop esi
// 00975d28  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
    void m1();
};


struct Desc
{
    Desc(const char *, const char *, void (Owner::*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("MeshType", "Data", &Owner::m0, &Owner::m1, 15, 0);
