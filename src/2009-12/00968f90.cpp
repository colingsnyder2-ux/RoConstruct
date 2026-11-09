// from server: 100% by nuck16
// roc 2009-12 00968f90  unit: seg_00960000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00968f90
//
// 00968f90  33c9                 xor ecx, ecx
// 00968f92  51                   push ecx
// 00968f93  6a0f                 push 0xf
// 00968f95  51                   push ecx
// 00968f96  b850994400           mov eax, 0x449950
// 00968f9b  50                   push eax
// 00968f9c  68a0a38100           push 0x81a3a0
// 00968fa1  6880aa9a00           push 0x9aaa80
// 00968fa6  6808ab9a00           push 0x9aab08
// 00968fab  b928b1b700           mov ecx, 0xb7b128
// 00968fb0  e85b18aeff           call 0x44a810
// 00968fb5  6830e29700           push 0x97e230
// 00968fba  e86ab9e8ff           call 0x7f4929
// 00968fbf  59                   pop ecx
// 00968fc0  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

extern "C" void func_0081a3a0();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("SlateQuality", "Quality", func_0081a3a0, &Owner::m0, 15, 0);
