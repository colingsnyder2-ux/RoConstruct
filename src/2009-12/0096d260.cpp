// from server: 100% by nuck16
// roc 2009-12 0096d260  unit: seg_00960000  size: 57 bytes
//
// 0096d260  56                   push esi
// 0096d261  33f6                 xor esi, esi
// 0096d263  56                   push esi
// 0096d264  6a0f                 push 0xf
// 0096d266  33c9                 xor ecx, ecx
// 0096d268  51                   push ecx
// 0096d269  b8e09b5200           mov eax, 0x529be0
// 0096d26e  50                   push eax
// 0096d26f  56                   push esi
// 0096d270  bae0488600           mov edx, 0x8648e0
// 0096d275  52                   push edx
// 0096d276  6864c69b00           push 0x9bc664
// 0096d27b  6854c69b00           push 0x9bc654
// 0096d280  b9d0ffb700           mov ecx, 0xb7ffd0
// 0096d285  e836c3bbff           call 0x5295c0
// 0096d28a  6850029800           push 0x980250
// 0096d28f  e89576e8ff           call 0x7f4929
// 0096d294  83c404               add esp, 4
// 0096d297  5e                   pop esi
// 0096d298  c3                   ret 

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

static Desc desc("DataMtuAdjust", "Replication", &Owner::m0, &Owner::m1, 15, 0);
