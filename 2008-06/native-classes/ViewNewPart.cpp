// native-flags: /O2 /GS- /EHsc /MD /fp:fast /Ob1
// 2008-06 native RBX::ViewNew::Part / PartChunk bodies that need the complete PartInstance (inactive): cframe,
// ~Part, Part's invalidate slot and the Decal / Texture property handlers (Texture's 004e6bc0 is a block-order
// near-miss: recorded, not counted). Bodies that read PartInstance fields (+0x1c8 / +0x1dc / +0x224) or the view's
// scene manager are not built; see native-headers/ViewNew/PartChunk.h.
// >>> native-status (generated) -- do not edit >>>
// ViewNewPart | 2008-06 | 3 byte-exact, inactive (not link-selected)
// 3/8 mapped addresses byte-exact | 5 unproved | no mapped strings | by king_originala (+3) (mixed 3)
// <<< native-status | src e8aa6d57 | roc native-status --write
#include "ViewNew/PartChunk.h"
#include "RenderLib/ViewBase2008.h"
#include "v8datamodel/PartInstance.h"
// Native v8datamodel/Decal.h: the 2008 class names are char arrays (RTTI $1?sDecal@2@3PADA / $1?sTexture@2@3PADA).
#include "v8datamodel/Decal.h"

namespace RBX
{
	namespace ViewNew
	{
		const G3D::CoordinateFrame& PartChunk::cframe()
		{
			coordinateFrame = partInstance->getCoordinateFrame();
			return coordinateFrame;
		}

		Part::~Part()
		{
			if (partInstance)
				partInstance->Notifier<PartInstance, CanAggregateChanged>::removeListener(this);
		}

		// PartInstance::prop_Color 0097610c, prop_Transparency 00976128 ("Transparency"), prop_Reflectance 0097601c
		// ("Reflectance"): the descriptor names come from their initializers 007f46f0 / 007f4750.
		void Part::onPropertyChanged(const Reflection::PropertyDescriptor* descriptor)
		{
			PartChunk::onPropertyChanged(descriptor);

			if (*descriptor == PartInstance::prop_Color)
			{
				if (usesMegaTexture())
					invalidateMesh();
				invalidateMaterial();
			}
			else if (*descriptor == PartInstance::prop_Transparency || *descriptor == PartInstance::prop_Reflectance)
			{
				invalidateMaterial();
			}
		}

		void Part::invalidate()
		{
			invalidateMaterial();
			invalidateMesh();
		}

		bool Part::usesMegaTexture() const
		{
			if (specialShape == NULL && partInstance->getPartType() == RBX::Part::BLOCK_PART)
			{
				G3D::Vector3 size = partInstance->getPartSizeXml();
				float x = fabs(size.x);
				float y = fabs(size.y);
				float z = fabs(size.z);
				float m = x > y ? x : y;
				return (z < m ? m : z) < 30.0f;
			}
			return false;
		}

		void Part::onEvent(const PartInstance* source, CanAggregateChanged event)
		{
			{
				G3D::ReferenceCountedPointer<RenderBase::Chunk> chunk(this);
				view->sceneManager->setSleeping(chunk, event.canClump);
			}
			if (!event.canClump)
			{
				if (getSortValue() < 0.5f)
					setSortValue(0.5f);
			}
			else
			{
				if (getSortValue() < 1.0f)
					setSortValue(0.0f);
			}
		}

		// FaceInstance::prop_Face 0097b57c ("Face"), Decal::prop_Texture 00975f14 / prop_Specular 00975ef8 /
		// prop_Shiny 00975f30, Texture::prop_StudsPerTileU 00975f68 / prop_StudsPerTileV 00975f4c (initializers
		// 007f7600 and 007f4190..007f4290 name them).
		void Decal::onDecalPropertyChanged(const Reflection::PropertyDescriptor* descriptor)
		{
			if (*descriptor == FaceInstance::prop_Face)
				invalidateMesh();
			else if (*descriptor == RBX::Decal::prop_Texture || *descriptor == RBX::Decal::prop_Specular || *descriptor == RBX::Decal::prop_Shiny)
				invalidateMaterial();
		}

		void Texture::onTexturePropertyChanged(const Reflection::PropertyDescriptor* descriptor)
		{
			if (*descriptor == FaceInstance::prop_Face)
				invalidateMesh();
			else if (*descriptor == RBX::Decal::prop_Texture || *descriptor == RBX::Decal::prop_Specular || *descriptor == RBX::Decal::prop_Shiny)
				invalidateMaterial();
			else if (*descriptor == RBX::Texture::prop_StudsPerTileU || *descriptor == RBX::Texture::prop_StudsPerTileV)
				invalidateMesh();
		}
	}
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class RBX::Listener<RBX::PartInstance,RBX::CanAggregateChanged>;
template class std::_Vector_const_iterator<RBX::Listener<RBX::PartInstance,RBX::CanAggregateChanged> *,std::allocator<RBX::Listener<RBX::PartInstance,RBX::CanAggregateChanged> *> >;
template class std::_Vector_iterator<RBX::Listener<RBX::PartInstance,RBX::CanAggregateChanged> *,std::allocator<RBX::Listener<RBX::PartInstance,RBX::CanAggregateChanged> *> >;
