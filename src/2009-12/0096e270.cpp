// from server: 100% by nuck16
// roc 2009-12 0096e270  unit: seg_00960000  size: 45 bytes
//
// 0096e270  33c9                 xor ecx, ecx
// 0096e272  51                   push ecx
// 0096e273  6a0f                 push 0xf
// 0096e275  51                   push ecx
// 0096e276  51                   push ecx
// 0096e277  b850d36200           mov eax, 0x62d350
// 0096e27c  50                   push eax
// 0096e27d  68a0b99c00           push 0x9cb9a0
// 0096e282  680cba9c00           push 0x9cba0c
// 0096e287  b9344bb800           mov ecx, 0xb84b34
// 0096e28c  e8cf12ccff           call 0x62f560
// 0096e291  68e0119800           push 0x9811e0
// 0096e296  e88e66e8ff           call 0x7f4929
// 0096e29b  59                   pop ecx
// 0096e29c  c3                   ret 

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

static Desc desc("VirtualBytes", "PerfCounters", &Owner::m0, 0, 15, 0);
