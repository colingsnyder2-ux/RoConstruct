// from server: 100% by nuck16
// roc 2009-12 00976b70  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00976b70
//
// 00976b70  6a01                 push 1
// 00976b72  68f0b39d00           push 0x9db3f0
// 00976b77  33c9                 xor ecx, ecx
// 00976b79  6854b49d00           push 0x9db454
// 00976b7e  51                   push ecx
// 00976b7f  b808010000           mov eax, 0x108
// 00976b84  50                   push eax
// 00976b85  b9e035b900           mov ecx, 0xb935e0
// 00976b8a  e8c11cd7ff           call 0x6e8850
// 00976b8f  68306b9800           push 0x986b30
// 00976b94  e890dde7ff           call 0x7f4929
// 00976b99  59                   pop ecx
// 00976b9a  c3                   ret 

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

static Desc desc(&Owner::m0, "StatusAdded", "status", 1);
