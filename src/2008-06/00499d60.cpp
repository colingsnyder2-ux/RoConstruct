// from server: 100% by colin
#include <set>

struct Member {
    void* data;
    bool enabled;
    int count;

    Member();
};

struct S : std::set<double> {
    Member member;

    S();
};

S::S()
    : member()
{
}
