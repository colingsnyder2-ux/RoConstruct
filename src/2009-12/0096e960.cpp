// from server: 100% by nuck16
// roc 2009-12 0096e960  unit: seg_00960000  size: 57 bytes
//
// 0096e960  56                   push esi
// 0096e961  33f6                 xor esi, esi
// 0096e963  56                   push esi
// 0096e964  6a0f                 push 0xf
// 0096e966  33c9                 xor ecx, ecx
// 0096e968  51                   push ecx
// 0096e969  b8a0bd6200           mov eax, 0x62bda0
// 0096e96e  50                   push eax
// 0096e96f  56                   push esi
// 0096e970  ba90bd6200           mov edx, 0x62bd90
// 0096e975  52                   push edx
// 0096e976  6868bc9c00           push 0x9cbc68
// 0096e97b  685cbc9c00           push 0x9cbc5c
// 0096e980  b92849b800           mov ecx, 0xb84928
// 0096e985  e8360fccff           call 0x62f8c0
// 0096e98a  6800159800           push 0x981500
// 0096e98f  e8955fe8ff           call 0x7f4929
// 0096e994  83c404               add esp, 4
// 0096e997  5e                   pop esi
// 0096e998  c3                   ret 

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

static Desc desc("LuaRamLimit", "Limits", &Owner::m0, &Owner::m1, 15, 0);
