// from server: 100% by nuck16
// roc 2009-12 00973870  unit: seg_00970000  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00973870
//
// 00973870  33c9                 xor ecx, ecx
// 00973872  51                   push ecx
// 00973873  51                   push ecx
// 00973874  51                   push ecx
// 00973875  b8b0076900           mov eax, 0x6907b0
// 0097387a  50                   push eax
// 0097387b  51                   push ecx
// 0097387c  6884b09b00           push 0x9bb084
// 00973881  68ac1b9d00           push 0x9d1bac
// 00973886  b91812b900           mov ecx, 0xb91218
// 0097388b  e840c2d1ff           call 0x68fad0
// 00973890  6820509800           push 0x985020
// 00973895  e88f10e8ff           call 0x7f4929
// 0097389a  59                   pop ecx
// 0097389b  c3                   ret 

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

static Desc desc("TextureName", "Data", 0, &Owner::m0, 0, 0);
