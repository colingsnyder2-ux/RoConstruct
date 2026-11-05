// from server: 100% by nuck16
// roc 2009-12 009793d0  unit: seg_00970000  size: 57 bytes
//
// 009793d0  56                   push esi
// 009793d1  33f6                 xor esi, esi
// 009793d3  56                   push esi
// 009793d4  6a0f                 push 0xf
// 009793d6  33c9                 xor ecx, ecx
// 009793d8  51                   push ecx
// 009793d9  b800307300           mov eax, 0x733000
// 009793de  50                   push eax
// 009793df  56                   push esi
// 009793e0  ba00347500           mov edx, 0x753400
// 009793e5  52                   push edx
// 009793e6  6884b09b00           push 0x9bb084
// 009793eb  684cd59a00           push 0x9ad54c
// 009793f0  b9a45db900           mov ecx, 0xb95da4
// 009793f5  e8265ddbff           call 0x72f120
// 009793fa  6830819800           push 0x988130
// 009793ff  e825b5e7ff           call 0x7f4929
// 00979404  83c404               add esp, 4
// 00979407  5e                   pop esi
// 00979408  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
    void m1();
};


struct Desc
{
    Desc(const char *, const char *, void (Owner::*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("Value", "Data", &Owner::m0, &Owner::m1, 15, 0);
