// from server: 100% by nuck16
// roc 2009-12 0097aeb0  unit: seg_00970000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097aeb0
//
// 0097aeb0  33c9                 xor ecx, ecx
// 0097aeb2  51                   push ecx
// 0097aeb3  6a0f                 push 0xf
// 0097aeb5  51                   push ecx
// 0097aeb6  b8e09d7500           mov eax, 0x759de0
// 0097aebb  50                   push eax
// 0097aebc  6890f75d00           push 0x5df790
// 0097aec1  6884b09b00           push 0x9bb084
// 0097aec6  68fc5e9e00           push 0x9e5efc
// 0097aecb  b91876b900           mov ecx, 0xb97618
// 0097aed0  e87bf2ddff           call 0x75a150
// 0097aed5  6810969800           push 0x989610
// 0097aeda  e84a9ae7ff           call 0x7f4929
// 0097aedf  59                   pop ecx
// 0097aee0  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

extern "C" void func_005df790();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("TextTransparency", "Data", func_005df790, &Owner::m0, 15, 0);
