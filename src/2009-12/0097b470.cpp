// from server: 100% by nuck16
// roc 2009-12 0097b470  unit: seg_00970000  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097b470
//
// 0097b470  33c9                 xor ecx, ecx
// 0097b472  51                   push ecx
// 0097b473  6a09                 push 9
// 0097b475  51                   push ecx
// 0097b476  51                   push ecx
// 0097b477  b8f06a7500           mov eax, 0x756af0
// 0097b47c  50                   push eax
// 0097b47d  6884b09b00           push 0x9bb084
// 0097b482  68f0779e00           push 0x9e77f0
// 0097b487  b9e07ab900           mov ecx, 0xb97ae0
// 0097b48c  e85f50deff           call 0x7604f0
// 0097b491  6800999800           push 0x989900
// 0097b496  e88e94e7ff           call 0x7f4929
// 0097b49b  59                   pop ecx
// 0097b49c  c3                   ret 

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

static Desc desc("AbsolutePosition", "Data", &Owner::m0, 0, 9, 0);
