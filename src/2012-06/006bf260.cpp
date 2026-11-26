// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
#include <typeinfo>
namespace RBX{ namespace Lua{ class WeakFunctionRef{}; } }
struct N{ char pad[0x10]; const std::type_info* p; template<class T> bool is() const { if(p==&typeid(T)) return true; return typeid(T)==*p; } };
struct S{ N* n; bool f(); };
bool S::f(){ return n->is<RBX::Lua::WeakFunctionRef>(); }
