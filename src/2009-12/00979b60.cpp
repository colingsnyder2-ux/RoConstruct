// from server: 100% by nuck16
// roc 2009-12 00979b60  unit: seg_00970000  size: 57 bytes
//
// 00979b60  56                   push esi
// 00979b61  33f6                 xor esi, esi
// 00979b63  56                   push esi
// 00979b64  6a0f                 push 0xf
// 00979b66  33c9                 xor ecx, ecx
// 00979b68  51                   push ecx
// 00979b69  b8b0d27300           mov eax, 0x73d2b0
// 00979b6e  50                   push eax
// 00979b6f  56                   push esi
// 00979b70  ba10ca7300           mov edx, 0x73ca10
// 00979b75  52                   push edx
// 00979b76  6884b09b00           push 0x9bb084
// 00979b7b  6890229e00           push 0x9e2290
// 00979b80  b9e067b900           mov ecx, 0xb967e0
// 00979b85  e81634dcff           call 0x73cfa0
// 00979b8a  68008b9800           push 0x988b00
// 00979b8f  e895ade7ff           call 0x7f4929
// 00979b94  83c404               add esp, 4
// 00979b97  5e                   pop esi
// 00979b98  c3                   ret 

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

static Desc desc("Adornee", "Data", &Owner::m0, &Owner::m1, 15, 0);
