// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /D_SECURE_SCL=0
#include <vector>
#include <map>
#include <algorithm>
struct D { virtual ~D(); };
struct Base { virtual ~Base(); char pad[0x18]; std::vector<D*> items; int t1; int t2; };
struct Y { int a[4]; ~Y(); };
template<class T> void del(T* p) { delete p; }
struct X : Base {
    std::map<int, int> m1;
    std::map<int, int> m2;
    std::vector<int> v3;
    Y y;
    std::vector<int> v5, v6, v7, v8;
    static int count;
    virtual ~X();
};
X::~X()
{
    ++count;
    std::for_each(items.begin(), items.end(), &del<D>);
}
