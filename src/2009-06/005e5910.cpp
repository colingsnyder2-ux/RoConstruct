// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <vector>
namespace boost { template<class T> class shared_ptr; }
namespace RBX {
class Instance;
class ContentId;
typedef const std::vector<boost::shared_ptr<Instance> > Instances;
namespace Reflection {
class Descriptor { public: virtual ~Descriptor() {} protected: Descriptor() {} };
class Type : public Descriptor { public: template<typename T> static const Type& singleton(); protected: Type() {} };
template<typename T> class TType : public Type { public: TType(const char* name, const char* tag); };
template<typename T> class TypeImpl : public TType<T> { public: TypeImpl(const char* name) : TType<T>(name, 0) {} virtual void dummy() const; };
template<>
const Type& Type::singleton<boost::shared_ptr<Instance>>()
{
	static TypeImpl<boost::shared_ptr<Instance>> type("Instance");
	return type;
}
}
}
