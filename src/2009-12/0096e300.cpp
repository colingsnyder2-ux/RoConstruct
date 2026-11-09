// from server: 100% by nuck16
// roc 2009-12 0096e300  unit: seg_00960000  size: 45 bytes
//
// 0096e300  33c9                 xor ecx, ecx
// 0096e302  51                   push ecx
// 0096e303  6a0f                 push 0xf
// 0096e305  51                   push ecx
// 0096e306  51                   push ecx
// 0096e307  b8e0c66200           mov eax, 0x62c6e0
// 0096e30c  50                   push eax
// 0096e30d  68a0b99c00           push 0x9cb9a0
// 0096e312  6840ba9c00           push 0x9cba40
// 0096e317  b92050b800           mov ecx, 0xb85020
// 0096e31c  e87f13ccff           call 0x62f6a0
// 0096e321  6860129800           push 0x981260
// 0096e326  e8fe65e8ff           call 0x7f4929
// 0096e32b  59                   pop ecx
// 0096e32c  c3                   ret 

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

static Desc desc("InstanceCount", "PerfCounters", &Owner::m0, 0, 15, 0);
