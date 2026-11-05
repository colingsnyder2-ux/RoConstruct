// from server: 100% by nuck16
// roc 2009-12 009782d0  unit: seg_00970000  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009782d0
//
// 009782d0  33c9                 xor ecx, ecx
// 009782d2  51                   push ecx
// 009782d3  68b8b19b00           push 0x9bb1b8
// 009782d8  6850a79b00           push 0x9ba750
// 009782dd  51                   push ecx
// 009782de  b880ac7000           mov eax, 0x70ac80
// 009782e3  50                   push eax
// 009782e4  b91051b900           mov ecx, 0xb95110
// 009782e9  e8d23fd9ff           call 0x70c2c0
// 009782ee  68e0789800           push 0x9878e0
// 009782f3  e831c6e7ff           call 0x7f4929
// 009782f8  59                   pop ecx
// 009782f9  c3                   ret 

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
    Desc(void (Owner::*)(), const char *, const char *, int);
    ~Desc();
};

static Desc desc(&Owner::m0, "Insert", "instance", 0);
