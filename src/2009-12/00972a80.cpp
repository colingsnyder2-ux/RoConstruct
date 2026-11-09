// from server: 100% by nuck16
// roc 2009-12 00972a80  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00972a80
//
// 00972a80  6a01                 push 1
// 00972a82  68ccf39c00           push 0x9cf3cc
// 00972a87  33c9                 xor ecx, ecx
// 00972a89  68b0f39c00           push 0x9cf3b0
// 00972a8e  51                   push ecx
// 00972a8f  b870576600           mov eax, 0x665770
// 00972a94  50                   push eax
// 00972a95  b96806b900           mov ecx, 0xb90668
// 00972a9a  e881c7cfff           call 0x66f220
// 00972a9f  68b04b9800           push 0x984bb0
// 00972aa4  e8801ee8ff           call 0x7f4929
// 00972aa9  59                   pop ecx
// 00972aaa  c3                   ret 

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

static Desc desc(&Owner::m0, "SetJobsExtendedStatsWindow", "seconds", 1);
