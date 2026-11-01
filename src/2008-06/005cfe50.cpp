// from server: 100% by king_originala
struct Base {
    unsigned char data[0x148];
    ~Base();
};

struct Member {
    unsigned char data[0x38];
    ~Member();
};

struct String {
    unsigned char data[0x1C];
    ~String();
};

extern void (__thiscall * const destroyString)(String*);

struct S : Base {
    Member member;
    String text;
    ~S();
};

__forceinline String::~String()
{
    destroyString(this);
}

S::~S()
{
}
