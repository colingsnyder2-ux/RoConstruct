// from server: 100% by nuck16
// roc 2009-12 0096e730  unit: seg_00960000  size: 57 bytes
//
// 0096e730  56                   push esi
// 0096e731  33f6                 xor esi, esi
// 0096e733  56                   push esi
// 0096e734  6a0f                 push 0xf
// 0096e736  33c9                 xor ecx, ecx
// 0096e738  51                   push ecx
// 0096e739  b8d0156300           mov eax, 0x6315d0
// 0096e73e  50                   push eax
// 0096e73f  56                   push esi
// 0096e740  bae0a76300           mov edx, 0x63a7e0
// 0096e745  52                   push edx
// 0096e746  6820a79b00           push 0x9ba720
// 0096e74b  6880b39c00           push 0x9cb380
// 0096e750  b9b84fb800           mov ecx, 0xb84fb8
// 0096e755  e8b632ccff           call 0x631a10
// 0096e75a  68c0149800           push 0x9814c0
// 0096e75f  e8c561e8ff           call 0x7f4929
// 0096e764  83c404               add esp, 4
// 0096e767  5e                   pop esi
// 0096e768  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
    void m1();
};


struct Desc
{
    Desc(const char *, const char *, void (Owner::*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("ThreadPoolConfig", "Configuration", &Owner::m0, &Owner::m1, 15, 0);
