// from server: 100% by nuck16
// roc 2009-12 00979be0  unit: seg_00970000  size: 57 bytes
//
// 00979be0  56                   push esi
// 00979be1  33f6                 xor esi, esi
// 00979be3  56                   push esi
// 00979be4  6a0f                 push 0xf
// 00979be6  33c9                 xor ecx, ecx
// 00979be8  51                   push ecx
// 00979be9  b820d47300           mov eax, 0x73d420
// 00979bee  50                   push eax
// 00979bef  56                   push esi
// 00979bf0  ba00b77300           mov edx, 0x73b700
// 00979bf5  52                   push edx
// 00979bf6  6884b09b00           push 0x9bb084
// 00979bfb  68a4229e00           push 0x9e22a4
// 00979c00  b97c67b900           mov ecx, 0xb9677c
// 00979c05  e88634dcff           call 0x73d090
// 00979c0a  68208b9800           push 0x988b20
// 00979c0f  e815ade7ff           call 0x7f4929
// 00979c14  83c404               add esp, 4
// 00979c17  5e                   pop esi
// 00979c18  c3                   ret 

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

static Desc desc("ExtentsOffset", "Data", &Owner::m0, &Owner::m1, 15, 0);
