// from server: 100% by nuck16
// roc 2009-12 0096e3c0  unit: seg_00960000  size: 45 bytes
//
// 0096e3c0  33c9                 xor ecx, ecx
// 0096e3c2  51                   push ecx
// 0096e3c3  6a0f                 push 0xf
// 0096e3c5  51                   push ecx
// 0096e3c6  51                   push ecx
// 0096e3c7  b8f0c66200           mov eax, 0x62c6f0
// 0096e3cc  50                   push eax
// 0096e3cd  68a0b99c00           push 0x9cb9a0
// 0096e3d2  6874ba9c00           push 0x9cba74
// 0096e3d7  b9b44bb800           mov ecx, 0xb84bb4
// 0096e3dc  e8bf12ccff           call 0x62f6a0
// 0096e3e1  68c0129800           push 0x9812c0
// 0096e3e6  e83e65e8ff           call 0x7f4929
// 0096e3eb  59                   pop ecx
// 0096e3ec  c3                   ret 

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

static Desc desc("JobCount", "PerfCounters", &Owner::m0, 0, 15, 0);
