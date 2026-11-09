// from server: 100% by nuck16
// roc 2009-12 0096cf30  unit: seg_00960000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096cf30
//
// 0096cf30  6a00                 push 0
// 0096cf32  6a0f                 push 0xf
// 0096cf34  68d8000000           push 0xd8
// 0096cf39  68b8c39b00           push 0x9bc3b8
// 0096cf3e  6814c59b00           push 0x9bc514
// 0096cf43  b9b0ffb700           mov ecx, 0xb7ffb0
// 0096cf48  e8a3c2bbff           call 0x5291f0
// 0096cf4d  6850019800           push 0x980150
// 0096cf52  e8d279e8ff           call 0x7f4929
// 0096cf57  59                   pop ecx
// 0096cf58  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:

};


struct Desc
{
    Desc(const char *, const char *, int, int, int);
    ~Desc();
};

static Desc desc("NetworkOwnerRate", "Network", 216, 15, 0);
