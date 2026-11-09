// from server: 100% by nuck16
// roc 2009-12 00979c60  unit: seg_00970000  size: 57 bytes
//
// 00979c60  56                   push esi
// 00979c61  33f6                 xor esi, esi
// 00979c63  56                   push esi
// 00979c64  6a0f                 push 0xf
// 00979c66  33c9                 xor ecx, ecx
// 00979c68  51                   push ecx
// 00979c69  b8e0d47300           mov eax, 0x73d4e0
// 00979c6e  50                   push eax
// 00979c6f  56                   push esi
// 00979c70  ba20b77300           mov edx, 0x73b720
// 00979c75  52                   push edx
// 00979c76  6884b09b00           push 0x9bb084
// 00979c7b  6840e09b00           push 0x9be040
// 00979c80  b99c67b900           mov ecx, 0xb9679c
// 00979c85  e86635dcff           call 0x73d1f0
// 00979c8a  68608b9800           push 0x988b60
// 00979c8f  e895ace7ff           call 0x7f4929
// 00979c94  83c404               add esp, 4
// 00979c97  5e                   pop esi
// 00979c98  c3                   ret 

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

static Desc desc("Size", "Data", &Owner::m0, &Owner::m1, 15, 0);
