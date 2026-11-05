// from server: 100% by nuck16
// roc 2009-12 0096e6a0  unit: seg_00960000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096e6a0
//
// 0096e6a0  6a00                 push 0
// 0096e6a2  6a0f                 push 0xf
// 0096e6a4  68a4000000           push 0xa4
// 0096e6a9  6858bb9c00           push 0x9cbb58
// 0096e6ae  687cbb9c00           push 0x9cbb7c
// 0096e6b3  b93c4cb800           mov ecx, 0xb84c3c
// 0096e6b8  e88310ccff           call 0x62f740
// 0096e6bd  68c0139800           push 0x9813c0
// 0096e6c2  e86262e8ff           call 0x7f4929
// 0096e6c7  59                   pop ecx
// 0096e6c8  c3                   ret 

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

static Desc desc("ReportExtendedMachineConfiguration", "Errors", 164, 15, 0);
