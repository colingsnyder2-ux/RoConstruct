// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /D_SECURE_SCL=0
#include <string>
#include <vector>
struct E { std::string s; int i; };
struct V : std::vector<E> { void tidy() { _Tidy(); } };
struct Part {
    V v;
    void clear();
};
void Part::clear()
{
    v.tidy();
}
