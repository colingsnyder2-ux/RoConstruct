// from server: 100% by nuck16
// roc 2009-12 0097b380  unit: seg_00970000  size: 57 bytes
//
// 0097b380  56                   push esi
// 0097b381  33f6                 xor esi, esi
// 0097b383  56                   push esi
// 0097b384  6a0f                 push 0xf
// 0097b386  33c9                 xor ecx, ecx
// 0097b388  51                   push ecx
// 0097b389  b8d0f67500           mov eax, 0x75f6d0
// 0097b38e  50                   push eax
// 0097b38f  56                   push esi
// 0097b390  baa08c7400           mov edx, 0x748ca0
// 0097b395  52                   push edx
// 0097b396  6884b09b00           push 0x9bb084
// 0097b39b  68b0589b00           push 0x9b58b0
// 0097b3a0  b9e479b900           mov ecx, 0xb979e4
// 0097b3a5  e89641deff           call 0x75f540
// 0097b3aa  6850989800           push 0x989850
// 0097b3af  e87595e7ff           call 0x7f4929
// 0097b3b4  83c404               add esp, 4
// 0097b3b7  5e                   pop esi
// 0097b3b8  c3                   ret 

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

static Desc desc("Visible", "Data", &Owner::m0, &Owner::m1, 15, 0);
