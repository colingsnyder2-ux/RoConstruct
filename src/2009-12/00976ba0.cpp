// from server: 100% by nuck16
// roc 2009-12 00976ba0  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00976ba0
//
// 00976ba0  6a01                 push 1
// 00976ba2  68f0b39d00           push 0x9db3f0
// 00976ba7  33c9                 xor ecx, ecx
// 00976ba9  6860b49d00           push 0x9db460
// 00976bae  51                   push ecx
// 00976baf  b80c010000           mov eax, 0x10c
// 00976bb4  50                   push eax
// 00976bb5  b9383cb900           mov ecx, 0xb93c38
// 00976bba  e8911cd7ff           call 0x6e8850
// 00976bbf  68c0699800           push 0x9869c0
// 00976bc4  e860dde7ff           call 0x7f4929
// 00976bc9  59                   pop ecx
// 00976bca  c3                   ret 

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

static Desc desc(&Owner::m0, "StatusRemoved", "status", 1);
