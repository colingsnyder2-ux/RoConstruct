// from server: 100% by nuck16
// roc 2009-12 00976980  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00976980
//
// 00976980  6a01                 push 1
// 00976982  68dcb39d00           push 0x9db3dc
// 00976987  33c9                 xor ecx, ecx
// 00976989  68ccb39d00           push 0x9db3cc
// 0097698e  51                   push ecx
// 0097698f  b83c010000           mov eax, 0x13c
// 00976994  50                   push eax
// 00976995  b9b039b900           mov ecx, 0xb939b0
// 0097699a  e81117d7ff           call 0x6e80b0
// 0097699f  6840699800           push 0x986940
// 009769a4  e880dfe7ff           call 0x7f4929
// 009769a9  59                   pop ecx
// 009769aa  c3                   ret 

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

static Desc desc(&Owner::m0, "HealthChanged", "health", 1);
