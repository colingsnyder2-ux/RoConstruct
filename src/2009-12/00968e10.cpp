// from server: 100% by nuck16
// roc 2009-12 00968e10  unit: seg_00960000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00968e10
//
// 00968e10  33c9                 xor ecx, ecx
// 00968e12  51                   push ecx
// 00968e13  6a0f                 push 0xf
// 00968e15  51                   push ecx
// 00968e16  b800984400           mov eax, 0x449800
// 00968e1b  50                   push eax
// 00968e1c  6880ac8a00           push 0x8aac80
// 00968e21  6880aa9a00           push 0x9aaa80
// 00968e26  68a0aa9a00           push 0x9aaaa0
// 00968e2b  b938b0b700           mov ecx, 0xb7b038
// 00968e30  e8db19aeff           call 0x44a810
// 00968e35  68f0e29700           push 0x97e2f0
// 00968e3a  e8eabae8ff           call 0x7f4929
// 00968e3f  59                   pop ecx
// 00968e40  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

extern "C" void func_008aac80();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("WoodQuality", "Quality", func_008aac80, &Owner::m0, 15, 0);
