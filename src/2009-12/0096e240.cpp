// from server: 100% by nuck16
// roc 2009-12 0096e240  unit: seg_00960000  size: 45 bytes
//
// 0096e240  33c9                 xor ecx, ecx
// 0096e242  51                   push ecx
// 0096e243  6a0f                 push 0xf
// 0096e245  51                   push ecx
// 0096e246  51                   push ecx
// 0096e247  b8c0d26200           mov eax, 0x62d2c0
// 0096e24c  50                   push eax
// 0096e24d  68a0b99c00           push 0x9cb9a0
// 0096e252  68f4b99c00           push 0x9cb9f4
// 0096e257  b96c49b800           mov ecx, 0xb8496c
// 0096e25c  e8ff12ccff           call 0x62f560
// 0096e261  68c0119800           push 0x9811c0
// 0096e266  e8be66e8ff           call 0x7f4929
// 0096e26b  59                   pop ecx
// 0096e26c  c3                   ret 

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

static Desc desc("PrivateWorkingSetBytes", "PerfCounters", &Owner::m0, 0, 15, 0);
