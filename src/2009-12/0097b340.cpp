// from server: 100% by nuck16
// roc 2009-12 0097b340  unit: seg_00970000  size: 57 bytes
//
// 0097b340  56                   push esi
// 0097b341  33f6                 xor esi, esi
// 0097b343  56                   push esi
// 0097b344  6a0f                 push 0xf
// 0097b346  33c9                 xor ecx, ecx
// 0097b348  51                   push ecx
// 0097b349  b8a0f67500           mov eax, 0x75f6a0
// 0097b34e  50                   push eax
// 0097b34f  56                   push esi
// 0097b350  ba00004c00           mov edx, 0x4c0000
// 0097b355  52                   push edx
// 0097b356  68dc1f9d00           push 0x9d1fdc
// 0097b35b  68ec7e9d00           push 0x9d7eec
// 0097b360  b9c479b900           mov ecx, 0xb979c4
// 0097b365  e82641deff           call 0x75f490
// 0097b36a  6870989800           push 0x989870
// 0097b36f  e8b595e7ff           call 0x7f4929
// 0097b374  83c404               add esp, 4
// 0097b377  5e                   pop esi
// 0097b378  c3                   ret 

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

static Desc desc("Transparency", "Appearance", &Owner::m0, &Owner::m1, 15, 0);
