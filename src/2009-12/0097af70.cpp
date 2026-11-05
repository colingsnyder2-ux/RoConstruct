// from server: 100% by nuck16
// roc 2009-12 0097af70  unit: seg_00970000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097af70
//
// 0097af70  33c9                 xor ecx, ecx
// 0097af72  51                   push ecx
// 0097af73  6a0f                 push 0xf
// 0097af75  51                   push ecx
// 0097af76  b8709e7500           mov eax, 0x759e70
// 0097af7b  50                   push eax
// 0097af7c  6880047400           push 0x740480
// 0097af81  6884b09b00           push 0x9bb084
// 0097af86  682c5f9e00           push 0x9e5f2c
// 0097af8b  b99c76b900           mov ecx, 0xb9769c
// 0097af90  e8cbf3ddff           call 0x75a360
// 0097af95  68b0959800           push 0x9895b0
// 0097af9a  e88a99e7ff           call 0x7f4929
// 0097af9f  59                   pop ecx
// 0097afa0  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

extern "C" void func_00740480();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("TextYAlignment", "Data", func_00740480, &Owner::m0, 15, 0);
