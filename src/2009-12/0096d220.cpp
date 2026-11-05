// from server: 100% by nuck16
// roc 2009-12 0096d220  unit: seg_00960000  size: 57 bytes
//
// 0096d220  56                   push esi
// 0096d221  33f6                 xor esi, esi
// 0096d223  56                   push esi
// 0096d224  6a0f                 push 0xf
// 0096d226  33c9                 xor ecx, ecx
// 0096d228  51                   push ecx
// 0096d229  b8909b5200           mov eax, 0x529b90
// 0096d22e  50                   push eax
// 0096d22f  56                   push esi
// 0096d230  ba908a5200           mov edx, 0x528a90
// 0096d235  52                   push edx
// 0096d236  680cc69b00           push 0x9bc60c
// 0096d23b  6840c69b00           push 0x9bc640
// 0096d240  b91000b800           mov ecx, 0xb80010
// 0096d245  e876c3bbff           call 0x5295c0
// 0096d24a  6870029800           push 0x980270
// 0096d24f  e8d576e8ff           call 0x7f4929
// 0096d254  83c404               add esp, 4
// 0096d257  5e                   pop esi
// 0096d258  c3                   ret 

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

static Desc desc("PhysicsMtuAdjust", "Physics", &Owner::m0, &Owner::m1, 15, 0);
