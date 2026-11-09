// from server: 100% by nuck16
// roc 2009-12 0096e180  unit: seg_00960000  size: 45 bytes
//
// 0096e180  33c9                 xor ecx, ecx
// 0096e182  51                   push ecx
// 0096e183  6a0f                 push 0xf
// 0096e185  51                   push ecx
// 0096e186  51                   push ecx
// 0096e187  b8f0cf6200           mov eax, 0x62cff0
// 0096e18c  50                   push eax
// 0096e18d  68a0b99c00           push 0x9cb9a0
// 0096e192  68b0b99c00           push 0x9cb9b0
// 0096e197  b9044db800           mov ecx, 0xb84d04
// 0096e19c  e85f14ccff           call 0x62f600
// 0096e1a1  68c0159800           push 0x9815c0
// 0096e1a6  e87e67e8ff           call 0x7f4929
// 0096e1ab  59                   pop ecx
// 0096e1ac  c3                   ret 

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

static Desc desc("ProcessCores", "PerfCounters", &Owner::m0, 0, 15, 0);
