// from server: 100% by nuck16
// roc 2009-12 00977920  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00977920
//
// 00977920  6a00                 push 0
// 00977922  6a02                 push 2
// 00977924  688c030000           push 0x38c
// 00977929  68801b9d00           push 0x9d1b80
// 0097792e  688ccd9d00           push 0x9dcd8c
// 00977933  b9384bb900           mov ecx, 0xb94b38
// 00977938  e84305d8ff           call 0x6f7e80
// 0097793d  68a0719800           push 0x9871a0
// 00977942  e8e2cfe7ff           call 0x7f4929
// 00977947  59                   pop ecx
// 00977948  c3                   ret 

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

static Desc desc("KeyUpConnectionCount", "EventReplicator", 908, 2, 0);
