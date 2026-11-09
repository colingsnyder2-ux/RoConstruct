// from server: 100% by nuck16
// roc 2009-12 00975830  unit: seg_00970000  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00975830
//
// 00975830  6a01                 push 1
// 00975832  33c9                 xor ecx, ecx
// 00975834  6864959d00           push 0x9d9564
// 00975839  51                   push ecx
// 0097583a  b8607a6d00           mov eax, 0x6d7a60
// 0097583f  50                   push eax
// 00975840  b9f830b900           mov ecx, 0xb930f8
// 00975845  e8d62cd6ff           call 0x6d8520
// 0097584a  6840629800           push 0x986240
// 0097584f  e8d5f0e7ff           call 0x7f4929
// 00975854  59                   pop ecx
// 00975855  c3                   ret 

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

static Desc desc(&Owner::m0, "GetValue", 1);
