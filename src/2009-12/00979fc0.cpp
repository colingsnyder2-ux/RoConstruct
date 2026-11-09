// from server: 100% by nuck16
// roc 2009-12 00979fc0  unit: seg_00970000  size: 57 bytes
//
// 00979fc0  56                   push esi
// 00979fc1  33f6                 xor esi, esi
// 00979fc3  56                   push esi
// 00979fc4  6a0f                 push 0xf
// 00979fc6  33c9                 xor ecx, ecx
// 00979fc8  51                   push ecx
// 00979fc9  b860197400           mov eax, 0x741960
// 00979fce  50                   push eax
// 00979fcf  56                   push esi
// 00979fd0  ba60725700           mov edx, 0x577260
// 00979fd5  52                   push edx
// 00979fd6  6884b09b00           push 0x9bb084
// 00979fdb  68ac299e00           push 0x9e29ac
// 00979fe0  b9586cb900           mov ecx, 0xb96c58
// 00979fe5  e82672dcff           call 0x741210
// 00979fea  68508d9800           push 0x988d50
// 00979fef  e835a9e7ff           call 0x7f4929
// 00979ff4  83c404               add esp, 4
// 00979ff7  5e                   pop esi
// 00979ff8  c3                   ret 

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

static Desc desc("MaxItems", "Data", &Owner::m0, &Owner::m1, 15, 0);
