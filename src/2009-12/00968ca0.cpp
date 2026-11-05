// from server: 100% by nuck16
// roc 2009-12 00968ca0  unit: seg_00960000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00968ca0
//
// 00968ca0  33c9                 xor ecx, ecx
// 00968ca2  51                   push ecx
// 00968ca3  6a0f                 push 0xf
// 00968ca5  51                   push ecx
// 00968ca6  b840964400           mov eax, 0x449640
// 00968cab  50                   push eax
// 00968cac  6840414400           push 0x444140
// 00968cb1  6880aa9a00           push 0x9aaa80
// 00968cb6  6864a59a00           push 0x9aa564
// 00968cbb  b950afb700           mov ecx, 0xb7af50
// 00968cc0  e80b17aeff           call 0x44a3d0
// 00968cc5  6890e39700           push 0x97e390
// 00968cca  e85abce8ff           call 0x7f4929
// 00968ccf  59                   pop ecx
// 00968cd0  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

extern "C" void func_00444140();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("AASamples", "Quality", func_00444140, &Owner::m0, 15, 0);
