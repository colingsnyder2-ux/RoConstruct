// from server: 100% by nuck16
// roc 2009-12 00974800  unit: seg_00970000  size: 57 bytes
//
// 00974800  56                   push esi
// 00974801  33f6                 xor esi, esi
// 00974803  56                   push esi
// 00974804  6a0f                 push 0xf
// 00974806  33c9                 xor ecx, ecx
// 00974808  51                   push ecx
// 00974809  b8c05f6c00           mov eax, 0x6c5fc0
// 0097480e  50                   push eax
// 0097480f  56                   push esi
// 00974810  ba405c6c00           mov edx, 0x6c5c40
// 00974815  52                   push edx
// 00974816  6810719d00           push 0x9d7110
// 0097481b  6800719d00           push 0x9d7100
// 00974820  b99823b900           mov ecx, 0xb92398
// 00974825  e87616d5ff           call 0x6c5ea0
// 0097482a  68605b9800           push 0x985b60
// 0097482f  e8f500e8ff           call 0x7f4929
// 00974834  83c404               add esp, 4
// 00974837  5e                   pop esi
// 00974838  c3                   ret 

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

static Desc desc("AreAnchorsShown", "Display", &Owner::m0, &Owner::m1, 15, 0);
