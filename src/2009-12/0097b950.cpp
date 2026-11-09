// from server: 100% by nuck16
// roc 2009-12 0097b950  unit: seg_00970000  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097b950
//
// 0097b950  33c9                 xor ecx, ecx
// 0097b952  51                   push ecx
// 0097b953  6a0f                 push 0xf
// 0097b955  51                   push ecx
// 0097b956  51                   push ecx
// 0097b957  b8b0b87600           mov eax, 0x76b8b0
// 0097b95c  50                   push eax
// 0097b95d  6884b09b00           push 0x9bb084
// 0097b962  68f0769d00           push 0x9d76f0
// 0097b967  b90482b900           mov ecx, 0xb98204
// 0097b96c  e81f03dfff           call 0x76bc90
// 0097b971  68b09a9800           push 0x989ab0
// 0097b976  e8ae8fe7ff           call 0x7f4929
// 0097b97b  59                   pop ecx
// 0097b97c  c3                   ret 

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
    Desc(const char *, const char *, void (Owner::*)(), int, int, int);
    ~Desc();
};

static Desc desc("Hit", "Data", &Owner::m0, 0, 15, 0);
