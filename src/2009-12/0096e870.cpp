// from server: 100% by nuck16
// roc 2009-12 0096e870  unit: seg_00960000  size: 57 bytes
//
// 0096e870  56                   push esi
// 0096e871  33f6                 xor esi, esi
// 0096e873  56                   push esi
// 0096e874  6a0f                 push 0xf
// 0096e876  33c9                 xor ecx, ecx
// 0096e878  51                   push ecx
// 0096e879  b850bd6200           mov eax, 0x62bd50
// 0096e87e  50                   push eax
// 0096e87f  56                   push esi
// 0096e880  ba40bd6200           mov edx, 0x62bd40
// 0096e885  52                   push edx
// 0096e886  6820a79b00           push 0x9ba720
// 0096e88b  68ecbb9c00           push 0x9cbbec
// 0096e890  b9584fb800           mov ecx, 0xb84f58
// 0096e895  e84607ccff           call 0x62efe0
// 0096e89a  68c00f9800           push 0x980fc0
// 0096e89f  e88560e8ff           call 0x7f4929
// 0096e8a4  83c404               add esp, 4
// 0096e8a7  5e                   pop esi
// 0096e8a8  c3                   ret 

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

static Desc desc("ThrottledJobSleepTime", "Configuration", &Owner::m0, &Owner::m1, 15, 0);
