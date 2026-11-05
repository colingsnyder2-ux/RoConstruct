// from server: 100% by nuck16
// roc 2009-12 0096ed70  unit: seg_00960000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096ed70
//
// 0096ed70  6a01                 push 1
// 0096ed72  6828c09c00           push 0x9cc028
// 0096ed77  6888c09c00           push 0x9cc088
// 0096ed7c  6884000000           push 0x84
// 0096ed81  b91853b800           mov ecx, 0xb85318
// 0096ed86  e8a572ccff           call 0x636030
// 0096ed8b  68001a9800           push 0x981a00
// 0096ed90  e8945be8ff           call 0x7f4929
// 0096ed95  59                   pop ecx
// 0096ed96  c3                   ret 

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

static Desc desc(132, "DescendantRemoving", "descendant", 1);
