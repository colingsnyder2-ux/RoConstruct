// from server: 100% by nuck16
// roc 2009-12 00973e10  unit: seg_00970000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00973e10
//
// 00973e10  33c9                 xor ecx, ecx
// 00973e12  51                   push ecx
// 00973e13  6a09                 push 9
// 00973e15  51                   push ecx
// 00973e16  b8809a6a00           mov eax, 0x6a9a80
// 00973e1b  50                   push eax
// 00973e1c  680c010000           push 0x10c
// 00973e21  6818209d00           push 0x9d2018
// 00973e26  6848309d00           push 0x9d3048
// 00973e2b  b92c17b900           mov ecx, 0xb9172c
// 00973e30  e84b15d3ff           call 0x6a5380
// 00973e35  6820549800           push 0x985420
// 00973e3a  e8ea0ae8ff           call 0x7f4929
// 00973e3f  59                   pop ecx
// 00973e40  c3                   ret 

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
    Desc(const char *, const char *, int, void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("ScriptsDisabled", "State", 268, &Owner::m0, 9, 0);
