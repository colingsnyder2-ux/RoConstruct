// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_639ff02666170d6a.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("reflection/enumconverter.h", "../roc_enum_native_owner_header_b9f24b80cd6bff22.cpp")
#undef _RELEASEASSERT
#include "util/Name.h"
#include "util/Debug.h"
#define Descriptor Descriptor_unused_
#include "reflection/descriptor.h"
#undef Descriptor
namespace RBX { namespace Reflection {
extern bool exeFlag2009;
void exeHook2009();
const Name& exeDeclare2009(const char*);
class Descriptor : public boost::noncopyable
{
public:
	const Name& name;
	Descriptor(const Name&);
	Descriptor(const char* name) : name(exeDeclare2009(name)) { if (exeFlag2009) exeHook2009(); }
	virtual ~Descriptor() {}
};
} }
#include "reflection/type.h"
namespace RBX { namespace Reflection { struct ExePad2009 { int exePad2009; }; } }
#define Type Type, public ExePad2009
#include "reflection/enumconverter.h"
#undef Type
enum _D3DFORMAT { D3DFMT_UNKNOWN = 0, D3DFMT_FORCE_DWORD = 0x7fffffff };
typedef enum _D3DFORMAT D3DFORMAT;
namespace RBX { namespace Reflection {
template void EnumDesc<D3DFORMAT>::addPair(D3DFORMAT, const char*);
} }
