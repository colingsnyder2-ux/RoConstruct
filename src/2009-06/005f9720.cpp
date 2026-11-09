// from server: 100% by EspClaude
// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client roc_espclaude_a943387d3f6c2861.cpp

// Candidate translation unit (score above; library headers required).
#include "decomp.h"
#include "util/Name.h"
#include <boost/noncopyable.hpp>
#include <boost/thread/recursive_mutex.hpp>
#define REFLECTION_DESCRIPTOR_H
namespace RBX {
namespace Reflection {
extern bool exeFlag2009;
void exeHook2009();
const Name& exeDeclare2009(const char*);
inline boost::recursive_mutex& sync()
{
	static boost::recursive_mutex s;
	return s;
}
class Descriptor : public boost::noncopyable
{
public:
	virtual ~Descriptor() {}
	const Name& name;
	Descriptor(const char* name) : name(exeDeclare2009(name)) { if (exeFlag2009) exeHook2009(); }
};
}
}
#include "reflection/reflection.h"
namespace RBX {
namespace Reflection {
ClassDescriptor::ClassDescriptor()
	: Descriptor("<<<ROOT>>>"), MemberDescriptorContainer<PropertyDescriptor>(NULL),
	  MemberDescriptorContainer<SignalDescriptor>(NULL), MemberDescriptorContainer<FunctionDescriptor>(NULL), base(NULL)
{
}
}
}
