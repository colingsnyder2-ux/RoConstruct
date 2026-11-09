// from server: 100% by nuck16
// roc 2009-12 00973eb0  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00973eb0
//
// 00973eb0  6a01                 push 1
// 00973eb2  6a09                 push 9
// 00973eb4  6810010000           push 0x110
// 00973eb9  6858aa9a00           push 0x9aaa58
// 00973ebe  6888309d00           push 0x9d3088
// 00973ec3  b90c17b900           mov ecx, 0xb9170c
// 00973ec8  e89315d3ff           call 0x6a5460
// 00973ecd  6860549800           push 0x985460
// 00973ed2  e8520ae8ff           call 0x7f4929
// 00973ed7  59                   pop ecx
// 00973ed8  c3                   ret 

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

static Desc desc("GarbageCollectionLimit", "Performance", 272, 9, 1);
