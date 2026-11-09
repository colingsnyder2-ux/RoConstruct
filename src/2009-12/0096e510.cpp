// from server: 100% by nuck16
// roc 2009-12 0096e510  unit: seg_00960000  size: 45 bytes
//
// 0096e510  33c9                 xor ecx, ecx
// 0096e512  51                   push ecx
// 0096e513  6a0f                 push 0xf
// 0096e515  51                   push ecx
// 0096e516  51                   push ecx
// 0096e517  b830c76200           mov eax, 0x62c730
// 0096e51c  50                   push eax
// 0096e51d  68b8c59b00           push 0x9bc5b8
// 0096e522  68f0ba9c00           push 0x9cbaf0
// 0096e527  b9084eb800           mov ecx, 0xb84e08
// 0096e52c  e85f09ccff           call 0x62ee90
// 0096e531  6840139800           push 0x981340
// 0096e536  e8ee63e8ff           call 0x7f4929
// 0096e53b  59                   pop ecx
// 0096e53c  c3                   ret 

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

static Desc desc("NumSleepingJobs", "Diagnostics", &Owner::m0, 0, 15, 0);
