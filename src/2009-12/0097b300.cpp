// from server: 100% by nuck16
// roc 2009-12 0097b300  unit: seg_00970000  size: 57 bytes
//
// 0097b300  56                   push esi
// 0097b301  33f6                 xor esi, esi
// 0097b303  56                   push esi
// 0097b304  6a0f                 push 0xf
// 0097b306  33c9                 xor ecx, ecx
// 0097b308  51                   push ecx
// 0097b309  b880f67500           mov eax, 0x75f680
// 0097b30e  50                   push eax
// 0097b30f  56                   push esi
// 0097b310  ba70f17500           mov edx, 0x75f170
// 0097b315  52                   push edx
// 0097b316  68dc1f9d00           push 0x9d1fdc
// 0097b31b  68b8409a00           push 0x9a40b8
// 0097b320  b90c7ab900           mov ecx, 0xb97a0c
// 0097b325  e8b640deff           call 0x75f3e0
// 0097b32a  6890989800           push 0x989890
// 0097b32f  e8f595e7ff           call 0x7f4929
// 0097b334  83c404               add esp, 4
// 0097b337  5e                   pop esi
// 0097b338  c3                   ret 

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

static Desc desc("Color", "Appearance", &Owner::m0, &Owner::m1, 15, 0);
