// from server: 100% by nuck16
// roc 2009-12 0097ac30  unit: seg_00970000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097ac30
//
// 0097ac30  33c9                 xor ecx, ecx
// 0097ac32  51                   push ecx
// 0097ac33  6a0f                 push 0xf
// 0097ac35  51                   push ecx
// 0097ac36  b8708c7500           mov eax, 0x758c70
// 0097ac3b  50                   push eax
// 0097ac3c  68c0877500           push 0x7587c0
// 0097ac41  6884b09b00           push 0x9bb084
// 0097ac46  6860e49d00           push 0x9de460
// 0097ac4b  b95c75b900           mov ecx, 0xb9755c
// 0097ac50  e80be3ddff           call 0x758f60
// 0097ac55  6890959800           push 0x989590
// 0097ac5a  e8ca9ce7ff           call 0x7f4929
// 0097ac5f  59                   pop ecx
// 0097ac60  c3                   ret 

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
