// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /D_SECURE_SCL=0
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
struct E { std::string a; int b; std::string c; int d; float e, f, g, h; bool i; };
template E* std::copy<E*, E*>(E*, E*, E*);
