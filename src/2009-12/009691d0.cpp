// from server: 100% by nuck16
// roc 2009-12 009691d0  unit: seg_00960000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009691d0
//
// 009691d0  33c9                 xor ecx, ecx
// 009691d2  51                   push ecx
// 009691d3  6a0f                 push 0xf
// 009691d5  51                   push ecx
// 009691d6  b8709b4400           mov eax, 0x449b70
// 009691db  50                   push eax
// 009691dc  68e0414400           push 0x4441e0
// 009691e1  6858aa9a00           push 0x9aaa58
// 009691e6  68c0ab9a00           push 0x9aabc0
// 009691eb  b960b2b700           mov ecx, 0xb7b260
// 009691f0  e8dbeaadff           call 0x447cd0
// 009691f5  6870e49700           push 0x97e470
// 009691fa  e82ab7e8ff           call 0x7f4929
// 009691ff  59                   pop ecx
// 00969200  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

extern "C" void func_004441e0();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("EagerBulkExecution", "Performance", func_004441e0, &Owner::m0, 15, 0);
