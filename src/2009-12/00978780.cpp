// from server: 100% by nuck16
// roc 2009-12 00978780  unit: seg_00970000  size: 57 bytes
//
// 00978780  56                   push esi
// 00978781  33f6                 xor esi, esi
// 00978783  56                   push esi
// 00978784  6a0f                 push 0xf
// 00978786  33c9                 xor ecx, ecx
// 00978788  51                   push ecx
// 00978789  b8a06c7100           mov eax, 0x716ca0
// 0097878e  50                   push eax
// 0097878f  56                   push esi
// 00978790  ba90587100           mov edx, 0x715890
// 00978795  52                   push edx
// 00978796  6884b09b00           push 0x9bb084
// 0097879b  68e4f49d00           push 0x9df4e4
// 009787a0  b97c57b900           mov ecx, 0xb9577c
// 009787a5  e8d6ded9ff           call 0x716680
// 009787aa  68f07c9800           push 0x987cf0
// 009787af  e875c1e7ff           call 0x7f4929
// 009787b4  83c404               add esp, 4
// 009787b7  5e                   pop esi
// 009787b8  c3                   ret 

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

static Desc desc("F1", "Data", &Owner::m0, &Owner::m1, 15, 0);
