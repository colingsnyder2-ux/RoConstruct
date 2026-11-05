// from server: 100% by nuck16
// roc 2009-12 00972a50  unit: seg_00970000  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00972a50
//
// 00972a50  6a01                 push 1
// 00972a52  33c9                 xor ecx, ecx
// 00972a54  6898f39c00           push 0x9cf398
// 00972a59  51                   push ecx
// 00972a5a  b8f0d96600           mov eax, 0x66d9f0
// 00972a5f  50                   push eax
// 00972a60  b95805b900           mov ecx, 0xb90558
// 00972a65  e8d6c5cfff           call 0x66f040
// 00972a6a  68404a9800           push 0x984a40
// 00972a6f  e8b51ee8ff           call 0x7f4929
// 00972a74  59                   pop ecx
// 00972a75  c3                   ret 

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

static Desc desc(&Owner::m0, "GetJobsExtendedStats", 1);
