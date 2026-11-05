// from server: 100% by nuck16
// roc 2009-12 00972960  unit: seg_00970000  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00972960
//
// 00972960  6a01                 push 1
// 00972962  33c9                 xor ecx, ecx
// 00972964  6854f39c00           push 0x9cf354
// 00972969  51                   push ecx
// 0097296a  b800056700           mov eax, 0x670500
// 0097296f  50                   push eax
// 00972970  b9e004b900           mov ecx, 0xb904e0
// 00972975  e816c0cfff           call 0x66e990
// 0097297a  6830499800           push 0x984930
// 0097297f  e8a51fe8ff           call 0x7f4929
// 00972984  59                   pop ecx
// 00972985  c3                   ret 

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

static Desc desc(&Owner::m0, "ClearContent", 1);
