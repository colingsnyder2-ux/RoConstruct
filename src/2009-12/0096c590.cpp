// from server: 100% by nuck16
// roc 2009-12 0096c590  unit: seg_00960000  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096c590
//
// 0096c590  6a04                 push 4
// 0096c592  6804b19b00           push 0x9bb104
// 0096c597  68b8b89b00           push 0x9bb8b8
// 0096c59c  33c9                 xor ecx, ecx
// 0096c59e  684cc19a00           push 0x9ac14c
// 0096c5a3  51                   push ecx
// 0096c5a4  b890095200           mov eax, 0x520990
// 0096c5a9  50                   push eax
// 0096c5aa  b998edb700           mov ecx, 0xb7ed98
// 0096c5af  e84c0abbff           call 0x51d000
// 0096c5b4  6840fc9700           push 0x97fc40
// 0096c5b9  e86b83e8ff           call 0x7f4929
// 0096c5be  59                   pop ecx
// 0096c5bf  c3                   ret 

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
    Desc(void (Owner::*)(), const char *, const char *, const char *, int);
    ~Desc();
};

static Desc desc(&Owner::m0, "ReportAbuse", "player", "message", 4);
