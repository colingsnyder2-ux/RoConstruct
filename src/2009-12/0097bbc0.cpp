// from server: 100% by nuck16
// roc 2009-12 0097bbc0  unit: seg_00970000  size: 57 bytes
//
// 0097bbc0  56                   push esi
// 0097bbc1  33f6                 xor esi, esi
// 0097bbc3  56                   push esi
// 0097bbc4  6a0f                 push 0xf
// 0097bbc6  33c9                 xor ecx, ecx
// 0097bbc8  51                   push ecx
// 0097bbc9  b820fd7600           mov eax, 0x76fd20
// 0097bbce  50                   push eax
// 0097bbcf  56                   push esi
// 0097bbd0  bad0ce7600           mov edx, 0x76ced0
// 0097bbd5  52                   push edx
// 0097bbd6  6884b09b00           push 0x9bb084
// 0097bbdb  6830899e00           push 0x9e8930
// 0097bbe0  b91084b900           mov ecx, 0xb98410
// 0097bbe5  e8462bdfff           call 0x76e730
// 0097bbea  68d09f9800           push 0x989fd0
// 0097bbef  e8358de7ff           call 0x7f4929
// 0097bbf4  83c404               add esp, 4
// 0097bbf7  5e                   pop esi
// 0097bbf8  c3                   ret 

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

static Desc desc("BorderSizePixel", "Data", &Owner::m0, &Owner::m1, 15, 0);
