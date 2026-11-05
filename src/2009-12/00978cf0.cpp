// from server: 100% by nuck16
// roc 2009-12 00978cf0  unit: seg_00970000  size: 57 bytes
//
// 00978cf0  56                   push esi
// 00978cf1  33f6                 xor esi, esi
// 00978cf3  56                   push esi
// 00978cf4  6a0f                 push 0xf
// 00978cf6  33c9                 xor ecx, ecx
// 00978cf8  51                   push ecx
// 00978cf9  b8a0e17100           mov eax, 0x71e1a0
// 00978cfe  50                   push eax
// 00978cff  56                   push esi
// 00978d00  baf08f5c00           mov edx, 0x5c8ff0
// 00978d05  52                   push edx
// 00978d06  6884b09b00           push 0x9bb084
// 00978d0b  68b0fc9d00           push 0x9dfcb0
// 00978d10  b9245bb900           mov ecx, 0xb95b24
// 00978d15  e88650daff           call 0x71dda0
// 00978d1a  6800809800           push 0x988000
// 00978d1f  e805bce7ff           call 0x7f4929
// 00978d24  83c404               add esp, 4
// 00978d27  5e                   pop esi
// 00978d28  c3                   ret 

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

static Desc desc("VertexColor", "Data", &Owner::m0, &Owner::m1, 15, 0);
