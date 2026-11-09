// from server: 100% by nuck16
// roc 2009-12 0096eed0  unit: seg_00960000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096eed0
//
// 0096eed0  6a01                 push 1
// 0096eed2  68b4c39c00           push 0x9cc3b4
// 0096eed7  68dcc29c00           push 0x9cc2dc
// 0096eedc  68e0000000           push 0xe0
// 0096eee1  b99058b800           mov ecx, 0xb85890
// 0096eee6  e835d6ccff           call 0x63c520
// 0096eeeb  68401c9800           push 0x981c40
// 0096eef0  e8345ae8ff           call 0x7f4929
// 0096eef5  59                   pop ecx
// 0096eef6  c3                   ret 

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

static Desc desc(224, "Heartbeat", "step", 1);
