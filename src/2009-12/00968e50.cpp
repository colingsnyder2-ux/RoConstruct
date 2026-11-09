// from server: 100% by nuck16
// roc 2009-12 00968e50  unit: seg_00960000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00968e50
//
// 00968e50  33c9                 xor ecx, ecx
// 00968e52  51                   push ecx
// 00968e53  6a0f                 push 0xf
// 00968e55  51                   push ecx
// 00968e56  b830984400           mov eax, 0x449830
// 00968e5b  50                   push eax
// 00968e5c  6880414400           push 0x444180
// 00968e61  6880aa9a00           push 0x9aaa80
// 00968e66  68acaa9a00           push 0x9aaaac
// 00968e6b  b960b0b700           mov ecx, 0xb7b060
// 00968e70  e89b19aeff           call 0x44a810
// 00968e75  68d0e29700           push 0x97e2d0
// 00968e7a  e8aabae8ff           call 0x7f4929
// 00968e7f  59                   pop ecx
// 00968e80  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

extern "C" void func_00444180();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("CorrodedMetalQuality", "Quality", func_00444180, &Owner::m0, 15, 0);
