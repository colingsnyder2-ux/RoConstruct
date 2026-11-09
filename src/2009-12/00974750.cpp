// from server: 100% by nuck16
// roc 2009-12 00974750  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00974750
//
// 00974750  6a01                 push 1
// 00974752  68a86e9d00           push 0x9d6ea8
// 00974757  33c9                 xor ecx, ecx
// 00974759  68986e9d00           push 0x9d6e98
// 0097475e  51                   push ecx
// 0097475f  b8e0d86b00           mov eax, 0x6bd8e0
// 00974764  50                   push eax
// 00974765  b97822b900           mov ecx, 0xb92278
// 0097476a  e861e2d4ff           call 0x6c29d0
// 0097476f  68d0599800           push 0x9859d0
// 00974774  e8b001e8ff           call 0x7f4929
// 00974779  59                   pop ecx
// 0097477a  c3                   ret 

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
    Desc(void (Owner::*)(), const char *, const char *, int);
    ~Desc();
};

static Desc desc(&Owner::m0, "SetThreadPool", "count", 1);
