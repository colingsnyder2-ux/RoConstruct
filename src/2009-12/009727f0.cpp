// from server: 100% by nuck16
// roc 2009-12 009727f0  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009727f0
//
// 009727f0  6a01                 push 1
// 009727f2  68e0f29c00           push 0x9cf2e0
// 009727f7  33c9                 xor ecx, ecx
// 009727f9  68ccf29c00           push 0x9cf2cc
// 009727fe  51                   push ecx
// 009727ff  b810546600           mov eax, 0x665410
// 00972804  50                   push eax
// 00972805  b92006b900           mov ecx, 0xb90620
// 0097280a  e871bdcfff           call 0x66e580
// 0097280f  68b04a9800           push 0x984ab0
// 00972814  e81021e8ff           call 0x7f4929
// 00972819  59                   pop ecx
// 0097281a  c3                   ret 

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

static Desc desc(&Owner::m0, "SetRemoteBuildMode", "buildModeEnabled", 1);
