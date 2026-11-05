// from server: 100% by nuck16
// roc 2009-12 0096e540  unit: seg_00960000  size: 45 bytes
//
// 0096e540  33c9                 xor ecx, ecx
// 0096e542  51                   push ecx
// 0096e543  6a0f                 push 0xf
// 0096e545  51                   push ecx
// 0096e546  51                   push ecx
// 0096e547  b840c76200           mov eax, 0x62c740
// 0096e54c  50                   push eax
// 0096e54d  68b8c59b00           push 0x9bc5b8
// 0096e552  6800bb9c00           push 0x9cbb00
// 0096e557  b9884ab800           mov ecx, 0xb84a88
// 0096e55c  e82f09ccff           call 0x62ee90
// 0096e561  68400f9800           push 0x980f40
// 0096e566  e8be63e8ff           call 0x7f4929
// 0096e56b  59                   pop ecx
// 0096e56c  c3                   ret 

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

static Desc desc("NumWaitingJobs", "Diagnostics", &Owner::m0, 0, 15, 0);
