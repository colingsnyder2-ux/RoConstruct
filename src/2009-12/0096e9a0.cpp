// from server: 100% by nuck16
// roc 2009-12 0096e9a0  unit: seg_00960000  size: 57 bytes
//
// 0096e9a0  56                   push esi
// 0096e9a1  33f6                 xor esi, esi
// 0096e9a3  56                   push esi
// 0096e9a4  6a0f                 push 0xf
// 0096e9a6  33c9                 xor ecx, ecx
// 0096e9a8  51                   push ecx
// 0096e9a9  b8c0bd6200           mov eax, 0x62bdc0
// 0096e9ae  50                   push eax
// 0096e9af  56                   push esi
// 0096e9b0  bab0bd6200           mov edx, 0x62bdb0
// 0096e9b5  52                   push edx
// 0096e9b6  6868bc9c00           push 0x9cbc68
// 0096e9bb  6870bc9c00           push 0x9cbc70
// 0096e9c0  b9d44bb800           mov ecx, 0xb84bd4
// 0096e9c5  e8f60eccff           call 0x62f8c0
// 0096e9ca  68e0149800           push 0x9814e0
// 0096e9cf  e8555fe8ff           call 0x7f4929
// 0096e9d4  83c404               add esp, 4
// 0096e9d7  5e                   pop esi
// 0096e9d8  c3                   ret 

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

static Desc desc("InstanceCountLimit", "Limits", &Owner::m0, &Owner::m1, 15, 0);
