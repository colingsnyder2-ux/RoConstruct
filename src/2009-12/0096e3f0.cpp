// from server: 100% by nuck16
// roc 2009-12 0096e3f0  unit: seg_00960000  size: 45 bytes
//
// 0096e3f0  33c9                 xor ecx, ecx
// 0096e3f2  51                   push ecx
// 0096e3f3  6a0f                 push 0xf
// 0096e3f5  51                   push ecx
// 0096e3f6  51                   push ecx
// 0096e3f7  b8f0bd6200           mov eax, 0x62bdf0
// 0096e3fc  50                   push eax
// 0096e3fd  68a0b99c00           push 0x9cb9a0
// 0096e402  6880ba9c00           push 0x9cba80
// 0096e407  b9e04fb800           mov ecx, 0xb84fe0
// 0096e40c  e88f12ccff           call 0x62f6a0
// 0096e411  68e0129800           push 0x9812e0
// 0096e416  e80e65e8ff           call 0x7f4929
// 0096e41b  59                   pop ecx
// 0096e41c  c3                   ret 

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

static Desc desc("CdnSuccessCount", "PerfCounters", &Owner::m0, 0, 15, 0);
