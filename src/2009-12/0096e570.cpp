// from server: 100% by nuck16
// roc 2009-12 0096e570  unit: seg_00960000  size: 45 bytes
//
// 0096e570  33c9                 xor ecx, ecx
// 0096e572  51                   push ecx
// 0096e573  6a0f                 push 0xf
// 0096e575  51                   push ecx
// 0096e576  51                   push ecx
// 0096e577  b850c76200           mov eax, 0x62c750
// 0096e57c  50                   push eax
// 0096e57d  68b8c59b00           push 0x9bc5b8
// 0096e582  6810bb9c00           push 0x9cbb10
// 0096e587  b9a44db800           mov ecx, 0xb84da4
// 0096e58c  e8ff08ccff           call 0x62ee90
// 0096e591  68600f9800           push 0x980f60
// 0096e596  e88e63e8ff           call 0x7f4929
// 0096e59b  59                   pop ecx
// 0096e59c  c3                   ret 

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

static Desc desc("NumRunningJobs", "Diagnostics", &Owner::m0, 0, 15, 0);
