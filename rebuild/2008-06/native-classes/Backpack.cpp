// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS-
// 2008-06 native RBX::Backpack (inactive): the Backpack part of the original Hopper unit (005d16d0..005d1b70).
// Evidence in native-headers/v8datamodel/Backpack.h (IScriptOwner from the native script/Script.h).
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

	// Names the Hopper.cpp descriptor object (00979cf4, dynamic initializer 007f5e30). INFERRED: external linkage; in
	// Hopper.cpp it is still `static` (proposal to its owner), so this declaration only fixes the relocation identity.
	extern Reflection::EnumPropDescriptor<HopperBin, HopperBin::BinType> desc_BinType;

	// 005d16d0 (setter of desc_BinType, first row of the Hopper unit tail with Backpack): raisePropertyChanged
	// 0040db00(00979cf4); for a non-script bin, EnumDesc<BinType>::singleton() (call_once 00557330(005d0360, flag
	// 00979cb4) then doSingleton 005d0300), convertToString 00448360 of the member, setLegacyTextureName 005d13d0.
	// Trial 1 (`binType != value`, the string passed as a temporary) gave `cmp [edi+0x1a0], eax` and `push eax`; the
	// target compares `cmp eax, [edi+0x1a0]` (value first) and re-materialises `lea edx, [esp+8]` (a named local).
	void HopperBin::setBinType(const BinType value)
	{
		if (value != binType)
		{
			binType = value;
			raisePropertyChanged(desc_BinType);
			if (binType != SCRIPT_BIN)
			{
				std::string name = Reflection::EnumDesc<BinType>::singleton().convertToString(binType);
				setLegacyTextureName(name);
			}
		}
	}

	Backpack::Backpack()
	{
		setName("Backpack");
	}

	// 005d18e0
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

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::shared_ptr<RBX::GuiItem>;
