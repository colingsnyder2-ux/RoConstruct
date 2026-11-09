// from server: 100% by nuck16
// roc 2009-12 00968ab0  unit: seg_00960000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00968ab0
//
// 00968ab0  33c9                 xor ecx, ecx
// 00968ab2  51                   push ecx
// 00968ab3  6a0f                 push 0xf
// 00968ab5  51                   push ecx
// 00968ab6  b8d0964400           mov eax, 0x4496d0
// 00968abb  50                   push eax
// 00968abc  6870f65200           push 0x52f670
// 00968ac1  68c0a99a00           push 0x9aa9c0
// 00968ac6  68b0a99a00           push 0x9aa9b0
// 00968acb  b940aeb700           mov ecx, 0xb7ae40
// 00968ad0  e8ab14aeff           call 0x449f80
// 00968ad5  68b0e29700           push 0x97e2b0
// 00968ada  e84abee8ff           call 0x7f4929
// 00968adf  59                   pop ecx
// 00968ae0  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

extern "C" void func_0052f670();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("graphicsMode", "General", func_0052f670, &Owner::m0, 15, 0);
