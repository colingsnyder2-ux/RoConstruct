// from server: 100% by nuck16
// roc 2009-12 00976920  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00976920
//
// 00976920  6a01                 push 1
// 00976922  688cb39d00           push 0x9db38c
// 00976927  33c9                 xor ecx, ecx
// 00976929  68b8b39d00           push 0x9db3b8
// 0097692e  51                   push ecx
// 0097692f  b834010000           mov eax, 0x134
// 00976934  50                   push eax
// 00976935  b9703fb900           mov ecx, 0xb93f70
// 0097693a  e8d118d7ff           call 0x6e8210
// 0097693f  68c0689800           push 0x9868c0
// 00976944  e8e0dfe7ff           call 0x7f4929
// 00976949  59                   pop ecx
// 0097694a  c3                   ret 

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

static Desc desc(&Owner::m0, "FallingDown", "active", 1);
