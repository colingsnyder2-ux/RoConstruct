// from server: 100% by nuck16
// roc 2009-12 0096e060  unit: seg_00960000  size: 45 bytes
//
// 0096e060  33c9                 xor ecx, ecx
// 0096e062  51                   push ecx
// 0096e063  6a0f                 push 0xf
// 0096e065  51                   push ecx
// 0096e066  51                   push ecx
// 0096e067  b870c56200           mov eax, 0x62c570
// 0096e06c  50                   push eax
// 0096e06d  6864b79a00           push 0x9ab764
// 0096e072  68241e9c00           push 0x9c1e24
// 0096e077  b96050b800           mov ecx, 0xb85060
// 0096e07c  e89f13ccff           call 0x62f420
// 0096e081  68c0109800           push 0x9810c0
// 0096e086  e89e68e8ff           call 0x7f4929
// 0096e08b  59                   pop ecx
// 0096e08c  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};


struct Desc
{
    Desc(const char *, const char *, void (Owner::*)(), int, int, int);
    ~Desc();
};

static Desc desc("CPU", "Profile", &Owner::m0, 0, 15, 0);
