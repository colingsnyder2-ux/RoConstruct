// from server: 100% by nuck16
// roc 2009-12 0096c530  unit: seg_00960000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096c530
//
// 0096c530  6a01                 push 1
// 0096c532  684cb59b00           push 0x9bb54c
// 0096c537  33c9                 xor ecx, ecx
// 0096c539  68a0b89b00           push 0x9bb8a0
// 0096c53e  51                   push ecx
// 0096c53f  b8c05c5100           mov eax, 0x515cc0
// 0096c544  50                   push eax
// 0096c545  b9c0ecb700           mov ecx, 0xb7ecc0
// 0096c54a  e8f106bbff           call 0x51cc40
// 0096c54f  6880fd9700           push 0x97fd80
// 0096c554  e8d083e8ff           call 0x7f4929
// 0096c559  59                   pop ecx
// 0096c55a  c3                   ret 

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

static Desc desc(&Owner::m0, "GetPlayerByID", "userID", 1);
