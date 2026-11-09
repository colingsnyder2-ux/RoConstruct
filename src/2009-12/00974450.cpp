// from server: 100% by nuck16
// roc 2009-12 00974450  unit: seg_00970000  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00974450
//
// 00974450  33c9                 xor ecx, ecx
// 00974452  51                   push ecx
// 00974453  688c669d00           push 0x9d668c
// 00974458  51                   push ecx
// 00974459  b820ad6b00           mov eax, 0x6bad20
// 0097445e  50                   push eax
// 0097445f  b9481ab900           mov ecx, 0xb91a48
// 00974464  e8372fd4ff           call 0x6b73a0
// 00974469  6890589800           push 0x985890
// 0097446e  e8b604e8ff           call 0x7f4929
// 00974473  59                   pop ecx
// 00974474  c3                   ret 

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
    Desc(void (Owner::*)(), const char *, int);
    ~Desc();
};

static Desc desc(&Owner::m0, "Play", 0);
