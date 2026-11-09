// from server: 100% by nuck16
// roc 2009-12 00968fd0  unit: seg_00960000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00968fd0
//
// 00968fd0  33c9                 xor ecx, ecx
// 00968fd2  51                   push ecx
// 00968fd3  6a0f                 push 0xf
// 00968fd5  51                   push ecx
// 00968fd6  b820994400           mov eax, 0x449920
// 00968fdb  50                   push eax
// 00968fdc  68f0337700           push 0x7733f0
// 00968fe1  6880aa9a00           push 0x9aaa80
// 00968fe6  6818ab9a00           push 0x9aab18
// 00968feb  b950b1b700           mov ecx, 0xb7b150
// 00968ff0  e81b18aeff           call 0x44a810
// 00968ff5  6850e29700           push 0x97e250
// 00968ffa  e82ab9e8ff           call 0x7f4929
// 00968fff  59                   pop ecx
// 00969000  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

extern "C" void func_007733f0();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("CompoundMaterialQuality", "Quality", func_007733f0, &Owner::m0, 15, 0);
