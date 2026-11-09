// from server: 100% by nuck16
// roc 2009-12 00972790  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00972790
//
// 00972790  6a01                 push 1
// 00972792  689cb19b00           push 0x9bb19c
// 00972797  33c9                 xor ecx, ecx
// 00972799  68bcf29c00           push 0x9cf2bc
// 0097279e  51                   push ecx
// 0097279f  b8d0006700           mov eax, 0x6700d0
// 009727a4  50                   push eax
// 009727a5  b9f806b900           mov ecx, 0xb906f8
// 009727aa  e831bccfff           call 0x66e3e0
// 009727af  68a04a9800           push 0x984aa0
// 009727b4  e87021e8ff           call 0x7f4929
// 009727b9  59                   pop ecx
// 009727ba  c3                   ret 

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
    Desc(void (Owner::*)(), const char *, const char *, int);
    ~Desc();
};

static Desc desc(&Owner::m0, "Load", "url", 1);
