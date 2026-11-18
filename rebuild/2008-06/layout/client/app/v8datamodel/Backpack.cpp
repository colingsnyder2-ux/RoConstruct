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

IScriptOwner* Backpack::scriptShouldRun(Script* script)
{
	Workspace* workspace = ServiceProvider::find<Workspace>(this);
	if (workspace)
	{
		bool isLocalBackpack = getParent() == Network::Players::findLocalPlayer(this);
		bool backend = Network::Players::backendProcessing(this, true);
		bool isLocalScript = dynamic_cast<LocalScript*>(script) != NULL;
		bool inHopperBin = dynamic_cast<HopperBin*>(script->getParent()) != NULL;

		if (!isLocalScript)
		{
			if (!(inHopperBin && isLocalBackpack) && !backend)
				return NULL;
		}
		else if (!isLocalBackpack)
			return NULL;
		return workspace;
	}
	return NULL;
}
}

template class boost::shared_ptr<RBX::GuiItem>;
