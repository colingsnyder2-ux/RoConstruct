// from server: 100% by nuck16
// roc 2009-12 0096c560  unit: seg_00960000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096c560
//
// 0096c560  6a01                 push 1
// 0096c562  6804b19b00           push 0x9bb104
// 0096c567  33c9                 xor ecx, ecx
// 0096c569  68b0b89b00           push 0x9bb8b0
// 0096c56e  51                   push ecx
// 0096c56f  b8c0f05100           mov eax, 0x51f0c0
// 0096c574  50                   push eax
// 0096c575  b9d0eeb700           mov ecx, 0xb7eed0
// 0096c57a  e8f108bbff           call 0x51ce70
// 0096c57f  6830fc9700           push 0x97fc30
// 0096c584  e8a083e8ff           call 0x7f4929
// 0096c589  59                   pop ecx
// 0096c58a  c3                   ret 

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

static Desc desc(&Owner::m0, "Chat", "message", 1);
