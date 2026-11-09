// from server: 100% by nuck16
// roc 2009-12 00974200  unit: seg_00970000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00974200
//
// 00974200  33c9                 xor ecx, ecx
// 00974202  51                   push ecx
// 00974203  6a0f                 push 0xf
// 00974205  51                   push ecx
// 00974206  b8b0996b00           mov eax, 0x6b99b0
// 0097420b  50                   push eax
// 0097420c  68c8000000           push 0xc8
// 00974211  6884b09b00           push 0x9bb084
// 00974216  6818669d00           push 0x9d6618
// 0097421b  b9881bb900           mov ecx, 0xb91b88
// 00974220  e87b22d4ff           call 0x6b64a0
// 00974225  6810569800           push 0x985610
// 0097422a  e8fa06e8ff           call 0x7f4929
// 0097422f  59                   pop ecx
// 00974230  c3                   ret 

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
    Desc(const char *, const char *, int, void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("RolloffScale", "Data", 200, &Owner::m0, 15, 0);
