// from server: 100% by nuck16
// roc 2009-12 0097b9e0  unit: seg_00970000  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097b9e0
//
// 0097b9e0  33c9                 xor ecx, ecx
// 0097b9e2  51                   push ecx
// 0097b9e3  6a0f                 push 0xf
// 0097b9e5  51                   push ecx
// 0097b9e6  51                   push ecx
// 0097b9e7  b8b0b67600           mov eax, 0x76b6b0
// 0097b9ec  50                   push eax
// 0097b9ed  6884b09b00           push 0x9bb084
// 0097b9f2  680c1c9e00           push 0x9e1c0c
// 0097b9f7  b97880b900           mov ecx, 0xb98078
// 0097b9fc  e8cf03dfff           call 0x76bdd0
// 0097ba01  68309a9800           push 0x989a30
// 0097ba06  e81e8fe7ff           call 0x7f4929
// 0097ba0b  59                   pop ecx
// 0097ba0c  c3                   ret 

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
    Desc(const char *, const char *, void (Owner::*)(), int, int, int);
    ~Desc();
};

static Desc desc("Target", "Data", &Owner::m0, 0, 15, 0);
