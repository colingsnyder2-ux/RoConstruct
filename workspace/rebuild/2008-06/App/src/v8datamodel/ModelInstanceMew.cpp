// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#undef _RELEASEASSERT
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/PartInstance.h"
#include "v8world/Primitive.h"
#include "tool/DragUtilities.h"
#include "AppDraw/Draw.h"
namespace RBX {
	void ModelInstance::updatePrimaryPart(PartInstance* set) const   // 00583a40
	{
		if (primaryPart == set)
		{
		}
		else if (set)
		{
			if (primaryPart)
			{
				G3D::Matrix3 oldMe = getLocation().rotation;
				modelInPrimary = G3D::CoordinateFrame(primaryPart->getCoordinateFrame().rotation.transpose() * oldMe, G3D::Vector3::zero());
				primaryPart = set;
			}
			else
			{
				modelInPrimary = G3D::CoordinateFrame();
				primaryPart = set;
			}
		}
		else
		{
			modelInPrimary = G3D::CoordinateFrame();
			primaryPart = NULL;
		}
	}

	Extents ModelInstance::computeWorldGridExtents() const   // 00583c90
	{
		return LocalGridExtents.getValue().express(getLocation(), G3D::CoordinateFrame());
	}

	const G3D::CoordinateFrame ModelInstance::getLocation() const   // 00583cf0
	{
		if (getPrimaryPartConst())
		{
			G3D::CoordinateFrame cf = primaryPart->getCoordinateFrame();
			return G3D::CoordinateFrame(cf.rotation * modelInPrimary.rotation, cf.translation);
		}

		return G3D::CoordinateFrame();
	}

	void ModelInstance::render3dSelect(Adorn* adorn, SelectState selectState)   // 00583da0 (Part ctor 00583980)
	{
		Extents localExtents = getExtentsLocal();
		G3D::CoordinateFrame location = getLocation();
		location.translation = location.pointToWorldSpace(localExtents.center());

		Part part(Part::BLOCK_PART, localExtents.size(), G3D::Color3::white(), location);
		Draw::selectionBox(part, adorn, selectState);
	}


	void ModelInstance::onExtentsChanged() const
	{
		LocalGridExtents.setDirty();
		WorldGridExtents.setDirty();
		FlagHeight.setDirty();
		PVInstance::onExtentsChanged();
	}

	static void makeJ(Instance* instance)   // 00584b30
	{
		PartInstance* partInstance = dynamic_cast<PartInstance*>(instance);
		if (partInstance)
		{
			partInstance->join();
		}
		else
		{
			ModelInstance* modelInstance = dynamic_cast<ModelInstance*>(instance);
			if (modelInstance)
				modelInstance->for_eachChild(makeJ);
		}
	}

	void ModelInstance::makeJoints()   // 00584b90
	{
		for_eachChild(makeJ);
	}

	static void breakJ(Instance* instance)   // 00584ba0
	{
		PartInstance* partInstance = dynamic_cast<PartInstance*>(instance);
		if (partInstance)
		{
			partInstance->destroyJoints();
		}
		else
		{
			ModelInstance* modelInstance = dynamic_cast<ModelInstance*>(instance);
			if (modelInstance)
				modelInstance->for_eachChild(breakJ);
		}
	}

	void ModelInstance::breakJoints()   // 00584c00
	{
		for_eachChild(breakJ);
	}
}
