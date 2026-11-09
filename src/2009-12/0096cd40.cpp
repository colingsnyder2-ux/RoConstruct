// from server: 100% by nuck16
// roc 2009-12 0096cd40  unit: seg_00960000  size: 61 bytes
//
// 0096cd40  6a01                 push 1
// 0096cd42  6a1e                 push 0x1e
// 0096cd44  68dcbe9b00           push 0x9bbedc
// 0096cd49  33c9                 xor ecx, ecx
// 0096cd4b  51                   push ecx
// 0096cd4c  68d0be9b00           push 0x9bbed0
// 0096cd51  68c4be9b00           push 0x9bbec4
// 0096cd56  68bcbe9b00           push 0x9bbebc
// 0096cd5b  68b4be9b00           push 0x9bbeb4
// 0096cd60  51                   push ecx
// 0096cd61  b870815200           mov eax, 0x528170
// 0096cd66  50                   push eax
// 0096cd67  b910fdb700           mov ecx, 0xb7fd10
// 0096cd6c  e84fa6bbff           call 0x5273c0
// 0096cd71  68d0009800           push 0x9800d0
// 0096cd76  e8ae7be8ff           call 0x7f4929
// 0096cd7b  59                   pop ecx
// 0096cd7c  c3                   ret 

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
    Desc(void (Owner::*)(), const char *, const char *, const char *, const char *, int, const char *, int, int);
    ~Desc();
};

static Desc desc(&Owner::m0, "Connect", "server", "serverPort", "clientPort", 0, "threadSleepTime", 30, 1);
