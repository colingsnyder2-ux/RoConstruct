// from server: 100% by nuck16
// roc 2009-12 00974180  unit: seg_00970000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00974180
//
// 00974180  33c9                 xor ecx, ecx
// 00974182  51                   push ecx
// 00974183  6a0f                 push 0xf
// 00974185  51                   push ecx
// 00974186  b8b0996b00           mov eax, 0x6b99b0
// 0097418b  50                   push eax
// 0097418c  68c0000000           push 0xc0
// 00974191  6884b09b00           push 0x9bb084
// 00974196  68f8659d00           push 0x9d65f8
// 0097419b  b9301cb900           mov ecx, 0xb91c30
// 009741a0  e8fb22d4ff           call 0x6b64a0
// 009741a5  68d0569800           push 0x9856d0
// 009741aa  e87a07e8ff           call 0x7f4929
// 009741af  59                   pop ecx
// 009741b0  c3                   ret 

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

static Desc desc("DopplerScale", "Data", 192, &Owner::m0, 15, 0);
