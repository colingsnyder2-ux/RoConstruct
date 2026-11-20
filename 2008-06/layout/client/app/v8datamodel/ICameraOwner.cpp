// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-embedded
// 2008-06 native RBX::ICameraOwner (inactive): the original unit 00641d20..00641fef (between the ICharacterSubject
// unit 00641240..00641d1f and Widget 00641ff0). Bodies after the donor tools/rbxgs v8datamodel/ICameraOwner.cpp on the
// donor ICameraOwner.h (vtable at +0, cameraIgnoreParts vector at +4). Identities from
// work/2008-06/identity-registry.json; the only known caller of 00641f40 is MegaDragger::startDragging 0060de5f.
// PartInstance embeds its Primitive (+0x228 in getCameraIgnorePrimitives), hence the part-embedded headers.
#include "v8datamodel/ICameraOwner.h"
#include "v8datamodel/PartInstance.h"

namespace RBX
{
	// 00641d20: weak_ptr<Instance>::lock 005cab00 (folded), PartInstance::getPrimitive (inline, +0x228),
	// vector<const Primitive*>::push_back 004213a0 (folded).
	void ICameraOwner::getCameraIgnorePrimitives(std::vector<const Primitive*>& primitives)
	{
		for (size_t i = 0; i < cameraIgnoreParts.size(); i++)
		{
			if (!cameraIgnoreParts[i].expired())
			{
				PartInstance* part = cameraIgnoreParts[i].lock().get();
				Primitive* prim = part->getPrimitive();

				primitives.push_back(prim);
			}
		}
	}

	// 00641f40: vector<PartInstance*> temporary (new(4) _Aux_cont proxy), push_back 004213a0 (folded), then
	// setCameraIgnoreParts(const vector&) 00641e00.
	void ICameraOwner::setCameraIgnoreParts(PartInstance* _set)
	{
		std::vector<PartInstance*> temp;
		temp.push_back(_set);

		setCameraIgnoreParts(temp);
	}

	// 00641e00: clear() through vector::erase 0060e390 (folded), shared_from<PartInstance> 00618a40, weak_ptr
	// push_back 0059c3b0.
	void ICameraOwner::setCameraIgnoreParts(const std::vector<PartInstance*>& _set)
	{
		cameraIgnoreParts.clear();

		for (size_t i = 0; i < _set.size(); i++)
		{
			PartInstance* part = _set[i];
			boost::weak_ptr<PartInstance> ptr = shared_from(part);

			cameraIgnoreParts.push_back(ptr);
		}
	}
}
