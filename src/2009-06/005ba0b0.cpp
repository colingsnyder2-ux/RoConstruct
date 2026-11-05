// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob0 /GS- /MT
#include <algorithm>
namespace Wml {
template<class Real> class ConvexHull2 {
public:
    class SortedVertex {
    public:
        Real x, y;
        int index;
        char pad[0x48 - 12];
        bool operator<(const SortedVertex& o) const;
    };
};
}
template std::pair<Wml::ConvexHull2<float>::SortedVertex*, Wml::ConvexHull2<float>::SortedVertex*> std::_Unguarded_partition<Wml::ConvexHull2<float>::SortedVertex*>(Wml::ConvexHull2<float>::SortedVertex*, Wml::ConvexHull2<float>::SortedVertex*);
