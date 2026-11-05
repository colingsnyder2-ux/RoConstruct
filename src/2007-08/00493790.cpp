// from server: 100% by EspClaude
// roc 2007-08 00493790  std::for_each(list::iterator, list::iterator, bind(fn, _1, b)) instantiation
// 2007 boost bind_t list2<arg<1>, value<B>> keeps the placeholder as a padded member (12-byte functor).
// roc-flags: /O2 /GS /EHsc /MD
#include <list>
#include <algorithm>
namespace RBX { class Instance; }
struct Slot;
struct BoundCall {
    void (*f)(Slot*&, RBX::Instance*);
    int placeholder;
    RBX::Instance* b;
    void operator()(Slot*& x) { f(x, b); }
};
template BoundCall std::for_each<std::list<Slot*>::iterator, BoundCall>(std::list<Slot*>::iterator, std::list<Slot*>::iterator, BoundCall);
