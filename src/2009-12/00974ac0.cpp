// from server: 100% by nuck16
// roc 2009-12 00974ac0  unit: seg_00970000  size: 57 bytes
//
// 00974ac0  56                   push esi
// 00974ac1  33f6                 xor esi, esi
// 00974ac3  56                   push esi
// 00974ac4  6a0f                 push 0xf
// 00974ac6  33c9                 xor ecx, ecx
// 00974ac8  51                   push ecx
// 00974ac9  b8d0616c00           mov eax, 0x6c61d0
// 00974ace  50                   push eax
// 00974acf  56                   push esi
// 00974ad0  baf05c6c00           mov edx, 0x6c5cf0
// 00974ad5  52                   push edx
// 00974ad6  6858aa9a00           push 0x9aaa58
// 00974adb  68d8719d00           push 0x9d71d8
// 00974ae0  b90c23b900           mov ecx, 0xb9230c
// 00974ae5  e81618d5ff           call 0x6c6300
// 00974aea  68205b9800           push 0x985b20
// 00974aef  e835fee7ff           call 0x7f4929
// 00974af4  83c404               add esp, 4
// 00974af7  5e                   pop esi
// 00974af8  c3                   ret 

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

static Desc desc("PhysicsEnviromentalThrottle", "Performance", &Owner::m0, &Owner::m1, 15, 0);
