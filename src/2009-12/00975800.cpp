// from server: 100% by nuck16
// roc 2009-12 00975800  unit: seg_00970000  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00975800
//
// 00975800  6a01                 push 1
// 00975802  33c9                 xor ecx, ecx
// 00975804  6854959d00           push 0x9d9554
// 00975809  51                   push ecx
// 0097580a  b8807a6d00           mov eax, 0x6d7a80
// 0097580f  50                   push eax
// 00975810  b9b830b900           mov ecx, 0xb930b8
// 00975815  e8262cd6ff           call 0x6d8440
// 0097581a  6890629800           push 0x986290
// 0097581f  e805f1e7ff           call 0x7f4929
// 00975824  59                   pop ecx
// 00975825  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

struct Desc
{
    Desc(void (Owner::*)(), const char *, int);
    ~Desc();
};

static Desc desc(&Owner::m0, "GetValueString", 1);
