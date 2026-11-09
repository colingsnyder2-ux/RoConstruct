// from server: 100% by nuck16
// roc 2009-12 00972ae0  unit: seg_00970000  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00972ae0
//
// 00972ae0  6a01                 push 1
// 00972ae2  68f4f39c00           push 0x9cf3f4
// 00972ae7  68ecf39c00           push 0x9cf3ec
// 00972aec  33c9                 xor ecx, ecx
// 00972aee  6800f49c00           push 0x9cf400
// 00972af3  51                   push ecx
// 00972af4  b840ad6600           mov eax, 0x66ad40
// 00972af9  50                   push eax
// 00972afa  b97009b900           mov ecx, 0xb90970
// 00972aff  e8acc8cfff           call 0x66f3b0
// 00972b04  68804a9800           push 0x984a80
// 00972b09  e81b1ee8ff           call 0x7f4929
// 00972b0e  59                   pop ecx
// 00972b0f  c3                   ret 

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
    Desc(void (Owner::*)(), const char *, const char *, const char *, int);
    ~Desc();
};

static Desc desc(&Owner::m0, "GetJobIntervalPeakFraction", "jobname", "greaterThan", 1);
