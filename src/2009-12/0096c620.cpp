// from server: 100% by nuck16
// roc 2009-12 0096c620  unit: seg_00960000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096c620
//
// 0096c620  6a01                 push 1
// 0096c622  68a0b09b00           push 0x9bb0a0
// 0096c627  33c9                 xor ecx, ecx
// 0096c629  68d4b89b00           push 0x9bb8d4
// 0096c62e  51                   push ecx
// 0096c62f  b8f0de5100           mov eax, 0x51def0
// 0096c634  50                   push eax
// 0096c635  b9e8ebb700           mov ecx, 0xb7ebe8
// 0096c63a  e80106bbff           call 0x51cc40
// 0096c63f  6890fc9700           push 0x97fc90
// 0096c644  e8e082e8ff           call 0x7f4929
// 0096c649  59                   pop ecx
// 0096c64a  c3                   ret 

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
    Desc(void (Owner::*)(), const char *, const char *, int);
    ~Desc();
};

static Desc desc(&Owner::m0, "CreateLocalPlayer", "userId", 1);
