// from server: 100% by nuck16
// roc 2009-12 00968ed0  unit: seg_00960000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00968ed0
//
// 00968ed0  33c9                 xor ecx, ecx
// 00968ed2  51                   push ecx
// 00968ed3  6a0f                 push 0xf
// 00968ed5  51                   push ecx
// 00968ed6  b890984400           mov eax, 0x449890
// 00968edb  50                   push eax
// 00968edc  68902f8a00           push 0x8a2f90
// 00968ee1  6880aa9a00           push 0x9aaa80
// 00968ee6  68d8aa9a00           push 0x9aaad8
// 00968eeb  b9b0b0b700           mov ecx, 0xb7b0b0
// 00968ef0  e81b19aeff           call 0x44a810
// 00968ef5  68d0e19700           push 0x97e1d0
// 00968efa  e82abae8ff           call 0x7f4929
// 00968eff  59                   pop ecx
// 00968f00  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

extern "C" void func_008a2f90();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("AluminumQuality", "Quality", func_008a2f90, &Owner::m0, 15, 0);
