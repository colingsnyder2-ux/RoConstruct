// from server: 100% by nuck16
// roc 2009-12 0097ae70  unit: seg_00970000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097ae70
//
// 0097ae70  33c9                 xor ecx, ecx
// 0097ae72  51                   push ecx
// 0097ae73  6a0f                 push 0xf
// 0097ae75  51                   push ecx
// 0097ae76  b8609d7500           mov eax, 0x759d60
// 0097ae7b  50                   push eax
// 0097ae7c  6820887500           push 0x758820
// 0097ae81  6884b09b00           push 0x9bb084
// 0097ae86  68f05e9e00           push 0x9e5ef0
// 0097ae8b  b93876b900           mov ecx, 0xb97638
// 0097ae90  e81bf2ddff           call 0x75a0b0
// 0097ae95  6830969800           push 0x989630
// 0097ae9a  e88a9ae7ff           call 0x7f4929
// 0097ae9f  59                   pop ecx
// 0097aea0  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

extern "C" void func_00758820();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("TextColor3", "Data", func_00758820, &Owner::m0, 15, 0);
