// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS- /MD
#define _SCL_SECURE_NO_WARNINGS
#include <algorithm>
namespace Wml {
class Vec {
public:
    void resize(int n);
    Vec& operator=(const Vec& o);
    void* pad;
    int num;
    double* data;
};
Vec& Vec::operator=(const Vec& o)
{
    if (this != &o)
    {
        resize(o.num);
        std::copy(o.data, o.data + o.num, data);
    }
    return *this;
}
}
