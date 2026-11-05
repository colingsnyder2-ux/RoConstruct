// from server: 100% by nuck16
// roc 2009-12 00968dd0  unit: seg_00960000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00968dd0
//
// 00968dd0  33c9                 xor ecx, ecx
// 00968dd2  51                   push ecx
// 00968dd3  6a0f                 push 0xf
// 00968dd5  51                   push ecx
// 00968dd6  b870974400           mov eax, 0x449770
// 00968ddb  50                   push eax
// 00968ddc  6820ee4800           push 0x48ee20
// 00968de1  6880aa9a00           push 0x9aaa80
// 00968de6  68d8a59a00           push 0x9aa5d8
// 00968deb  b910b0b700           mov ecx, 0xb7b010
// 00968df0  e84b19aeff           call 0x44a740
// 00968df5  6810e39700           push 0x97e310
// 00968dfa  e82abbe8ff           call 0x7f4929
// 00968dff  59                   pop ecx
// 00968e00  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

extern "C" void func_0048ee20();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("Antialiasing", "Quality", func_0048ee20, &Owner::m0, 15, 0);
