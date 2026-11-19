#include "v8datamodel/FlagStand.h"
#include "reflection/signal.h"
#include "v8datamodel/Flag.h"

namespace RBX
{
	char sFlagStand[] = "FlagStand"; // 0095be6c (doDeclare 005bf8e0, classDescriptor 005c38f0, constructor setName)

	// Template members the shared headers only declare (same definitions as Team.cpp / SpawnLocation.cpp).
	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::FactoryProduct() : D() {}

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	template<class C, class D, const char* N>
	DescribedCreatable<C, D, N>::DescribedCreatable()
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}

	static Reflection::PropDescriptor<FlagStand, BrickColor> prop_Color("TeamColor", "Data", &FlagStand::getTeamColor, &FlagStand::setTeamColor, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::SignalDesc<FlagStand, void(boost::shared_ptr<Instance>)> event_FlagCaptured("FlagCaptured", "Player");

	BrickColor FlagStand::getTeamColor() const
	{
		return teamColor;
	}

	FlagStand::FlagStand()
	{
		setName(sFlagStand);
	}

	Flag* FlagStand::GetFlag()
	{
		Primitive* primitive = getPrimitive();

		for (RigidJoint* current = primitive->getFirstRigid(); current != NULL; current = primitive->getNextRigid(current))
		{
			for (int i = 0; i < 2; i++)
			{
				Flag* flag = dynamic_cast<Flag*>(PartInstance::fromPrimitive(current->getPrimitive(i))->getParent());
				if (flag)
					return flag;
			}
		}

		return NULL;
	}

	void FlagStand::setTeamColor(BrickColor color)
	{
		teamColor = color;
		raisePropertyChanged(PartInstance::prop_Color);
	}
}

template class std::_Vector_const_iterator<RBX::Primitive const *,std::allocator<RBX::Primitive const *> >;
template class std::_Vector_iterator<RBX::Primitive const *,std::allocator<RBX::Primitive const *> >;
