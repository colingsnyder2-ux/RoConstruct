// from server: 100% by nuck16
// roc 2009-12 0096c800  unit: seg_00960000  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096c800
//
// 0096c800  6a01                 push 1
// 0096c802  33c9                 xor ecx, ecx
// 0096c804  51                   push ecx
// 0096c805  68a8b99b00           push 0x9bb9a8
// 0096c80a  6898b99b00           push 0x9bb998
// 0096c80f  51                   push ecx
// 0096c810  b850285100           mov eax, 0x512850
// 0096c815  50                   push eax
// 0096c816  b918efb700           mov ecx, 0xb7ef18
// 0096c81b  e8e00ebbff           call 0x51d700
// 0096c820  68f0fc9700           push 0x97fcf0
// 0096c825  e8ff80e8ff           call 0x7f4929
// 0096c82a  59                   pop ecx
// 0096c82b  c3                   ret 

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
    Desc(void (Owner::*)(), const char *, const char *, int, int);
    ~Desc();
};

static Desc desc(&Owner::m0, "SetChatStyle", "style", 0, 1);
