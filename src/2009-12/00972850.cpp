// from server: 100% by nuck16
// roc 2009-12 00972850  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00972850
//
// 00972850  6a01                 push 1
// 00972852  689cb19b00           push 0x9bb19c
// 00972857  33c9                 xor ecx, ecx
// 00972859  6808f39c00           push 0x9cf308
// 0097285e  51                   push ecx
// 0097285f  b870546600           mov eax, 0x665470
// 00972864  50                   push eax
// 00972865  b9b006b900           mov ecx, 0xb906b0
// 0097286a  e891bfcfff           call 0x66e800
// 0097286f  68004b9800           push 0x984b00
// 00972874  e8b020e8ff           call 0x7f4929
// 00972879  59                   pop ecx
// 0097287a  c3                   ret 

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

static Desc desc(&Owner::m0, "SetServerSaveUrl", "url", 1);
