// from server: 100% by Intel_Inside
// stl: set_E
struct E
{
    void* a;
    void* b;
    void* c;
    void* d;
    ~E();
    bool operator<(const E&) const;
};

#include <set>
template class std::set<E>;
