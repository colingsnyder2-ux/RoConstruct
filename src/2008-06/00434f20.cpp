// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_a4a5133839b14b11.cpp

// Candidate translation unit (score above; library headers required).
#define _CPPUNWIND 1
#include <typeinfo>
#include <string>
#include <boost/any.hpp>
namespace RBX { namespace Reflection {
class Type {
	unsigned int reserved[2];
public:
	const std::type_info& info;
	const std::type_info& getInfo() const { return info; }
};
class Variant {
	const Type* type;
	boost::any value;
public:
	template<class T> const T& convert() const;
	template<class T> T get() const;
};
const std::string& getStringFromAny(const boost::any* value);
template<> std::string Variant::get<std::string>() const
{
	if (typeid(std::string) == type->getInfo())
		return getStringFromAny(&value);
	Variant copy(*this);
	return copy.convert<std::string>();
}
}}
