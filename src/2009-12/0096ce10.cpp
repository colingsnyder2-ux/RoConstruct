// from server: 100% by nuck16
// roc 2009-12 0096ce10  unit: seg_00960000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096ce10
//
// 0096ce10  6a01                 push 1
// 0096ce12  6860bf9b00           push 0x9bbf60
// 0096ce17  6858bf9b00           push 0x9bbf58
// 0096ce1c  681cbf9b00           push 0x9bbf1c
// 0096ce21  6844bf9b00           push 0x9bbf44
// 0096ce26  6844010000           push 0x144
// 0096ce2b  b9d8fcb700           mov ecx, 0xb7fcd8
// 0096ce30  e87bacbbff           call 0x527ab0
// 0096ce35  6890009800           push 0x980090
// 0096ce3a  e8ea7ae8ff           call 0x7f4929
// 0096ce3f  59                   pop ecx
// 0096ce40  c3                   ret 

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
    Desc(int, const char *, const char *, const char *, const char *, int);
    ~Desc();
};

static Desc desc(324, "ConnectionFailed", "peer", "code", "reason", 1);
