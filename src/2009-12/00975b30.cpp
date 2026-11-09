// from server: 100% by nuck16
// roc 2009-12 00975b30  unit: seg_00970000  size: 57 bytes
//
// 00975b30  56                   push esi
// 00975b31  33f6                 xor esi, esi
// 00975b33  56                   push esi
// 00975b34  6a0f                 push 0xf
// 00975b36  33c9                 xor ecx, ecx
// 00975b38  51                   push ecx
// 00975b39  b830da6d00           mov eax, 0x6dda30
// 00975b3e  50                   push eax
// 00975b3f  56                   push esi
// 00975b40  bac01a4600           mov edx, 0x461ac0
// 00975b45  52                   push edx
// 00975b46  6884b09b00           push 0x9bb084
// 00975b4b  68989b9d00           push 0x9d9b98
// 00975b50  b9cc32b900           mov ecx, 0xb932cc
// 00975b55  e80676d6ff           call 0x6dd160
// 00975b5a  68b0639800           push 0x9863b0
// 00975b5f  e8c5ede7ff           call 0x7f4929
// 00975b64  83c404               add esp, 4
// 00975b67  5e                   pop esi
// 00975b68  c3                   ret 

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

static Desc desc("Focus", "Data", &Owner::m0, &Owner::m1, 15, 0);
