// from server: 100% by nuck16
// roc 2009-12 0096e2a0  unit: seg_00960000  size: 45 bytes
//
// 0096e2a0  33c9                 xor ecx, ecx
// 0096e2a2  51                   push ecx
// 0096e2a3  6a0f                 push 0xf
// 0096e2a5  51                   push ecx
// 0096e2a6  51                   push ecx
// 0096e2a7  b8e0d36200           mov eax, 0x62d3e0
// 0096e2ac  50                   push eax
// 0096e2ad  68a0b99c00           push 0x9cb9a0
// 0096e2b2  681cba9c00           push 0x9cba1c
// 0096e2b7  b9144bb800           mov ecx, 0xb84b14
// 0096e2bc  e89f12ccff           call 0x62f560
// 0096e2c1  6800129800           push 0x981200
// 0096e2c6  e85e66e8ff           call 0x7f4929
// 0096e2cb  59                   pop ecx
// 0096e2cc  c3                   ret 

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

static Desc desc("PageFileBytes", "PerfCounters", &Owner::m0, 0, 15, 0);
