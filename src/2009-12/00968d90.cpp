// from server: 100% by nuck16
// roc 2009-12 00968d90  unit: seg_00960000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00968d90
//
// 00968d90  33c9                 xor ecx, ecx
// 00968d92  51                   push ecx
// 00968d93  6a0f                 push 0xf
// 00968d95  51                   push ecx
// 00968d96  b8a0974400           mov eax, 0x4497a0
// 00968d9b  50                   push eax
// 00968d9c  6870414400           push 0x444170
// 00968da1  6880aa9a00           push 0x9aaa80
// 00968da6  6828a69a00           push 0x9aa628
// 00968dab  b9e8afb700           mov ecx, 0xb7afe8
// 00968db0  e8bb18aeff           call 0x44a670
// 00968db5  6830e39700           push 0x97e330
// 00968dba  e86abbe8ff           call 0x7f4929
// 00968dbf  59                   pop ecx
// 00968dc0  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

extern "C" void func_00444170();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("Shadow", "Quality", func_00444170, &Owner::m0, 15, 0);
