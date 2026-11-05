// from server: 100% by nuck16
// roc 2009-12 00976bd0  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00976bd0
//
// 00976bd0  6a01                 push 1
// 00976bd2  68f0b39d00           push 0x9db3f0
// 00976bd7  33c9                 xor ecx, ecx
// 00976bd9  6870b49d00           push 0x9db470
// 00976bde  51                   push ecx
// 00976bdf  b810010000           mov eax, 0x110
// 00976be4  50                   push eax
// 00976be5  b97039b900           mov ecx, 0xb93970
// 00976bea  e8b11dd7ff           call 0x6e89a0
// 00976bef  68706b9800           push 0x986b70
// 00976bf4  e830dde7ff           call 0x7f4929
// 00976bf9  59                   pop ecx
// 00976bfa  c3                   ret 

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

static Desc desc(&Owner::m0, "CustomStatusAdded", "status", 1);
