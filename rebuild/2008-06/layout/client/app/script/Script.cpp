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

void Script::setEmbeddedCode(const std::string& value)
{
    if (getEmbeddedCode() != value)
    {
        embeddedSource.reset(new std::string(value));
        raisePropertyChanged(prop_EmbeddedSourceCode);
    }
}

void Script::setScriptId(const ContentId& value)
{
    if (getScriptId() != value)
    {
        scriptId = value;
        requestCode();
        raisePropertyChanged(prop_SourceCodeId);
    }
}

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

void Script::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
{
	if (ScriptContext* sc = ServiceProvider::find<ScriptContext>(oldProvider))
	{
		sc->removeScript(this);
	}
	if (newProvider)
		requestCode();	// prefetch the script source when entering a provider
}

boost::shared_ptr<const std::string> Script::requestCode()
{
    if (scriptId.isNull())
        return embeddedSource;
    else
        return ContentProvider::singleton().requestContentString(scriptId);
}

template class boost::function1<void,RBX::Security::Context *,std::allocator<boost::function_base> >;
template class boost::function1<void,void *,std::allocator<boost::function_base> >;
template class boost::shared_ptr<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const >;

template void RBX::Name::callDoDeclare<RBX::sScript>();
