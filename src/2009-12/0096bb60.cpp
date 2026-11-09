// from server: 100% by nuck16
// roc 2009-12 0096bb60  unit: seg_00960000  size: 57 bytes
//
// 0096bb60  56                   push esi
// 0096bb61  33f6                 xor esi, esi
// 0096bb63  56                   push esi
// 0096bb64  6a0f                 push 0xf
// 0096bb66  33c9                 xor ecx, ecx
// 0096bb68  51                   push ecx
// 0096bb69  b800b85000           mov eax, 0x50b800
// 0096bb6e  50                   push eax
// 0096bb6f  56                   push esi
// 0096bb70  ba60684700           mov edx, 0x476860
// 0096bb75  52                   push edx
// 0096bb76  6884b09b00           push 0x9bb084
// 0096bb7b  68a0b09b00           push 0x9bb0a0
// 0096bb80  b9e8e4b700           mov ecx, 0xb7e4e8
// 0096bb85  e8e645b9ff           call 0x500170
// 0096bb8a  6820f39700           push 0x97f320
// 0096bb8f  e8958de8ff           call 0x7f4929
// 0096bb94  83c404               add esp, 4
// 0096bb97  5e                   pop esi
// 0096bb98  c3                   ret 

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

static Desc desc("userId", "Data", &Owner::m0, &Owner::m1, 15, 0);
