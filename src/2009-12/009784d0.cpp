// from server: 100% by nuck16
// roc 2009-12 009784d0  unit: seg_00970000  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009784d0
//
// 009784d0  33c9                 xor ecx, ecx
// 009784d2  51                   push ecx
// 009784d3  6894e79d00           push 0x9de794
// 009784d8  687ce79d00           push 0x9de77c
// 009784dd  51                   push ecx
// 009784de  b840517100           mov eax, 0x715140
// 009784e3  50                   push eax
// 009784e4  b94854b900           mov ecx, 0xb95448
// 009784e9  e882c6d9ff           call 0x714b70
// 009784ee  68807b9800           push 0x987b80
// 009784f3  e831c4e7ff           call 0x7f4929
// 009784f8  59                   pop ecx
// 009784f9  c3                   ret 

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

static Desc desc(&Owner::m0, "SetMinutesAfterMidnight", "minutes", 0);
