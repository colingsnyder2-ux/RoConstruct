// from server: 100% by nuck16
// roc 2009-12 0096ed40  unit: seg_00960000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096ed40
//
// 0096ed40  6a01                 push 1
// 0096ed42  6828c09c00           push 0x9cc028
// 0096ed47  6878c09c00           push 0x9cc078
// 0096ed4c  6880000000           push 0x80
// 0096ed51  b9f853b800           mov ecx, 0xb853f8
// 0096ed56  e8d572ccff           call 0x636030
// 0096ed5b  68c0199800           push 0x9819c0
// 0096ed60  e8c45be8ff           call 0x7f4929
// 0096ed65  59                   pop ecx
// 0096ed66  c3                   ret 

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

static Desc desc(128, "DescendantAdded", "descendant", 1);
