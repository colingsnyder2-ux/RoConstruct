// from server: 100% by nuck16
// roc 2009-12 00974c60  unit: seg_00970000  size: 57 bytes
//
// 00974c60  56                   push esi
// 00974c61  33f6                 xor esi, esi
// 00974c63  56                   push esi
// 00974c64  6a0f                 push 0xf
// 00974c66  33c9                 xor ecx, ecx
// 00974c68  51                   push ecx
// 00974c69  b870926c00           mov eax, 0x6c9270
// 00974c6e  50                   push eax
// 00974c6f  56                   push esi
// 00974c70  bae0396b00           mov edx, 0x6b39e0
// 00974c75  52                   push edx
// 00974c76  6884b09b00           push 0x9bb084
// 00974c7b  68c8769d00           push 0x9d76c8
// 00974c80  b96c25b900           mov ecx, 0xb9256c
// 00974c85  e8f632d5ff           call 0x6c7f80
// 00974c8a  68905c9800           push 0x985c90
// 00974c8f  e895fce7ff           call 0x7f4929
// 00974c94  83c404               add esp, 4
// 00974c97  5e                   pop esi
// 00974c98  c3                   ret 

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

static Desc desc("BlastRadius", "Data", &Owner::m0, &Owner::m1, 15, 0);
