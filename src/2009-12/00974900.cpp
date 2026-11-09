// from server: 100% by nuck16
// roc 2009-12 00974900  unit: seg_00970000  size: 57 bytes
//
// 00974900  56                   push esi
// 00974901  33f6                 xor esi, esi
// 00974903  56                   push esi
// 00974904  6a0f                 push 0xf
// 00974906  33c9                 xor ecx, ecx
// 00974908  51                   push ecx
// 00974909  b880606c00           mov eax, 0x6c6080
// 0097490e  50                   push eax
// 0097490f  56                   push esi
// 00974910  ba805c6c00           mov edx, 0x6c5c80
// 00974915  52                   push edx
// 00974916  6810719d00           push 0x9d7110
// 0097491b  6858719d00           push 0x9d7158
// 00974920  b9fc23b900           mov ecx, 0xb923fc
// 00974925  e87615d5ff           call 0x6c5ea0
// 0097492a  68205a9800           push 0x985a20
// 0097492f  e8f5ffe7ff           call 0x7f4929
// 00974934  83c404               add esp, 4
// 00974937  5e                   pop esi
// 00974938  c3                   ret 

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

static Desc desc("AreWorldCoordsShown", "Display", &Owner::m0, &Owner::m1, 15, 0);
