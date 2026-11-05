// from server: 100% by nuck16
// roc 2009-12 00979d80  unit: seg_00970000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00979d80
//
// 00979d80  6a01                 push 1
// 00979d82  68b8b19b00           push 0x9bb1b8
// 00979d87  6880269e00           push 0x9e2680
// 00979d8c  6898000000           push 0x98
// 00979d91  b9a868b900           mov ecx, 0xb968a8
// 00979d96  e8a559dcff           call 0x73f740
// 00979d9b  68708c9800           push 0x988c70
// 00979da0  e884abe7ff           call 0x7f4929
// 00979da5  59                   pop ecx
// 00979da6  c3                   ret 

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
    Desc(int, const char *, const char *, int);
    ~Desc();
};

static Desc desc(152, "ItemAdded", "instance", 1);
