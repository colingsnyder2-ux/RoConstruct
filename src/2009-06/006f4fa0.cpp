// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <map>
class Item;
class Listener { public: int x; };
struct Callback {
	void (Listener::*fn)(unsigned int, Item*, int);
	Listener* obj;
	int extra;
	void operator()(unsigned int k, Item* v) const { (obj->*fn)(k, v, extra); }
};
class Registry : public std::multimap<unsigned int, Item*> {
public:
	template<class F> void visit(const unsigned int& key, const F& f);
};
template<class F> void Registry::visit(const unsigned int& key, const F& f)
{
	iterator it;
	for (it = lower_bound(key); it != upper_bound(key); ++it)
		f(key, it->second);
}
template void Registry::visit<Callback>(const unsigned int&, const Callback&);
