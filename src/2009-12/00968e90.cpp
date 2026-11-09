// from server: 100% by nuck16
// roc 2009-12 00968e90  unit: seg_00960000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00968e90
//
// 00968e90  33c9                 xor ecx, ecx
// 00968e92  51                   push ecx
// 00968e93  6a0f                 push 0xf
// 00968e95  51                   push ecx
// 00968e96  b860984400           mov eax, 0x449860
// 00968e9b  50                   push eax
// 00968e9c  68c0628c00           push 0x8c62c0
// 00968ea1  6880aa9a00           push 0x9aaa80
// 00968ea6  68c4aa9a00           push 0x9aaac4
// 00968eab  b988b0b700           mov ecx, 0xb7b088
// 00968eb0  e85b19aeff           call 0x44a810
// 00968eb5  68b0e19700           push 0x97e1b0
// 00968eba  e86abae8ff           call 0x7f4929
// 00968ebf  59                   pop ecx
// 00968ec0  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

extern "C" void func_008c62c0();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("DiamondPlateQuality", "Quality", func_008c62c0, &Owner::m0, 15, 0);
