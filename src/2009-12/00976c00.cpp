// from server: 100% by nuck16
// roc 2009-12 00976c00  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00976c00
//
// 00976c00  6a01                 push 1
// 00976c02  68f0b39d00           push 0x9db3f0
// 00976c07  33c9                 xor ecx, ecx
// 00976c09  6884b49d00           push 0x9db484
// 00976c0e  51                   push ecx
// 00976c0f  b814010000           mov eax, 0x114
// 00976c14  50                   push eax
// 00976c15  b9c83cb900           mov ecx, 0xb93cc8
// 00976c1a  e8811dd7ff           call 0x6e89a0
// 00976c1f  68006a9800           push 0x986a00
// 00976c24  e800dde7ff           call 0x7f4929
// 00976c29  59                   pop ecx
// 00976c2a  c3                   ret 

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

static Desc desc(&Owner::m0, "CustomStatusRemoved", "status", 1);
