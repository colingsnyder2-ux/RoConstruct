// from server: 100% by nuck16
// roc 2009-12 0097afb0  unit: seg_00970000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097afb0
//
// 0097afb0  33c9                 xor ecx, ecx
// 0097afb2  51                   push ecx
// 0097afb3  6a0f                 push 0xf
// 0097afb5  51                   push ecx
// 0097afb6  b890af7500           mov eax, 0x75af90
// 0097afbb  50                   push eax
// 0097afbc  68c0877500           push 0x7587c0
// 0097afc1  6884b09b00           push 0x9bb084
// 0097afc6  6860e49d00           push 0x9de460
// 0097afcb  b95477b900           mov ecx, 0xb97754
// 0097afd0  e85b03deff           call 0x75b330
// 0097afd5  6850979800           push 0x989750
// 0097afda  e84a99e7ff           call 0x7f4929
// 0097afdf  59                   pop ecx
// 0097afe0  c3                   ret 

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
