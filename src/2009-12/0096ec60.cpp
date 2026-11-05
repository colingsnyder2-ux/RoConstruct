// from server: 100% by nuck16
// roc 2009-12 0096ec60  unit: seg_00960000  size: 57 bytes
//
// 0096ec60  56                   push esi
// 0096ec61  33f6                 xor esi, esi
// 0096ec63  56                   push esi
// 0096ec64  6a0f                 push 0xf
// 0096ec66  33c9                 xor ecx, ecx
// 0096ec68  51                   push ecx
// 0096ec69  b8405d5000           mov eax, 0x505d40
// 0096ec6e  50                   push eax
// 0096ec6f  56                   push esi
// 0096ec70  bae0ab4600           mov edx, 0x46abe0
// 0096ec75  52                   push edx
// 0096ec76  6884b09b00           push 0x9bb084
// 0096ec7b  68c82c9a00           push 0x9a2cc8
// 0096ec80  b9b052b800           mov ecx, 0xb852b0
// 0096ec85  e80655ccff           call 0x634190
// 0096ec8a  68c0179800           push 0x9817c0
// 0096ec8f  e8955ce8ff           call 0x7f4929
// 0096ec94  83c404               add esp, 4
// 0096ec97  5e                   pop esi
// 0096ec98  c3                   ret 

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

static Desc desc("Name", "Data", &Owner::m0, &Owner::m1, 15, 0);
