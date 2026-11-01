// from server: 100% by tester
#include <list>

struct E {
    char data[320];
    bool operator==(const E&) const;
    bool operator<(const E&) const;
};

template class std::list<E>;
