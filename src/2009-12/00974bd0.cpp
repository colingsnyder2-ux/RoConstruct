// from server: 100% by nuck16
// roc 2009-12 00974bd0  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00974bd0
//
// 00974bd0  6a00                 push 0
// 00974bd2  6a0f                 push 0xf
// 00974bd4  68a1000000           push 0xa1
// 00974bd9  6820d89a00           push 0x9ad820
// 00974bde  6808749d00           push 0x9d7408
// 00974be3  b94825b900           mov ecx, 0xb92548
// 00974be8  e8b31ad5ff           call 0x6c66a0
// 00974bed  68e05b9800           push 0x985be0
// 00974bf2  e832fde7ff           call 0x7f4929
// 00974bf7  59                   pop ecx
// 00974bf8  c3                   ret 

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

static Desc desc("SoftwareSound", "Sound", 161, 15, 0);
