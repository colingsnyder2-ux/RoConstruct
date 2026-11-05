// from server: 100% by nuck16
// roc 2009-12 0096e030  unit: seg_00960000  size: 45 bytes
//
// 0096e030  33c9                 xor ecx, ecx
// 0096e032  51                   push ecx
// 0096e033  6a0f                 push 0xf
// 0096e035  51                   push ecx
// 0096e036  51                   push ecx
// 0096e037  b860c16200           mov eax, 0x62c160
// 0096e03c  50                   push eax
// 0096e03d  6864b79a00           push 0x9ab764
// 0096e042  685cb99c00           push 0x9cb95c
// 0096e047  b9ac49b800           mov ecx, 0xb849ac
// 0096e04c  e8cf13ccff           call 0x62f420
// 0096e051  68a0109800           push 0x9810a0
// 0096e056  e8ce68e8ff           call 0x7f4929
// 0096e05b  59                   pop ecx
// 0096e05c  c3                   ret 

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

static Desc desc("GfxCard", "Profile", &Owner::m0, 0, 15, 0);
