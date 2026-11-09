// from server: 100% by nuck16
// roc 2009-12 00976830  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00976830
//
// 00976830  6a01                 push 1
// 00976832  6870b39d00           push 0x9db370
// 00976837  33c9                 xor ecx, ecx
// 00976839  6878b39d00           push 0x9db378
// 0097683e  51                   push ecx
// 0097683f  b820010000           mov eax, 0x120
// 00976844  50                   push eax
// 00976845  b9f83bb900           mov ecx, 0xb93bf8
// 0097684a  e86118d7ff           call 0x6e80b0
// 0097684f  68c0679800           push 0x9867c0
// 00976854  e8d0e0e7ff           call 0x7f4929
// 00976859  59                   pop ecx
// 0097685a  c3                   ret 

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

static Desc desc(&Owner::m0, "Climbing", "speed", 1);
