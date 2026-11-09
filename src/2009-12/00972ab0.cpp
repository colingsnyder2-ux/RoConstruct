// from server: 100% by nuck16
// roc 2009-12 00972ab0  unit: seg_00970000  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00972ab0
//
// 00972ab0  6a01                 push 1
// 00972ab2  68f4f39c00           push 0x9cf3f4
// 00972ab7  68ecf39c00           push 0x9cf3ec
// 00972abc  33c9                 xor ecx, ecx
// 00972abe  68d4f39c00           push 0x9cf3d4
// 00972ac3  51                   push ecx
// 00972ac4  b8e0ab6600           mov eax, 0x66abe0
// 00972ac9  50                   push eax
// 00972aca  b95004b900           mov ecx, 0xb90450
// 00972acf  e8dcc8cfff           call 0x66f3b0
// 00972ad4  68c04b9800           push 0x984bc0
// 00972ad9  e84b1ee8ff           call 0x7f4929
// 00972ade  59                   pop ecx
// 00972adf  c3                   ret 

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
    Desc(void (Owner::*)(), const char *, const char *, const char *, int);
    ~Desc();
};

static Desc desc(&Owner::m0, "GetJobTimePeakFraction", "jobname", "greaterThan", 1);
