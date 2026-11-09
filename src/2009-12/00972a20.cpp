// from server: 100% by nuck16
// roc 2009-12 00972a20  unit: seg_00970000  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00972a20
//
// 00972a20  6a01                 push 1
// 00972a22  33c9                 xor ecx, ecx
// 00972a24  6880f39c00           push 0x9cf380
// 00972a29  51                   push ecx
// 00972a2a  b810536600           mov eax, 0x665310
// 00972a2f  50                   push eax
// 00972a30  b9a004b900           mov ecx, 0xb904a0
// 00972a35  e856bfcfff           call 0x66e990
// 00972a3a  68004a9800           push 0x984a00
// 00972a3f  e8e51ee8ff           call 0x7f4929
// 00972a44  59                   pop ecx
// 00972a45  c3                   ret 

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

static Desc desc(&Owner::m0, "SetMessageBrickCount", 1);
