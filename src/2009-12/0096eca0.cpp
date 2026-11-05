// from server: 100% by nuck16
// roc 2009-12 0096eca0  unit: seg_00960000  size: 57 bytes
//
// 0096eca0  56                   push esi
// 0096eca1  33f6                 xor esi, esi
// 0096eca3  56                   push esi
// 0096eca4  6a09                 push 9
// 0096eca6  33c9                 xor ecx, ecx
// 0096eca8  51                   push ecx
// 0096eca9  b8806d6300           mov eax, 0x636d80
// 0096ecae  50                   push eax
// 0096ecaf  56                   push esi
// 0096ecb0  baf0e48100           mov edx, 0x81e4f0
// 0096ecb5  52                   push edx
// 0096ecb6  6884b09b00           push 0x9bb084
// 0096ecbb  684cc09c00           push 0x9cc04c
// 0096ecc0  b9ac51b800           mov ecx, 0xb851ac
// 0096ecc5  e87655ccff           call 0x634240
// 0096ecca  6880179800           push 0x981780
// 0096eccf  e8555ce8ff           call 0x7f4929
// 0096ecd4  83c404               add esp, 4
// 0096ecd7  5e                   pop esi
// 0096ecd8  c3                   ret 

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

static Desc desc("Parent", "Data", &Owner::m0, &Owner::m1, 9, 0);
