// from server: 100% by nuck16
// roc 2009-12 0097acb0  unit: seg_00970000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097acb0
//
// 0097acb0  33c9                 xor ecx, ecx
// 0097acb2  51                   push ecx
// 0097acb3  6a0f                 push 0xf
// 0097acb5  51                   push ecx
// 0097acb6  b8508d7500           mov eax, 0x758d50
// 0097acbb  50                   push eax
// 0097acbc  6820887500           push 0x758820
// 0097acc1  6884b09b00           push 0x9bb084
// 0097acc6  68f05e9e00           push 0x9e5ef0
// 0097accb  b93c75b900           mov ecx, 0xb9753c
// 0097acd0  e8cbe3ddff           call 0x7590a0
// 0097acd5  6850959800           push 0x989550
// 0097acda  e84a9ce7ff           call 0x7f4929
// 0097acdf  59                   pop ecx
// 0097ace0  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

extern "C" void func_00758820();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("TextColor3", "Data", func_00758820, &Owner::m0, 15, 0);
