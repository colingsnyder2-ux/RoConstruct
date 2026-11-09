// from server: 100% by nuck16
// roc 2009-12 0096bd40  unit: seg_00960000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096bd40
//
// 0096bd40  6a01                 push 1
// 0096bd42  6850b19b00           push 0x9bb150
// 0096bd47  6848b19b00           push 0x9bb148
// 0096bd4c  682c010000           push 0x12c
// 0096bd51  b928e4b700           mov ecx, 0xb7e428
// 0096bd56  e865dfb9ff           call 0x509cc0
// 0096bd5b  68a0f49700           push 0x97f4a0
// 0096bd60  e8c48be8ff           call 0x7f4929
// 0096bd65  59                   pop ecx
// 0096bd66  c3                   ret 

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

static Desc desc(300, "Idled", "time", 1);
