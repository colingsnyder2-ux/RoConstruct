// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <map>
namespace RBX {
class Joint; class Primitive;
template<class K, class V>
class MultiMap : public std::multimap<K, V> {
public:
    void removeEntry(const K& k, const V& v);
};
template<class K, class V>
void MultiMap<K, V>::removeEntry(const K& k, const V& v)
{
    typename std::multimap<K, V>::iterator it;
    for (it = this->lower_bound(k); it != this->upper_bound(k); ++it) {
        if (it->second == v) {
            this->erase(it);
            return;
        }
    }
}
template class MultiMap<Primitive*, Joint*>;
}
