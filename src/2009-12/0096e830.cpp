// from server: 100% by nuck16
// roc 2009-12 0096e830  unit: seg_00960000  size: 57 bytes
//
// 0096e830  56                   push esi
// 0096e831  33f6                 xor esi, esi
// 0096e833  56                   push esi
// 0096e834  6a0f                 push 0xf
// 0096e836  33c9                 xor ecx, ecx
// 0096e838  51                   push ecx
// 0096e839  b830bd6200           mov eax, 0x62bd30
// 0096e83e  50                   push eax
// 0096e83f  56                   push esi
// 0096e840  ba20bd6200           mov edx, 0x62bd20
// 0096e845  52                   push edx
// 0096e846  6820a79b00           push 0x9ba720
// 0096e84b  68d4bb9c00           push 0x9cbbd4
// 0096e850  b98050b800           mov ecx, 0xb85080
// 0096e855  e8d606ccff           call 0x62ef30
// 0096e85a  6840149800           push 0x981440
// 0096e85f  e8c560e8ff           call 0x7f4929
// 0096e864  83c404               add esp, 4
// 0096e867  5e                   pop esi
// 0096e868  c3                   ret 

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

static Desc desc("AreArbitersThrottled", "Configuration", &Owner::m0, &Owner::m1, 15, 0);
