// from server: 100% by nuck16
// roc 2009-12 00972820  unit: seg_00970000  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00972820
//
// 00972820  33c9                 xor ecx, ecx
// 00972822  51                   push ecx
// 00972823  68f4f29c00           push 0x9cf2f4
// 00972828  51                   push ecx
// 00972829  b800546600           mov eax, 0x665400
// 0097282e  50                   push eax
// 0097282f  b9e005b900           mov ecx, 0xb905e0
// 00972834  e8d7becfff           call 0x66e710
// 00972839  68c04a9800           push 0x984ac0
// 0097283e  e8e620e8ff           call 0x7f4929
// 00972843  59                   pop ecx
// 00972844  c3                   ret 

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

static Desc desc(&Owner::m0, "GetRemoteBuildMode", 0);
