// from server: 100% by nuck16
// roc 2009-12 0097bd40  unit: seg_00970000  size: 57 bytes
//
// 0097bd40  56                   push esi
// 0097bd41  33f6                 xor esi, esi
// 0097bd43  56                   push esi
// 0097bd44  6a0f                 push 0xf
// 0097bd46  33c9                 xor ecx, ecx
// 0097bd48  51                   push ecx
// 0097bd49  b8a0fd7600           mov eax, 0x76fda0
// 0097bd4e  50                   push eax
// 0097bd4f  56                   push esi
// 0097bd50  ba50cf7600           mov edx, 0x76cf50
// 0097bd55  52                   push edx
// 0097bd56  6884b09b00           push 0x9bb084
// 0097bd5b  6884899e00           push 0x9e8984
// 0097bd60  b98082b900           mov ecx, 0xb98280
// 0097bd65  e8262bdfff           call 0x76e890
// 0097bd6a  68f09e9800           push 0x989ef0
// 0097bd6f  e8b58be7ff           call 0x7f4929
// 0097bd74  83c404               add esp, 4
// 0097bd77  5e                   pop esi
// 0097bd78  c3                   ret 

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

static Desc desc("BackgroundColor3", "Data", &Owner::m0, &Owner::m1, 15, 0);
