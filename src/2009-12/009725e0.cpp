// from server: 100% by nuck16
// roc 2009-12 009725e0  unit: seg_00970000  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009725e0
//
// 009725e0  33c9                 xor ecx, ecx
// 009725e2  51                   push ecx
// 009725e3  68e01d9b00           push 0x9b1de0
// 009725e8  68a0e79c00           push 0x9ce7a0
// 009725ed  51                   push ecx
// 009725ee  b8c0476600           mov eax, 0x6647c0
// 009725f3  50                   push eax
// 009725f4  b93003b900           mov ecx, 0xb90330
// 009725f9  e83225cfff           call 0x664b30
// 009725fe  6870489800           push 0x984870
// 00972603  e82123e8ff           call 0x7f4929
// 00972608  59                   pop ecx
// 00972609  c3                   ret 

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

static Desc desc(&Owner::m0, "service", "name", 0);
