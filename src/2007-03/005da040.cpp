// from server: 44% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/script/Script.cpp

// Candidate translation unit (score above; library headers required).
#include "script/Script.h"

#include "network/Player.h"
#include "script/ScriptContext.h"
#include "util/ContentProvider.h"
#include "util/Name.h"
#include "v8datamodel/Team.h"

#include <boost/thread/once.hpp>

namespace RBX {

char sScript[] = "Script";

char sLocalScript[] = "LocalScript";

const Reflection::PropDescriptor<Script, std::string> Script::prop_EmbeddedSourceCode(
	"Source", "Data", &Script::getEmbeddedCode, &Script::setEmbeddedCode
);

const Reflection::PropDescriptor<Script, ContentId> Script::prop_SourceCodeId(
	"LinkedSource", "Data", &Script::getScriptId, &Script::setScriptId
);

Reflection::BoundProp<bool, 1> Script::prop_Disabled("Disabled", "Behavior", &Script::disabled);

} // namespace RBX

static boost::shared_ptr<const std::string> helloWorld;
static boost::once_flag flagInitScriptCpp = BOOST_ONCE_INIT;

namespace RBX {

// FUNCTION: WEBSERVICE 0x10068bf0
// FUNCTION: ROBLOX 0x00575380
Script::~Script()
{
}

// FUNCTION: WEBSERVICE 0x10068d50
// FUNCTION: ROBLOX 0x005754e0
boost::shared_ptr<const std::string> Script::requestCode()
{
	if (scriptId.isNull()) {
		return embeddedSource;
	}

	return ContentProvider::singleton().requestContentString(scriptId);
}

} // namespace RBX

// FUNCTION: WEBSERVICE 0x10069000
// FUNCTION: ROBLOX 0x00575800
static void initScriptCpp()
{
	helloWorld.reset(new std::string("print(\"Hello world!\")\r\n"));
}

namespace RBX {

// FUNCTION: WEBSERVICE 0x100699a0
// FUNCTION: ROBLOX 0x00575cf0
Script::Script() : DescribedCreatable<Script, Instance, sScript>("Script"), disabled(false), owner(NULL)
{
	boost::call_once(initScriptCpp, flagInitScriptCpp);

	embeddedSource = helloWorld;
}

// FUNCTION: WEBSERVICE 0x10069aa0
// FUNCTION: ROBLOX 0x00575df0
void Script::onAncestorChanged(const AncestorChanged& event)
{
	Instance::onAncestorChanged(event);

	IScriptOwner* newOwner = NULL;

	for (Instance* i = getParent(); i != NULL; i = i->getParent()) {
		IScriptOwner* scriptOwner = dynamic_cast<IScriptOwner*>(i);

		if (scriptOwner && (newOwner = scriptOwner->scriptShouldRun(this)) != NULL) {
			break;
		}
	}

	if (newOwner != owner) {
		if (owner) {
			owner->releaseScript(this);
		}

		owner = newOwner;

		if (ScriptContext* scriptContext = ServiceProvider::find<ScriptContext>(this)) {
			scriptContext->removeScript(this);

			if (owner) {
				owner->runScript(this, scriptContext);
			}
		}
	}
}

// FUNCTION: WEBSERVICE 0x10069b40
// FUNCTION: ROBLOX 0x00575e90
void Script::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
{
	if (ScriptContext* scriptContext = oldProvider ? oldProvider->find<ScriptContext>() : NULL) {
		scriptContext->removeScript(this);
	}

	Instance::onServiceProvider(oldProvider, newProvider);
}

// FUNCTION: WEBSERVICE 0x10069cd0
// FUNCTION: ROBLOX 0x00576020
LocalScript::LocalScript()
{
	setName("LocalScript");
}

// FUNCTION: WEBSERVICE 0x10069e80
// FUNCTION: ROBLOX 0x005761d0
void Script::setEmbeddedCode(const std::string& value)
{
	if (*embeddedSource != value) {
		embeddedSource.reset(new std::string(value));
		raisePropertyChanged(prop_EmbeddedSourceCode);
	}
}

// FUNCTION: WEBSERVICE 0x10069f10
// FUNCTION: ROBLOX 0x00576260
void Script::setScriptId(const ContentId& value)
{
	if (scriptId != value) {
		scriptId = value;
		requestCode();
		raisePropertyChanged(prop_SourceCodeId);
	}
}

} // namespace RBX

template const RBX::Name& RBX::Name::doDeclare<RBX::sTeam>();
template const RBX::Name& RBX::Name::doDeclare<RBX::Network::sPlayer>();
template void RBX::Name::callDoDeclare<RBX::sTeam>();
template void RBX::Name::callDoDeclare<RBX::Network::sPlayer>();

template const RBX::FactoryProduct<RBX::Network::Player, RBX::Instance, RBX::Network::sPlayer>::Creator
	RBX::FactoryProduct<RBX::Network::Player, RBX::Instance, RBX::Network::sPlayer>::creator;

template class RBX::FactoryProduct<RBX::Script, RBX::Instance, RBX::sScript>;
template class RBX::Reflection::
	Described<RBX::Script, RBX::sScript, RBX::FactoryProduct<RBX::Script, RBX::Instance, RBX::sScript> >;
template class RBX::DescribedCreatable<RBX::Script, RBX::Instance, RBX::sScript>;

template class RBX::FactoryProduct<RBX::LocalScript, RBX::Script, RBX::sLocalScript>;
template class RBX::Reflection::Described<
	RBX::LocalScript,
	RBX::sLocalScript,
	RBX::FactoryProduct<RBX::LocalScript, RBX::Script, RBX::sLocalScript> >;
template class RBX::DescribedCreatable<RBX::LocalScript, RBX::Script, RBX::sLocalScript>;
