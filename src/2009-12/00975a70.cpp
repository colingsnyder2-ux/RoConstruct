// from server: 100% by nuck16
// roc 2009-12 00975a70  unit: seg_00970000  size: 57 bytes
//
// 00975a70  56                   push esi
// 00975a71  33f6                 xor esi, esi
// 00975a73  56                   push esi
// 00975a74  6a02                 push 2
// 00975a76  33c9                 xor ecx, ecx
// 00975a78  51                   push ecx
// 00975a79  b8f0bb6d00           mov eax, 0x6dbbf0
// 00975a7e  50                   push eax
// 00975a7f  56                   push esi
// 00975a80  ba00a96d00           mov edx, 0x6da900
// 00975a85  52                   push edx
// 00975a86  6884b09b00           push 0x9bb084
// 00975a8b  68a09b9d00           push 0x9d9ba0
// 00975a90  b91032b900           mov ecx, 0xb93210
// 00975a95  e86653d6ff           call 0x6dae00
// 00975a9a  6810639800           push 0x986310
// 00975a9f  e885eee7ff           call 0x7f4929
// 00975aa4  83c404               add esp, 4
// 00975aa7  5e                   pop esi
// 00975aa8  c3                   ret 

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

static Desc desc("EnableReplication", "Data", &Owner::m0, &Owner::m1, 2, 0);
