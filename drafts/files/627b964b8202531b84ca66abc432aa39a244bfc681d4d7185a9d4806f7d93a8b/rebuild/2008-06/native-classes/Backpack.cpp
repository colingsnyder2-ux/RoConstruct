// 2008-06 native RBX::Backpack (inactive): the Backpack part of the original Hopper unit (005d16d0..005d1b70).
// Evidence in native-headers/v8datamodel/Backpack.h (IScriptOwner from the native script/Script.h).
// >>> native-status (generated) -- do not edit >>>
// Backpack | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src ad5f3cec | roc native-status --write
#include "v8datamodel/Backpack.h"
#include "v8datamodel/Workspace.h"
#include "Network/Players.h"

namespace RBX
{
	const char sBackpack[] = "Backpack"; // 0083b738 (doDeclare 00489e1b, classDescriptor 005c0189)

	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::FactoryProduct() : D() {}

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	template<class C, class D, const char* N>
	DescribedCreatable<C, D, N>::DescribedCreatable()
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}

	Backpack::Backpack()
	{
		setName("Backpack");
	}

	// 005d18e0 (IScriptOwner vtable 0083b924 slot 0, this adjusted by -0x168). ServiceProvider::find<Workspace>
	// 00491e50, Network::Players::findLocalPlayer 0049ac80, Network::Players::backendProcessing 00495eb0,
	// dynamic_cast to LocalScript (RTTI 00948dd4) and HopperBin (RTTI 009496a0) of script->getParent(); returns the
	// Workspace's IScriptOwner base (+0x340).
	IScriptOwner* Backpack::scriptShouldRun(Script* script)
	{
		Workspace* workspace = ServiceProvider::find<Workspace>(this);
		if (!workspace)
			return NULL;

		bool isLocalBackpack = getParent() == Network::Players::findLocalPlayer(this);
		bool backend = Network::Players::backendProcessing(this, true);
		bool isLocalScript = dynamic_cast<LocalScript*>(script) != NULL;
		bool inHopperBin = dynamic_cast<HopperBin*>(script->getParent()) != NULL;

		if (isLocalScript ? isLocalBackpack : ((inHopperBin && isLocalBackpack) || backend))
			return workspace;

		return NULL;
	}
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::shared_ptr<RBX::GuiItem>;
