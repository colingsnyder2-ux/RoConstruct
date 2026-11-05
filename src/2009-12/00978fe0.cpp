// from server: 100% by nuck16
// roc 2009-12 00978fe0  unit: seg_00970000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00978fe0
//
// 00978fe0  33c9                 xor ecx, ecx
// 00978fe2  51                   push ecx
// 00978fe3  6a0f                 push 0xf
// 00978fe5  51                   push ecx
// 00978fe6  b820337300           mov eax, 0x733320
// 00978feb  50                   push eax
// 00978fec  6894000000           push 0x94
// 00978ff1  6884b09b00           push 0x9bb084
// 00978ff6  684cd59a00           push 0x9ad54c
// 00978ffb  b9c860b900           mov ecx, 0xb960c8
// 00979000  e83b56dbff           call 0x72e640
// 00979005  68f0819800           push 0x9881f0
// 0097900a  e81ab9e7ff           call 0x7f4929
// 0097900f  59                   pop ecx
// 00979010  c3                   ret 

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
    Desc(const char *, const char *, int, void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("Value", "Data", 148, &Owner::m0, 15, 0);
