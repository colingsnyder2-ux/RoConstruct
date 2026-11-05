// from server: 100% by nuck16
// roc 2009-12 0096c830  unit: seg_00960000  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096c830
//
// 0096c830  33c9                 xor ecx, ecx
// 0096c832  51                   push ecx
// 0096c833  6a0f                 push 0xf
// 0096c835  51                   push ecx
// 0096c836  51                   push ecx
// 0096c837  b8d0225100           mov eax, 0x5122d0
// 0096c83c  50                   push eax
// 0096c83d  6884b09b00           push 0x9bb084
// 0096c842  68b0b99b00           push 0x9bb9b0
// 0096c847  b9b0eeb700           mov ecx, 0xb7eeb0
// 0096c84c  e87fdebaff           call 0x51a6d0
// 0096c851  6850fb9700           push 0x97fb50
// 0096c856  e8ce80e8ff           call 0x7f4929
// 0096c85b  59                   pop ecx
// 0096c85c  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

struct Desc
{
    Desc(const char *, const char *, void (Owner::*)(), int, int, int);
    ~Desc();
};

static Desc desc("ClassicChat", "Data", &Owner::m0, 0, 15, 0);
