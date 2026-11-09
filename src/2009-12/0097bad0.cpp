// from server: 100% by nuck16
// roc 2009-12 0097bad0  unit: seg_00970000  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097bad0
//
// 0097bad0  33c9                 xor ecx, ecx
// 0097bad2  51                   push ecx
// 0097bad3  6a0f                 push 0xf
// 0097bad5  51                   push ecx
// 0097bad6  51                   push ecx
// 0097bad7  b820b87600           mov eax, 0x76b820
// 0097badc  50                   push eax
// 0097badd  6884b09b00           push 0x9bb084
// 0097bae2  68a4819e00           push 0x9e81a4
// 0097bae7  b9507fb900           mov ecx, 0xb97f50
// 0097baec  e88f03dfff           call 0x76be80
// 0097baf1  68709a9800           push 0x989a70
// 0097baf6  e82e8ee7ff           call 0x7f4929
// 0097bafb  59                   pop ecx
// 0097bafc  c3                   ret 

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

static Desc desc("ViewSizeY", "Data", &Owner::m0, 0, 15, 0);
