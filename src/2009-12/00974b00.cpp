// from server: 100% by nuck16
// roc 2009-12 00974b00  unit: seg_00970000  size: 57 bytes
//
// 00974b00  56                   push esi
// 00974b01  33f6                 xor esi, esi
// 00974b03  56                   push esi
// 00974b04  6a0f                 push 0xf
// 00974b06  33c9                 xor ecx, ecx
// 00974b08  51                   push ecx
// 00974b09  b800626c00           mov eax, 0x6c6200
// 00974b0e  50                   push eax
// 00974b0f  56                   push esi
// 00974b10  ba005d6c00           mov edx, 0x6c5d00
// 00974b15  52                   push edx
// 00974b16  6858aa9a00           push 0x9aaa58
// 00974b1b  68f4719d00           push 0x9d71f4
// 00974b20  b91c24b900           mov ecx, 0xb9241c
// 00974b25  e87613d5ff           call 0x6c5ea0
// 00974b2a  68005b9800           push 0x985b00
// 00974b2f  e8f5fde7ff           call 0x7f4929
// 00974b34  83c404               add esp, 4
// 00974b37  5e                   pop esi
// 00974b38  c3                   ret 

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

static Desc desc("Is30FpsThrottleEnabled", "Performance", &Owner::m0, &Owner::m1, 15, 0);
