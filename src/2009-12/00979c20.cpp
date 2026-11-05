// from server: 100% by nuck16
// roc 2009-12 00979c20  unit: seg_00970000  size: 57 bytes
//
// 00979c20  56                   push esi
// 00979c21  33f6                 xor esi, esi
// 00979c23  56                   push esi
// 00979c24  6a0f                 push 0xf
// 00979c26  33c9                 xor ecx, ecx
// 00979c28  51                   push ecx
// 00979c29  b890d47300           mov eax, 0x73d490
// 00979c2e  50                   push eax
// 00979c2f  56                   push esi
// 00979c30  ba10b77300           mov edx, 0x73b710
// 00979c35  52                   push edx
// 00979c36  6884b09b00           push 0x9bb084
// 00979c3b  68b4229e00           push 0x9e22b4
// 00979c40  b95c67b900           mov ecx, 0xb9675c
// 00979c45  e8f634dcff           call 0x73d140
// 00979c4a  68808b9800           push 0x988b80
// 00979c4f  e8d5ace7ff           call 0x7f4929
// 00979c54  83c404               add esp, 4
// 00979c57  5e                   pop esi
// 00979c58  c3                   ret 

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

static Desc desc("SizeOffset", "Data", &Owner::m0, &Owner::m1, 15, 0);
