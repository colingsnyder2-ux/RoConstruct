// from server: 100% by nuck16
// roc 2009-12 0096e390  unit: seg_00960000  size: 45 bytes
//
// 0096e390  33c9                 xor ecx, ecx
// 0096e392  51                   push ecx
// 0096e393  6a0f                 push 0xf
// 0096e395  51                   push ecx
// 0096e396  51                   push ecx
// 0096e397  b8d0c66200           mov eax, 0x62c6d0
// 0096e39c  50                   push eax
// 0096e39d  68a0b99c00           push 0x9cb9a0
// 0096e3a2  6868ba9c00           push 0x9cba68
// 0096e3a7  b9844db800           mov ecx, 0xb84d84
// 0096e3ac  e8ef12ccff           call 0x62f6a0
// 0096e3b1  68a0129800           push 0x9812a0
// 0096e3b6  e86e65e8ff           call 0x7f4929
// 0096e3bb  59                   pop ecx
// 0096e3bc  c3                   ret 

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

static Desc desc("HandleCount", "PerfCounters", &Owner::m0, 0, 15, 0);
