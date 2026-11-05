// from server: 100% by nuck16
// roc 2009-12 0096e2d0  unit: seg_00960000  size: 45 bytes
//
// 0096e2d0  33c9                 xor ecx, ecx
// 0096e2d2  51                   push ecx
// 0096e2d3  6a0f                 push 0xf
// 0096e2d5  51                   push ecx
// 0096e2d6  51                   push ecx
// 0096e2d7  b870d46200           mov eax, 0x62d470
// 0096e2dc  50                   push eax
// 0096e2dd  68a0b99c00           push 0x9cb9a0
// 0096e2e2  682cba9c00           push 0x9cba2c
// 0096e2e7  b98c49b800           mov ecx, 0xb8498c
// 0096e2ec  e86f12ccff           call 0x62f560
// 0096e2f1  6820129800           push 0x981220
// 0096e2f6  e82e66e8ff           call 0x7f4929
// 0096e2fb  59                   pop ecx
// 0096e2fc  c3                   ret 

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

static Desc desc("PageFaultsPerSecond", "PerfCounters", &Owner::m0, 0, 15, 0);
