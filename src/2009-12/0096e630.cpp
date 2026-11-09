// from server: 100% by nuck16
// roc 2009-12 0096e630  unit: seg_00960000  size: 57 bytes
//
// 0096e630  56                   push esi
// 0096e631  33f6                 xor esi, esi
// 0096e633  56                   push esi
// 0096e634  6a0f                 push 0xf
// 0096e636  33c9                 xor ecx, ecx
// 0096e638  51                   push ecx
// 0096e639  b820186300           mov eax, 0x631820
// 0096e63e  50                   push eax
// 0096e63f  56                   push esi
// 0096e640  ba50b04400           mov edx, 0x44b050
// 0096e645  52                   push edx
// 0096e646  6858bb9c00           push 0x9cbb58
// 0096e64b  6818b49c00           push 0x9cb418
// 0096e650  b9d04eb800           mov ecx, 0xb84ed0
// 0096e655  e8d632ccff           call 0x631930
// 0096e65a  68a0139800           push 0x9813a0
// 0096e65f  e8c562e8ff           call 0x7f4929
// 0096e664  83c404               add esp, 4
// 0096e667  5e                   pop esi
// 0096e668  c3                   ret 

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

static Desc desc("ErrorReporting", "Errors", &Owner::m0, &Owner::m1, 15, 0);
