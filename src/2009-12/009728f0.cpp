// from server: 100% by nuck16
// roc 2009-12 009728f0  unit: seg_00970000  size: 54 bytes
//
// 009728f0  6a04                 push 4
// 009728f2  33c9                 xor ecx, ecx
// 009728f4  51                   push ecx
// 009728f5  6830f39c00           push 0x9cf330
// 009728fa  682c1e9c00           push 0x9c1e2c
// 009728ff  689cb19b00           push 0x9bb19c
// 00972904  683cf39c00           push 0x9cf33c
// 00972909  51                   push ecx
// 0097290a  b8a0236700           mov eax, 0x6723a0
// 0097290f  50                   push eax
// 00972910  b91809b900           mov ecx, 0xb90918
// 00972915  e8f6c3cfff           call 0x66ed10
// 0097291a  68604b9800           push 0x984b60
// 0097291f  e80520e8ff           call 0x7f4929
// 00972924  59                   pop ecx
// 00972925  c3                   ret 

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
    Desc(void (Owner::*)(), const char *, const char *, const char *, const char *, int, int);
    ~Desc();
};

static Desc desc(&Owner::m0, "HttpPost", "url", "data", "synchronous", 0, 4);
