// Inactive native 2008-06 recovery: the RBX::Script / LocalScript unit (script/Script.cpp) of the application range
// 0057c000..00588000, 00585c60..0058704f (after the ModelInstance unit, before ChangeHistoryService.cpp, which starts
// with ~FactoryProduct<ChangeHistoryService> 00587060). Verified by tests/record_native_app_unit57c_2008.py.
// Layout: the committed native script/Script.h (read-only here).
//   RTTI     vtables 008311dc .?AVScript@RBX@@ (~Script 00585e40, Script() 00586960) and 00831594 .?AVLocalScript@RBX@@
//            (~LocalScript 00586eb0, LocalScript() 00586d70); FactoryProduct<Script, Instance, sScript> 008310dc and
//            FactoryProduct<LocalScript, Script, sLocalScript> 0083129c, the class names non-const char arrays
//            ($1?sScript@2@3PADA / $1?sLocalScript@2@3PADA).
//   size     0x160: Creatable<Instance>::create<Script> 00414bd0 mallocs 0x160 and calls Script() 00586960.
// Unit profile: document-swap flags, /fp:fast and /U_RELEASEASSERT (the unit profile of the ModelInstance unit).
// Codegen analog: bodies follow the donor tools/rbxgs script/Script.cpp; the recorder proves each against the bytes
// and every call / data target.
// >>> native-status (generated) -- do not edit >>>
// AppUnit57C_2008Script | 2008-06 | draft (no current byte proof)
// 0/7 mapped addresses byte-exact | 7 unproved | 1 referenced strings (not rechecked) | by Espeon (+2) (mixed 5)
// <<< native-status | src 6a8c5a09 | roc native-status --write
#include "script/Script.h"
#include "script/ScriptContext.h"
#include "v8tree/Service.h"
#include "util/ContentProvider.h"
#include "boost/thread/once.hpp"

namespace RBX
{
	char sScript[] = "Script";             // doDeclare / getClassName 00586310
	char sLocalScript[] = "LocalScript";   // getClassName 005863c0

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }
	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }
	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::FactoryProduct() : D() {}
	template<class C, class D, const char* N>
	DescribedCreatable<C, D, N>::DescribedCreatable()
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}
	template<class C, class D, const char* N>
	template<typename Arg0Type>
	DescribedCreatable<C, D, N>::DescribedCreatable(Arg0Type arg0)
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >(arg0) {}
}

using namespace RBX;

const Reflection::PropDescriptor<Script, std::string> Script::prop_EmbeddedSourceCode("Source", "Data", &Script::getEmbeddedCode, &Script::setEmbeddedCode, Reflection::PropertyDescriptor::LEGACY);
const Reflection::PropDescriptor<Script, ContentId> Script::prop_SourceCodeId("LinkedSource", "Data", &Script::getScriptId, &Script::setScriptId, Reflection::PropertyDescriptor::LEGACY);
Reflection::BoundProp<bool, true> Script::prop_Disabled("Disabled", "Behavior", &Script::disabled, Reflection::PropertyDescriptor::STANDARD);

static boost::shared_ptr<const std::string> helloWorld;
static boost::once_flag flagInitScriptCpp = BOOST_ONCE_INIT;

void initScriptCpp()   // 005862a0 (boost::call_once target)
{
    helloWorld.reset(new std::string("print(\"Hello world!\")\r\n"));
}

Script::Script()   // 00586960
    : DescribedCreatable("Script"),
      disabled(false),
      owner(NULL)
{
    boost::call_once(&initScriptCpp, flagInitScriptCpp);
    embeddedSource = helloWorld;
}

LocalScript::LocalScript()   // 00586d70
{
    setName("LocalScript");
}

Script::~Script()   // 00585e40
{
}

LocalScript::~LocalScript()   // 00586eb0
{
}

// 00586f30
void Script::setEmbeddedCode(const std::string& value)
{
    if (getEmbeddedCode() != value)
    {
        embeddedSource.reset(new std::string(value));
        raisePropertyChanged(prop_EmbeddedSourceCode);
    }
}

// 00586fc0
void Script::setScriptId(const ContentId& value)
{
    if (getScriptId() != value)
    {
        scriptId = value;
        requestCode();
        raisePropertyChanged(prop_SourceCodeId);
    }
}

// 00586a70
void Script::onAncestorChanged(const AncestorChanged& event)
{
    Instance::onAncestorChanged(event);
    IScriptOwner* newOwner = NULL;
    Instance* parent = this->getParent();
    while (parent)
    {
        IScriptOwner* parentOwner = dynamic_cast<IScriptOwner*>(parent);
        if (parentOwner)
        {
            newOwner = parentOwner->scriptShouldRun(this);
            if (newOwner)
                break;
        }
        parent = parent->getParent();
    }
    if (newOwner != owner)
    {
        if (owner)
            owner->releaseScript(this);
        owner = newOwner;
        ScriptContext* sc = ServiceProvider::find<ScriptContext>(this);
        if (sc)
        {
            sc->removeScript(this);
            if (owner)
                owner->runScript(this, sc);
        }
    }
}

// 00586bf0: after find<ScriptContext>(old) 0042de90 / removeScript 005ad030 the original tests newProvider
// (00586c0f), calls requestCode 00586b10 (00586c1d) into a discarded shared_ptr (released at 00586c22..00586c52)
// and returns: no Instance::onServiceProvider call in 2008 (as BodyMover 00632db0 / DebrisService 0063c280).
// Rejected: the donor tail `Instance::onServiceProvider(oldProvider, newProvider);` (call the original lacks).
void Script::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
{
	if (ScriptContext* sc = ServiceProvider::find<ScriptContext>(oldProvider))
	{
		sc->removeScript(this);
	}
	if (newProvider)
		requestCode();	// prefetch the script source when entering a provider
}

// 00586b10: NOT exact (see the receipt)
boost::shared_ptr<const std::string> Script::requestCode()
{
    if (scriptId.isNull())
        return embeddedSource;
    else
        return ContentProvider::singleton().requestContentString(scriptId);
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::function1<void,RBX::Security::Context *,std::allocator<boost::function_base> >;
template class boost::function1<void,void *,std::allocator<boost::function_base> >;
template class boost::shared_ptr<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const >;

// Name registrations emitted by this unit (bytes and sX relocation identity proven against the 2008-06 client).
template void RBX::Name::callDoDeclare<RBX::sScript>();
