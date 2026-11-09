// from server: 100% by nuck16
// roc 2009-12 0096e210  unit: seg_00960000  size: 45 bytes
//
// 0096e210  33c9                 xor ecx, ecx
// 0096e212  51                   push ecx
// 0096e213  6a0f                 push 0xf
// 0096e215  51                   push ecx
// 0096e216  51                   push ecx
// 0096e217  b830d26200           mov eax, 0x62d230
// 0096e21c  50                   push eax
// 0096e21d  68a0b99c00           push 0x9cb9a0
// 0096e222  68e4b99c00           push 0x9cb9e4
// 0096e227  b9cc4ab800           mov ecx, 0xb84acc
// 0096e22c  e82f13ccff           call 0x62f560
// 0096e231  68a0119800           push 0x9811a0
// 0096e236  e8ee66e8ff           call 0x7f4929
// 0096e23b  59                   pop ecx
// 0096e23c  c3                   ret 

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

static Desc desc("PrivateBytes", "PerfCounters", &Owner::m0, 0, 15, 0);
