// from server: 100% by nuck16
// roc 2009-12 00973ee0  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00973ee0
//
// 00973ee0  6a01                 push 1
// 00973ee2  6a09                 push 9
// 00973ee4  6814010000           push 0x114
// 00973ee9  6858aa9a00           push 0x9aaa58
// 00973eee  68a0309d00           push 0x9d30a0
// 00973ef3  b94c17b900           mov ecx, 0xb9174c
// 00973ef8  e86315d3ff           call 0x6a5460
// 00973efd  6840549800           push 0x985440
// 00973f02  e8220ae8ff           call 0x7f4929
// 00973f07  59                   pop ecx
// 00973f08  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:

};


struct Desc
{
    Desc(const char *, const char *, int, int, int);
    ~Desc();
};

static Desc desc("GarbageCollectionFrequency", "Performance", 276, 9, 1);
