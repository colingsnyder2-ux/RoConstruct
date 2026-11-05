// from server: 100% by nuck16
// roc 2009-12 00978600  unit: seg_00970000  size: 57 bytes
//
// 00978600  56                   push esi
// 00978601  33f6                 xor esi, esi
// 00978603  56                   push esi
// 00978604  6a0f                 push 0xf
// 00978606  33c9                 xor ecx, ecx
// 00978608  51                   push ecx
// 00978609  b870507100           mov eax, 0x715070
// 0097860e  50                   push eax
// 0097860f  56                   push esi
// 00978610  bae04d5700           mov edx, 0x574de0
// 00978615  52                   push edx
// 00978616  68dc1f9d00           push 0x9d1fdc
// 0097861b  68d8e79d00           push 0x9de7d8
// 00978620  b99455b900           mov ecx, 0xb95594
// 00978625  e8e6bed9ff           call 0x714510
// 0097862a  68407a9800           push 0x987a40
// 0097862f  e8f5c2e7ff           call 0x7f4929
// 00978634  83c404               add esp, 4
// 00978637  5e                   pop esi
// 00978638  c3                   ret 

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

static Desc desc("Ambient", "Appearance", &Owner::m0, &Owner::m1, 15, 0);
