// from server: 100% by nuck16
// roc 2009-12 00975a30  unit: seg_00970000  size: 57 bytes
//
// 00975a30  56                   push esi
// 00975a31  33f6                 xor esi, esi
// 00975a33  56                   push esi
// 00975a34  6a02                 push 2
// 00975a36  33c9                 xor ecx, ecx
// 00975a38  51                   push ecx
// 00975a39  b800b86d00           mov eax, 0x6db800
// 00975a3e  50                   push eax
// 00975a3f  56                   push esi
// 00975a40  baf0a86d00           mov edx, 0x6da8f0
// 00975a45  52                   push edx
// 00975a46  6884b09b00           push 0x9bb084
// 00975a4b  68989b9d00           push 0x9d9b98
// 00975a50  b9f031b900           mov ecx, 0xb931f0
// 00975a55  e8f652d6ff           call 0x6dad50
// 00975a5a  6830639800           push 0x986330
// 00975a5f  e8c5eee7ff           call 0x7f4929
// 00975a64  83c404               add esp, 4
// 00975a67  5e                   pop esi
// 00975a68  c3                   ret 

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

static Desc desc("Focus", "Data", &Owner::m0, &Owner::m1, 2, 0);
