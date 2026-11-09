// from server: 100% by nuck16
// roc 2009-12 00974a00  unit: seg_00970000  size: 57 bytes
//
// 00974a00  56                   push esi
// 00974a01  33f6                 xor esi, esi
// 00974a03  56                   push esi
// 00974a04  6a0f                 push 0xf
// 00974a06  33c9                 xor ecx, ecx
// 00974a08  51                   push ecx
// 00974a09  b840616c00           mov eax, 0x6c6140
// 00974a0e  50                   push eax
// 00974a0f  56                   push esi
// 00974a10  bac05c6c00           mov edx, 0x6c5cc0
// 00974a15  52                   push edx
// 00974a16  6810719d00           push 0x9d7110
// 00974a1b  68a8719d00           push 0x9d71a8
// 00974a20  b9b823b900           mov ecx, 0xb923b8
// 00974a25  e87614d5ff           call 0x6c5ea0
// 00974a2a  68a05a9800           push 0x985aa0
// 00974a2f  e8f5fee7ff           call 0x7f4929
// 00974a34  83c404               add esp, 4
// 00974a37  5e                   pop esi
// 00974a38  c3                   ret 

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

static Desc desc("IsReceiveAgeShown", "Display", &Owner::m0, &Owner::m1, 15, 0);
