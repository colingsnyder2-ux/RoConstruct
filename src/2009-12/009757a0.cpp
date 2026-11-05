// from server: 100% by nuck16
// roc 2009-12 009757a0  unit: seg_00970000  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009757a0
//
// 009757a0  6a04                 push 4
// 009757a2  33c9                 xor ecx, ecx
// 009757a4  68f8809d00           push 0x9d80f8
// 009757a9  51                   push ecx
// 009757aa  b8404c4500           mov eax, 0x454c40
// 009757af  50                   push eax
// 009757b0  b9f02bb900           mov ecx, 0xb92bf0
// 009757b5  e8b6dcd5ff           call 0x6d3470
// 009757ba  6850619800           push 0x986150
// 009757bf  e865f1e7ff           call 0x7f4929
// 009757c4  59                   pop ecx
// 009757c5  c3                   ret 

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

static Desc desc(&Owner::m0, "GetUploadUrl", 4);
