// from server: 100% by Xemicl
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /D_SECURE_SCL=0
#include <vector>
namespace Wml {
template <class Real> class ConvexClipper {
public:
    class Vertex { public: Real p[3]; Real dist; int occurs; bool visible; };
};
}
template class std::vector<Wml::ConvexClipper<double>::Vertex>;
