// from server: 100% by king_originala
#pragma optimize("", off)

struct Member {
    Member(int value);
};

struct S {
    int first;
    int second;
    Member member;

    S(int value);
};

S::S(int value)
    : first(0), second(value), member(value)
{
}
