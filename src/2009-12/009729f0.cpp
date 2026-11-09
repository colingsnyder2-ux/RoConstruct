// from server: 100% by nuck16
// roc 2009-12 009729f0  unit: seg_00970000  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009729f0
//
// 009729f0  6a01                 push 1
// 009729f2  33c9                 xor ecx, ecx
// 009729f4  6870f39c00           push 0x9cf370
// 009729f9  51                   push ecx
// 009729fa  b840586600           mov eax, 0x665840
// 009729ff  50                   push eax
// 00972a00  b9a007b900           mov ecx, 0xb907a0
// 00972a05  e886bfcfff           call 0x66e990
// 00972a0a  68c0499800           push 0x9849c0
// 00972a0f  e8151fe8ff           call 0x7f4929
// 00972a14  59                   pop ecx
// 00972a15  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

struct Desc
{
    Desc(void (Owner::*)(), const char *, int);
    ~Desc();
};

static Desc desc(&Owner::m0, "ClearMessage", 1);
