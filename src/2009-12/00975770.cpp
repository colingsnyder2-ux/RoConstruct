// from server: 100% by nuck16
// roc 2009-12 00975770  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00975770
//
// 00975770  6a04                 push 4
// 00975772  689cb19b00           push 0x9bb19c
// 00975777  33c9                 xor ecx, ecx
// 00975779  68e8809d00           push 0x9d80e8
// 0097577e  51                   push ecx
// 0097577f  b8a0276d00           mov eax, 0x6d27a0
// 00975784  50                   push eax
// 00975785  b9502bb900           mov ecx, 0xb92b50
// 0097578a  e851dbd5ff           call 0x6d32e0
// 0097578f  68a0619800           push 0x9861a0
// 00975794  e890f1e7ff           call 0x7f4929
// 00975799  59                   pop ecx
// 0097579a  c3                   ret 

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

static Desc desc(&Owner::m0, "SetUploadUrl", "url", 4);
