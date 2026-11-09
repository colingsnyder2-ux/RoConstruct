// from server: 100% by nuck16
// roc 2009-12 00975af0  unit: seg_00970000  size: 57 bytes
//
// 00975af0  56                   push esi
// 00975af1  33f6                 xor esi, esi
// 00975af3  56                   push esi
// 00975af4  6a0f                 push 0xf
// 00975af6  33c9                 xor ecx, ecx
// 00975af8  51                   push ecx
// 00975af9  b810e06d00           mov eax, 0x6de010
// 00975afe  50                   push eax
// 00975aff  56                   push esi
// 00975b00  bad01a4600           mov edx, 0x461ad0
// 00975b05  52                   push edx
// 00975b06  6884b09b00           push 0x9bb084
// 00975b0b  6824799d00           push 0x9d7924
// 00975b10  b94033b900           mov ecx, 0xb93340
// 00975b15  e89675d6ff           call 0x6dd0b0
// 00975b1a  68d0639800           push 0x9863d0
// 00975b1f  e805eee7ff           call 0x7f4929
// 00975b24  83c404               add esp, 4
// 00975b27  5e                   pop esi
// 00975b28  c3                   ret 

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

static Desc desc("CoordinateFrame", "Data", &Owner::m0, &Owner::m1, 15, 0);
