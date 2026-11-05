// from server: 100% by nuck16
// roc 2009-12 00976950  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00976950
//
// 00976950  6a01                 push 1
// 00976952  688cb39d00           push 0x9db38c
// 00976957  33c9                 xor ecx, ecx
// 00976959  68c4b39d00           push 0x9db3c4
// 0097695e  51                   push ecx
// 0097695f  b838010000           mov eax, 0x138
// 00976964  50                   push eax
// 00976965  b9603ab900           mov ecx, 0xb93a60
// 0097696a  e8a118d7ff           call 0x6e8210
// 0097696f  6800699800           push 0x986900
// 00976974  e8b0dfe7ff           call 0x7f4929
// 00976979  59                   pop ecx
// 0097697a  c3                   ret 

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

static Desc desc(&Owner::m0, "Seated", "active", 1);
