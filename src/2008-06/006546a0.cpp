// from server: 55% by king_originala
struct String
{
    char storage[24];
    String();
};

struct Member
{
    Member(void *);
};

struct S
{
    String text;
    Member member;

    S(void *, void *);
};

S::S(void *, void *value)
    : text(), member(value)
{
}
