// from server: 100% by nuck16
// roc 2009-12 009757d0  unit: seg_00970000  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009757d0
//
// 009757d0  6a04                 push 4
// 009757d2  6818819d00           push 0x9d8118
// 009757d7  6810819d00           push 0x9d8110
// 009757dc  33c9                 xor ecx, ecx
// 009757de  6808819d00           push 0x9d8108
// 009757e3  51                   push ecx
// 009757e4  b8e0386d00           mov eax, 0x6d38e0
// 009757e9  50                   push eax
// 009757ea  b9982bb900           mov ecx, 0xb92b98
// 009757ef  e85cddd5ff           call 0x6d3550
// 009757f4  6890619800           push 0x986190
// 009757f9  e82bf1e7ff           call 0x7f4929
// 009757fe  59                   pop ecx
// 009757ff  c3                   ret 

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
    Desc(void (Owner::*)(), const char *, const char *, const char *, int);
    ~Desc();
};

static Desc desc(&Owner::m0, "SetPing", "pingUrl", "interval", 4);
