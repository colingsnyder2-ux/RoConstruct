// from server: 100% by nuck16
// roc 2009-12 0096f010  unit: seg_00960000  size: 57 bytes
//
// 0096f010  56                   push esi
// 0096f011  33f6                 xor esi, esi
// 0096f013  56                   push esi
// 0096f014  6a0f                 push 0xf
// 0096f016  33c9                 xor ecx, ecx
// 0096f018  51                   push ecx
// 0096f019  b870d96300           mov eax, 0x63d970
// 0096f01e  50                   push eax
// 0096f01f  56                   push esi
// 0096f020  baa0d26300           mov edx, 0x63d2a0
// 0096f025  52                   push edx
// 0096f026  6884b09b00           push 0x9bb084
// 0096f02b  68d0c59c00           push 0x9cc5d0
// 0096f030  b9cc5ab800           mov ecx, 0xb85acc
// 0096f035  e846e6ccff           call 0x63d680
// 0096f03a  68e01c9800           push 0x981ce0
// 0096f03f  e8e558e8ff           call 0x7f4929
// 0096f044  83c404               add esp, 4
// 0096f047  5e                   pop esi
// 0096f048  c3                   ret 

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

static Desc desc("AutoAssignable", "Data", &Owner::m0, &Owner::m1, 15, 0);
