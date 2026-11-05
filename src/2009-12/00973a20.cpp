// from server: 100% by nuck16
// roc 2009-12 00973a20  unit: seg_00970000  size: 57 bytes
//
// 00973a20  56                   push esi
// 00973a21  33f6                 xor esi, esi
// 00973a23  56                   push esi
// 00973a24  6a02                 push 2
// 00973a26  33c9                 xor ecx, ecx
// 00973a28  51                   push ecx
// 00973a29  b850506900           mov eax, 0x695050
// 00973a2e  50                   push eax
// 00973a2f  56                   push esi
// 00973a30  ba60967f00           mov edx, 0x7f9660
// 00973a35  52                   push edx
// 00973a36  68dc1f9d00           push 0x9d1fdc
// 00973a3b  68c81b9d00           push 0x9d1bc8
// 00973a40  b99813b900           mov ecx, 0xb91398
// 00973a45  e8d6fed1ff           call 0x693920
// 00973a4a  68c0519800           push 0x9851c0
// 00973a4f  e8d50ee8ff           call 0x7f4929
// 00973a54  83c404               add esp, 4
// 00973a57  5e                   pop esi
// 00973a58  c3                   ret 

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

static Desc desc("ActivationState", "Appearance", &Owner::m0, &Owner::m1, 2, 0);
