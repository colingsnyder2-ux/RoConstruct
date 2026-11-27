// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /D_SECURE_SCL=0
#include <list>
struct Product { char data[76]; };
void grow(std::list<Product>& l, const Product& p) { l.push_back(p); l.push_back(p); l.insert(l.begin(), p); l.push_front(p); }