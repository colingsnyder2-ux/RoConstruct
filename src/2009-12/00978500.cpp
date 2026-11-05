// from server: 100% by nuck16
// roc 2009-12 00978500  unit: seg_00970000  size: 57 bytes
//
// 00978500  56                   push esi
// 00978501  33f6                 xor esi, esi
// 00978503  56                   push esi
// 00978504  6a0f                 push 0xf
// 00978506  33c9                 xor ecx, ecx
// 00978508  51                   push ecx
// 00978509  b800517100           mov eax, 0x715100
// 0097850e  50                   push eax
// 0097850f  56                   push esi
// 00978510  ba60317100           mov edx, 0x713160
// 00978515  52                   push edx
// 00978516  68dc1f9d00           push 0x9d1fdc
// 0097851b  689ce79d00           push 0x9de79c
// 00978520  b97455b900           mov ecx, 0xb95574
// 00978525  e8e6bfd9ff           call 0x714510
// 0097852a  68a07a9800           push 0x987aa0
// 0097852f  e8f5c3e7ff           call 0x7f4929
// 00978534  83c404               add esp, 4
// 00978537  5e                   pop esi
// 00978538  c3                   ret 

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

static Desc desc("ShadowColor", "Appearance", &Owner::m0, &Owner::m1, 15, 0);
