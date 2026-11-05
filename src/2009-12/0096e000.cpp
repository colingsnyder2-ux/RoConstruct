// from server: 100% by nuck16
// roc 2009-12 0096e000  unit: seg_00960000  size: 45 bytes
//
// 0096e000  33c9                 xor ecx, ecx
// 0096e002  51                   push ecx
// 0096e003  6a0f                 push 0xf
// 0096e005  51                   push ecx
// 0096e006  51                   push ecx
// 0096e007  b8e0c06200           mov eax, 0x62c0e0
// 0096e00c  50                   push eax
// 0096e00d  6864b79a00           push 0x9ab764
// 0096e012  6850b99c00           push 0x9cb950
// 0096e017  b9444db800           mov ecx, 0xb84d44
// 0096e01c  e8ff13ccff           call 0x62f420
// 0096e021  6880109800           push 0x981080
// 0096e026  e8fe68e8ff           call 0x7f4929
// 0096e02b  59                   pop ecx
// 0096e02c  c3                   ret 

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

static Desc desc("GlVendor", "Profile", &Owner::m0, 0, 15, 0);
