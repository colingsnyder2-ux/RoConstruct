// from server: 100% by nuck16
// roc 2009-12 0097bc80  unit: seg_00970000  size: 57 bytes
//
// 0097bc80  56                   push esi
// 0097bc81  33f6                 xor esi, esi
// 0097bc83  56                   push esi
// 0097bc84  6a08                 push 8
// 0097bc86  33c9                 xor ecx, ecx
// 0097bc88  51                   push ecx
// 0097bc89  b8000a7700           mov eax, 0x770a00
// 0097bc8e  50                   push eax
// 0097bc8f  56                   push esi
// 0097bc90  bae0ce7600           mov edx, 0x76cee0
// 0097bc95  52                   push edx
// 0097bc96  6884b09b00           push 0x9bb084
// 0097bc9b  6858899e00           push 0x9e8958
// 0097bca0  b97c85b900           mov ecx, 0xb9857c
// 0097bca5  e8362bdfff           call 0x76e7e0
// 0097bcaa  6830a09800           push 0x98a030
// 0097bcaf  e8758ce7ff           call 0x7f4929
// 0097bcb4  83c404               add esp, 4
// 0097bcb7  5e                   pop esi
// 0097bcb8  c3                   ret 

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

static Desc desc("BorderColor", "Data", &Owner::m0, &Owner::m1, 8, 0);
