// from server: 100% by nuck16
// roc 2009-12 0096c490  unit: seg_00960000  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096c490
//
// 0096c490  33c9                 xor ecx, ecx
// 0096c492  51                   push ecx
// 0096c493  6a09                 push 9
// 0096c495  51                   push ecx
// 0096c496  51                   push ecx
// 0096c497  b8b03d5100           mov eax, 0x513db0
// 0096c49c  50                   push eax
// 0096c49d  6884b09b00           push 0x9bb084
// 0096c4a2  687cb89b00           push 0x9bb87c
// 0096c4a7  b934edb700           mov ecx, 0xb7ed34
// 0096c4ac  e8dfdfbaff           call 0x51a490
// 0096c4b1  6810fb9700           push 0x97fb10
// 0096c4b6  e86e84e8ff           call 0x7f4929
// 0096c4bb  59                   pop ecx
// 0096c4bc  c3                   ret 

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
    Desc(const char *, const char *, void (Owner::*)(), int, int, int);
    ~Desc();
};

static Desc desc("NumPlayers", "Data", &Owner::m0, 0, 9, 0);
