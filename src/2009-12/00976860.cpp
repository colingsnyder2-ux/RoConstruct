// from server: 100% by nuck16
// roc 2009-12 00976860  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00976860
//
// 00976860  6a01                 push 1
// 00976862  688cb39d00           push 0x9db38c
// 00976867  33c9                 xor ecx, ecx
// 00976869  6884b39d00           push 0x9db384
// 0097686e  51                   push ecx
// 0097686f  b824010000           mov eax, 0x124
// 00976874  50                   push eax
// 00976875  b9183bb900           mov ecx, 0xb93b18
// 0097687a  e89119d7ff           call 0x6e8210
// 0097687f  68906a9800           push 0x986a90
// 00976884  e8a0e0e7ff           call 0x7f4929
// 00976889  59                   pop ecx
// 0097688a  c3                   ret 

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

static Desc desc(&Owner::m0, "Jumping", "active", 1);
