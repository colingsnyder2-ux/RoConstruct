// from server: 100% by nuck16
// roc 2009-12 00973e80  unit: seg_00970000  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00973e80
//
// 00973e80  6a01                 push 1
// 00973e82  6a01                 push 1
// 00973e84  6874309d00           push 0x9d3074
// 00973e89  33c9                 xor ecx, ecx
// 00973e8b  6864309d00           push 0x9d3064
// 00973e90  51                   push ecx
// 00973e91  b8306e6a00           mov eax, 0x6a6e30
// 00973e96  50                   push eax
// 00973e97  b9c017b900           mov ecx, 0xb917c0
// 00973e9c  e8af2cd3ff           call 0x6a6b50
// 00973ea1  6880549800           push 0x985480
// 00973ea6  e87e0ae8ff           call 0x7f4929
// 00973eab  59                   pop ecx
// 00973eac  c3                   ret 

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

static Desc desc(&Owner::m0, "GetHeapStats", "clearHighwaterMark", 1, 1);
