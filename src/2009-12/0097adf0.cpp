// from server: 100% by nuck16
// roc 2009-12 0097adf0  unit: seg_00970000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097adf0
//
// 0097adf0  33c9                 xor ecx, ecx
// 0097adf2  51                   push ecx
// 0097adf3  6a0f                 push 0xf
// 0097adf5  51                   push ecx
// 0097adf6  b8809c7500           mov eax, 0x759c80
// 0097adfb  50                   push eax
// 0097adfc  68c0877500           push 0x7587c0
// 0097ae01  6884b09b00           push 0x9bb084
// 0097ae06  6860e49d00           push 0x9de460
// 0097ae0b  b95876b900           mov ecx, 0xb97658
// 0097ae10  e85bf1ddff           call 0x759f70
// 0097ae15  6870969800           push 0x989670
// 0097ae1a  e80a9be7ff           call 0x7f4929
// 0097ae1f  59                   pop ecx
// 0097ae20  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

extern "C" void func_007587c0();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("Text", "Data", func_007587c0, &Owner::m0, 15, 0);
