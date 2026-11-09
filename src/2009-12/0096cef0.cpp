// from server: 100% by nuck16
// roc 2009-12 0096cef0  unit: seg_00960000  size: 57 bytes
//
// 0096cef0  56                   push esi
// 0096cef1  33f6                 xor esi, esi
// 0096cef3  56                   push esi
// 0096cef4  6a0f                 push 0xf
// 0096cef6  33c9                 xor ecx, ecx
// 0096cef8  51                   push ecx
// 0096cef9  b8f09c5200           mov eax, 0x529cf0
// 0096cefe  50                   push eax
// 0096ceff  56                   push esi
// 0096cf00  bac08a5200           mov edx, 0x528ac0
// 0096cf05  52                   push edx
// 0096cf06  68b8c39b00           push 0x9bc3b8
// 0096cf0b  6804c59b00           push 0x9bc504
// 0096cf10  b9f0ffb700           mov ecx, 0xb7fff0
// 0096cf15  e826c2bbff           call 0x529140
// 0096cf1a  6890029800           push 0x980290
// 0096cf1f  e8057ae8ff           call 0x7f4929
// 0096cf24  83c404               add esp, 4
// 0096cf27  5e                   pop esi
// 0096cf28  c3                   ret 

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

static Desc desc("PhysicsSendRate", "Network", &Owner::m0, &Owner::m1, 15, 0);
