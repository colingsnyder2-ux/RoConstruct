// from server: 100% by king_originala
struct Base {
    unsigned int data[82];
    Base();
    ~Base();
};

struct Part {
    unsigned char data[56];
    void initialize();
};

struct S;

struct Member {
    unsigned char data[56];
    Member(S*);
    ~Member();
};

struct StringMember {
    unsigned char data[28];
    StringMember();
    ~StringMember();
};

extern void (__thiscall * const constructString)(StringMember*);
extern unsigned int __cdecl getLocalScope();

extern unsigned char table0[];
extern unsigned char table10[];
extern unsigned char table14[];
extern unsigned char table20[];
extern unsigned char table24[];
extern unsigned char table44[];
extern unsigned char table64[];
extern unsigned char table84[];
extern unsigned char tableA4[];
extern unsigned char tableC4[];
extern unsigned char table130[];

struct Guid {
    StringMember text;
    unsigned int scope;
    Guid();
    ~Guid();
};

struct S : Base {
    Member member;
    Guid guid;
    S();
};

__forceinline Member::Member(S* owner)
{
    unsigned int* p = reinterpret_cast<unsigned int*>(owner);
    p[0] = reinterpret_cast<unsigned int>(table0);
    p[4] = reinterpret_cast<unsigned int>(table10);
    p[5] = reinterpret_cast<unsigned int>(table14);
    p[8] = reinterpret_cast<unsigned int>(table20);
    p[9] = reinterpret_cast<unsigned int>(table24);
    p[17] = reinterpret_cast<unsigned int>(table44);
    p[25] = reinterpret_cast<unsigned int>(table64);
    p[33] = reinterpret_cast<unsigned int>(table84);
    p[41] = reinterpret_cast<unsigned int>(tableA4);
    p[49] = reinterpret_cast<unsigned int>(tableC4);
    p[76] = reinterpret_cast<unsigned int>(table130);
    reinterpret_cast<Part*>(this)->initialize();
}

__forceinline StringMember::StringMember()
{
    constructString(this);
}

__forceinline Guid::Guid() : text()
{
    scope = getLocalScope();
}

S::S() : Base(), member(this), guid()
{
}
