// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /GS- /MD
#include <vector>
namespace Wml {
template <class Real> class ConvexHull2 {
public:
    class SortedVertex {
    public:
        Real m_kV[2];
        int m_iIndex;
    };
};
}
template std::_Vector_const_iterator<Wml::ConvexHull2<float>::SortedVertex, std::allocator<Wml::ConvexHull2<float>::SortedVertex> >::_Vector_const_iterator(Wml::ConvexHull2<float>::SortedVertex*, const std::_Container_base*);
