// from server: 100% by nuck16
// roc 2009-12 00968d10  unit: seg_00960000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00968d10
//
// 00968d10  33c9                 xor ecx, ecx
// 00968d12  51                   push ecx
// 00968d13  6a0f                 push 0xf
// 00968d15  51                   push ecx
// 00968d16  b840974400           mov eax, 0x449740
// 00968d1b  50                   push eax
// 00968d1c  68d01d4400           push 0x441dd0
// 00968d21  6880aa9a00           push 0x9aaa80
// 00968d26  68e8a59a00           push 0x9aa5e8
// 00968d2b  b998afb700           mov ecx, 0xb7af98
// 00968d30  e86b17aeff           call 0x44a4a0
// 00968d35  6870e39700           push 0x97e370
// 00968d3a  e8eabbe8ff           call 0x7f4929
// 00968d3f  59                   pop ecx
// 00968d40  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

extern "C" void func_00441dd0();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("Bevels", "Quality", func_00441dd0, &Owner::m0, 15, 0);
