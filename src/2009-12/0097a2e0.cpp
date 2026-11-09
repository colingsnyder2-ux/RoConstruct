// from server: 100% by nuck16
// roc 2009-12 0097a2e0  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097a2e0
//
// 0097a2e0  6a01                 push 1
// 0097a2e2  6844399e00           push 0x9e3944
// 0097a2e7  33c9                 xor ecx, ecx
// 0097a2e9  6834399e00           push 0x9e3934
// 0097a2ee  51                   push ecx
// 0097a2ef  b8a0020000           mov eax, 0x2a0
// 0097a2f4  50                   push eax
// 0097a2f5  b9606eb900           mov ecx, 0xb96e60
// 0097a2fa  e8f1b9dcff           call 0x745cf0
// 0097a2ff  68d08e9800           push 0x988ed0
// 0097a304  e820a6e7ff           call 0x7f4929
// 0097a309  59                   pop ecx
// 0097a30a  c3                   ret 

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

static Desc desc(&Owner::m0, "FlagCaptured", "Player", 1);
