// from server: 100% by nuck16
// roc 2009-12 009768f0  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009768f0
//
// 009768f0  6a01                 push 1
// 009768f2  688cb39d00           push 0x9db38c
// 009768f7  33c9                 xor ecx, ecx
// 009768f9  68acb39d00           push 0x9db3ac
// 009768fe  51                   push ecx
// 009768ff  b82c010000           mov eax, 0x12c
// 00976904  50                   push eax
// 00976905  b9b83bb900           mov ecx, 0xb93bb8
// 0097690a  e80119d7ff           call 0x6e8210
// 0097690f  6880689800           push 0x986880
// 00976914  e810e0e7ff           call 0x7f4929
// 00976919  59                   pop ecx
// 0097691a  c3                   ret 

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

static Desc desc(&Owner::m0, "Strafing", "active", 1);
