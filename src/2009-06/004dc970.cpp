// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace RBX {
class Name { public: std::string s; const std::string& toString() const { return s; } };
namespace Reflection {
class Descriptor { public: virtual ~Descriptor(); const Name& name; };
class ClassDescriptor : public Descriptor {};
class MemberDescriptor : public Descriptor { public: int pad; ClassDescriptor* owner; };
}
namespace Network {
class Streaming2009 {
public:
	std::string memberKey(const Reflection::MemberDescriptor& d);
};
std::string Streaming2009::memberKey(const Reflection::MemberDescriptor& d)
{
	return d.owner->name.toString() + ":" + d.name.toString();
}
}}
