// from server: 100% by nuck16
// roc 2009-12 00972610  unit: seg_00970000  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00972610
//
// 00972610  33c9                 xor ecx, ecx
// 00972612  51                   push ecx
// 00972613  68e01d9b00           push 0x9b1de0
// 00972618  68a8e79c00           push 0x9ce7a8
// 0097261d  51                   push ecx
// 0097261e  b8c0476600           mov eax, 0x6647c0
// 00972623  50                   push eax
// 00972624  b9e802b900           mov ecx, 0xb902e8
// 00972629  e80225cfff           call 0x664b30
// 0097262e  6820489800           push 0x984820
// 00972633  e8f122e8ff           call 0x7f4929
// 00972638  59                   pop ecx
// 00972639  c3                   ret 

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

static Desc desc(&Owner::m0, "GetService", "name", 0);
