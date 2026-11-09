// from server: 100% by nuck16
// roc 2009-12 009790d0  unit: seg_00970000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009790d0
//
// 009790d0  33c9                 xor ecx, ecx
// 009790d2  51                   push ecx
// 009790d3  6a0f                 push 0xf
// 009790d5  51                   push ecx
// 009790d6  b8c0337300           mov eax, 0x7333c0
// 009790db  50                   push eax
// 009790dc  6894000000           push 0x94
// 009790e1  6884b09b00           push 0x9bb084
// 009790e6  684cd59a00           push 0x9ad54c
// 009790eb  b94861b900           mov ecx, 0xb96148
// 009790f0  e88b5ddbff           call 0x72ee80
// 009790f5  6810829800           push 0x988210
// 009790fa  e82ab8e7ff           call 0x7f4929
// 009790ff  59                   pop ecx
// 00979100  c3                   ret 

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

static Desc desc("Value", "Data", 148, &Owner::m0, 15, 0);
