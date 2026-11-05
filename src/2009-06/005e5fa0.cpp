// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace boost { template<class T> class shared_ptr; }
namespace RBX { namespace Reflection {
class DescribedBase;
class Tuple;
class Type {
public:
	template<class T> Type(const char* name, T* dummy);
	virtual ~Type();
	template<class T> static const Type& singleton();
};
template<class T> class TType : public Type {
public:
	TType(const char* name) : Type(name, (T*)0) {}
	virtual ~TType() {}
};
template<> const Type& Type::singleton<Tuple>()
{
	static TType<Tuple> type("Tuple");
	return type;
}
}}
