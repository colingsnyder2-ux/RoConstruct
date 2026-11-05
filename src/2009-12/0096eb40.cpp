// from server: 100% by nuck16
// roc 2009-12 0096eb40  unit: seg_00960000  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096eb40
//
// 0096eb40  33c9                 xor ecx, ecx
// 0096eb42  51                   push ecx
// 0096eb43  68e4bf9c00           push 0x9cbfe4
// 0096eb48  51                   push ecx
// 0096eb49  b840316300           mov eax, 0x633140
// 0096eb4e  50                   push eax
// 0096eb4f  b95053b800           mov ecx, 0xb85350
// 0096eb54  e84761ccff           call 0x634ca0
// 0096eb59  6800189800           push 0x981800
// 0096eb5e  e8c65de8ff           call 0x7f4929
// 0096eb63  59                   pop ecx
// 0096eb64  c3                   ret 

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

static Desc desc(&Owner::m0, "GetChildren", 0);
