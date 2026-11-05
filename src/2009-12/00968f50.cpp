// from server: 100% by nuck16
// roc 2009-12 00968f50  unit: seg_00960000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00968f50
//
// 00968f50  33c9                 xor ecx, ecx
// 00968f52  51                   push ecx
// 00968f53  6a0f                 push 0xf
// 00968f55  51                   push ecx
// 00968f56  b8f0984400           mov eax, 0x4498f0
// 00968f5b  50                   push eax
// 00968f5c  6870584d00           push 0x4d5870
// 00968f61  6880aa9a00           push 0x9aaa80
// 00968f66  68f8aa9a00           push 0x9aaaf8
// 00968f6b  b900b1b700           mov ecx, 0xb7b100
// 00968f70  e89b18aeff           call 0x44a810
// 00968f75  6810e29700           push 0x97e210
// 00968f7a  e8aab9e8ff           call 0x7f4929
// 00968f7f  59                   pop ecx
// 00968f80  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

extern "C" void func_004d5870();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("PlasticQuality", "Quality", func_004d5870, &Owner::m0, 15, 0);
