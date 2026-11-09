// from server: 100% by nuck16
// roc 2009-12 0096d360  unit: seg_00960000  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096d360
//
// 0096d360  6a01                 push 1
// 0096d362  68e8030000           push 0x3e8
// 0096d367  68f8be9b00           push 0x9bbef8
// 0096d36c  33c9                 xor ecx, ecx
// 0096d36e  68accb9b00           push 0x9bcbac
// 0096d373  51                   push ecx
// 0096d374  b8d0c55200           mov eax, 0x52c5d0
// 0096d379  50                   push eax
// 0096d37a  b90004b800           mov ecx, 0xb80400
// 0096d37f  e8ec01bcff           call 0x52d570
// 0096d384  6830049800           push 0x980430
// 0096d389  e89b75e8ff           call 0x7f4929
// 0096d38e  59                   pop ecx
// 0096d38f  c3                   ret 

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
    Desc(void (Owner::*)(), const char *, const char *, int, int);
    ~Desc();
};

static Desc desc(&Owner::m0, "Stop", "blockDuration", 1000, 1);
