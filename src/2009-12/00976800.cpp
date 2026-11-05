// from server: 100% by nuck16
// roc 2009-12 00976800  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00976800
//
// 00976800  6a01                 push 1
// 00976802  6870b39d00           push 0x9db370
// 00976807  33c9                 xor ecx, ecx
// 00976809  6868b39d00           push 0x9db368
// 0097680e  51                   push ecx
// 0097680f  b81c010000           mov eax, 0x11c
// 00976814  50                   push eax
// 00976815  b90038b900           mov ecx, 0xb93800
// 0097681a  e89118d7ff           call 0x6e80b0
// 0097681f  68506a9800           push 0x986a50
// 00976824  e800e1e7ff           call 0x7f4929
// 00976829  59                   pop ecx
// 0097682a  c3                   ret 

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

static Desc desc(&Owner::m0, "Running", "speed", 1);
