// from server: 100% by nuck16
// roc 2009-12 00976c90  unit: seg_00970000  size: 57 bytes
//
// 00976c90  56                   push esi
// 00976c91  33f6                 xor esi, esi
// 00976c93  56                   push esi
// 00976c94  6a08                 push 8
// 00976c96  33c9                 xor ecx, ecx
// 00976c98  51                   push ecx
// 00976c99  b870146f00           mov eax, 0x6f1470
// 00976c9e  50                   push eax
// 00976c9f  56                   push esi
// 00976ca0  bab00e6f00           mov edx, 0x6f0eb0
// 00976ca5  52                   push edx
// 00976ca6  6884b09b00           push 0x9bb084
// 00976cab  68b8409a00           push 0x9a40b8
// 00976cb0  b99c41b900           mov ecx, 0xb9419c
// 00976cb5  e846a4d7ff           call 0x6f1100
// 00976cba  68406c9800           push 0x986c40
// 00976cbf  e865dce7ff           call 0x7f4929
// 00976cc4  83c404               add esp, 4
// 00976cc7  5e                   pop esi
// 00976cc8  c3                   ret 

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

static Desc desc("Color", "Data", &Owner::m0, &Owner::m1, 8, 0);
