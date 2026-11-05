// from server: 100% by EspClaude
// roc 2009-06 005c4ca0  unoptimized copy ctor: base(o) then member at +0xc copied
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS- /EHsc /MD

struct Base
{
    char data[0xc];
    Base(const Base&);
    ~Base();
};

struct Member
{
    char data[0x1c];
    Member(const Member&);
    ~Member();
};

struct Holder : Base
{
    Member member;
    Holder(const Holder& other);
};

Holder::Holder(const Holder& other)
    : Base(other), member(other.member)
{
}
