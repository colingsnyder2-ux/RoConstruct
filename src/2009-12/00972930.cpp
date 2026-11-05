// from server: 100% by nuck16
// roc 2009-12 00972930  unit: seg_00970000  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00972930
//
// 00972930  6a01                 push 1
// 00972932  33c9                 xor ecx, ecx
// 00972934  6848f39c00           push 0x9cf348
// 00972939  51                   push ecx
// 0097293a  b8f0cf6600           mov eax, 0x66cff0
// 0097293f  50                   push eax
// 00972940  b9c003b900           mov ecx, 0xb903c0
// 00972945  e8f6c6cfff           call 0x66f040
// 0097294a  68704b9800           push 0x984b70
// 0097294f  e8d51fe8ff           call 0x7f4929
// 00972954  59                   pop ecx
// 00972955  c3                   ret 

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
    Desc(void (Owner::*)(), const char *, int);
    ~Desc();
};

static Desc desc(&Owner::m0, "GetJobsInfo", 1);
