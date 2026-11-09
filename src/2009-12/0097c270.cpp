// from server: 100% by nuck16
// roc 2009-12 0097c270  unit: seg_00970000  size: 57 bytes
//
// 0097c270  56                   push esi
// 0097c271  33f6                 xor esi, esi
// 0097c273  56                   push esi
// 0097c274  6a0f                 push 0xf
// 0097c276  33c9                 xor ecx, ecx
// 0097c278  51                   push ecx
// 0097c279  b850ff7600           mov eax, 0x76ff50
// 0097c27e  50                   push eax
// 0097c27f  56                   push esi
// 0097c280  ba90887500           mov edx, 0x758890
// 0097c285  52                   push edx
// 0097c286  6884b09b00           push 0x9bb084
// 0097c28b  68b08a9e00           push 0x9e8ab0
// 0097c290  b9b083b900           mov ecx, 0xb983b0
// 0097c295  e8a629dfff           call 0x76ec40
// 0097c29a  68509f9800           push 0x989f50
// 0097c29f  e88586e7ff           call 0x7f4929
// 0097c2a4  83c404               add esp, 4
// 0097c2a7  5e                   pop esi
// 0097c2a8  c3                   ret 

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

static Desc desc("AutoButtonColor", "Data", &Owner::m0, &Owner::m1, 15, 0);
