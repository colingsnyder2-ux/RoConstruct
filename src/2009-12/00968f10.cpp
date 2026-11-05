// from server: 100% by nuck16
// roc 2009-12 00968f10  unit: seg_00960000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00968f10
//
// 00968f10  33c9                 xor ecx, ecx
// 00968f12  51                   push ecx
// 00968f13  6a0f                 push 0xf
// 00968f15  51                   push ecx
// 00968f16  b8c0984400           mov eax, 0x4498c0
// 00968f1b  50                   push eax
// 00968f1c  6880dc8400           push 0x84dc80
// 00968f21  6880aa9a00           push 0x9aaa80
// 00968f26  68e8aa9a00           push 0x9aaae8
// 00968f2b  b9d8b0b700           mov ecx, 0xb7b0d8
// 00968f30  e8db18aeff           call 0x44a810
// 00968f35  68f0e19700           push 0x97e1f0
// 00968f3a  e8eab9e8ff           call 0x7f4929
// 00968f3f  59                   pop ecx
// 00968f40  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

extern "C" void func_0084dc80();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("GrassQuality", "Quality", func_0084dc80, &Owner::m0, 15, 0);
