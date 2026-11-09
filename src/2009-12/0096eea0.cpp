// from server: 100% by nuck16
// roc 2009-12 0096eea0  unit: seg_00960000  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096eea0
//
// 0096eea0  6a01                 push 1
// 0096eea2  68b4c39c00           push 0x9cc3b4
// 0096eea7  6850b19b00           push 0x9bb150
// 0096eeac  68acc39c00           push 0x9cc3ac
// 0096eeb1  68dc000000           push 0xdc
// 0096eeb6  b95459b800           mov ecx, 0xb85954
// 0096eebb  e8e0d4ccff           call 0x63c3a0
// 0096eec0  68801c9800           push 0x981c80
// 0096eec5  e85f5ae8ff           call 0x7f4929
// 0096eeca  59                   pop ecx
// 0096eecb  c3                   ret 

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
    Desc(int, const char *, const char *, const char *, int);
    ~Desc();
};

static Desc desc(220, "Stepped", "time", "step", 1);
