// from server: 100% by nuck16
// roc 2009-12 0096bb20  unit: seg_00960000  size: 57 bytes
//
// 0096bb20  56                   push esi
// 0096bb21  33f6                 xor esi, esi
// 0096bb23  56                   push esi
// 0096bb24  6a0f                 push 0xf
// 0096bb26  33c9                 xor ecx, ecx
// 0096bb28  51                   push ecx
// 0096bb29  b800b15000           mov eax, 0x50b100
// 0096bb2e  50                   push eax
// 0096bb2f  56                   push esi
// 0096bb30  bab0524f00           mov edx, 0x4f52b0
// 0096bb35  52                   push edx
// 0096bb36  6884b09b00           push 0x9bb084
// 0096bb3b  688cb09b00           push 0x9bb08c
// 0096bb40  b9e8e7b700           mov ecx, 0xb7e7e8
// 0096bb45  e87645b9ff           call 0x5000c0
// 0096bb4a  6840f39700           push 0x97f340
// 0096bb4f  e8d58de8ff           call 0x7f4929
// 0096bb54  83c404               add esp, 4
// 0096bb57  5e                   pop esi
// 0096bb58  c3                   ret 

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

static Desc desc("CharacterAppearance", "Data", &Owner::m0, &Owner::m1, 15, 0);
