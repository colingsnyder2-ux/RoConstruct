// from server: 100% by nuck16
// roc 2009-12 009798d0  unit: seg_00970000  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009798d0
//
// 009798d0  33c9                 xor ecx, ecx
// 009798d2  51                   push ecx
// 009798d3  68f01c9e00           push 0x9e1cf0
// 009798d8  51                   push ecx
// 009798d9  b8f0537300           mov eax, 0x7353f0
// 009798de  50                   push eax
// 009798df  b91866b900           mov ecx, 0xb96618
// 009798e4  e8f706dcff           call 0x739fe0
// 009798e9  68f0889800           push 0x9888f0
// 009798ee  e836b0e7ff           call 0x7f4929
// 009798f3  59                   pop ecx
// 009798f4  c3                   ret 

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

static Desc desc(&Owner::m0, "GetLastForce", 0);
