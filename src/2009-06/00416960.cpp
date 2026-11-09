// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
namespace boost {
class any;
struct S { std::string s; int v; };
template<class T> T* any_cast(any* operand);
template<> S* any_cast<S>(any* operand);
template<class T> T any_cast(any& operand) { return *any_cast<T>(&operand); }
template S any_cast<S>(any& operand);
}
