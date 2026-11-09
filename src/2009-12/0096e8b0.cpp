// from server: 100% by nuck16
// roc 2009-12 0096e8b0  unit: seg_00960000  size: 57 bytes
//
// 0096e8b0  56                   push esi
// 0096e8b1  33f6                 xor esi, esi
// 0096e8b3  56                   push esi
// 0096e8b4  6a0f                 push 0xf
// 0096e8b6  33c9                 xor ecx, ecx
// 0096e8b8  51                   push ecx
// 0096e8b9  b830be6200           mov eax, 0x62be30
// 0096e8be  50                   push eax
// 0096e8bf  56                   push esi
// 0096e8c0  ba20be6200           mov edx, 0x62be20
// 0096e8c5  52                   push edx
// 0096e8c6  6818bc9c00           push 0x9cbc18
// 0096e8cb  6804bc9c00           push 0x9cbc04
// 0096e8d0  b94050b800           mov ecx, 0xb85040
// 0096e8d5  e8360fccff           call 0x62f810
// 0096e8da  6820149800           push 0x981420
// 0096e8df  e84560e8ff           call 0x7f4929
// 0096e8e4  83c404               add esp, 4
// 0096e8e7  5e                   pop esi
// 0096e8e8  c3                   ret 

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

static Desc desc("IsProfilingEnabled", "Benchmarking", &Owner::m0, &Owner::m1, 15, 0);
