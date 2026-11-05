// from server: 100% by nuck16
// roc 2009-12 009784a0  unit: seg_00970000  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009784a0
//
// 009784a0  33c9                 xor ecx, ecx
// 009784a2  51                   push ecx
// 009784a3  6864e79d00           push 0x9de764
// 009784a8  51                   push ecx
// 009784a9  b880387100           mov eax, 0x713880
// 009784ae  50                   push eax
// 009784af  b9b855b900           mov ecx, 0xb955b8
// 009784b4  e8c7c5d9ff           call 0x714a80
// 009784b9  68407b9800           push 0x987b40
// 009784be  e866c4e7ff           call 0x7f4929
// 009784c3  59                   pop ecx
// 009784c4  c3                   ret 

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

static Desc desc(&Owner::m0, "GetMinutesAfterMidnight", 0);
