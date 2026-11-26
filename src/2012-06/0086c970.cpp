// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /D_SECURE_SCL=0
#include <map>
#include <string>
struct Val { int a; int b; };
template class std::map<std::string, Val>;
