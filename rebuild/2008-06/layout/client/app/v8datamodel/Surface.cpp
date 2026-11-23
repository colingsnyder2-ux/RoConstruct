#undef _RELEASEASSERT
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Surface.h"
#include "v8xml/XmlElement.h"
#include "reflection/enumconverter.h"
#include "util/Name.h"

namespace RBX
{
	void Surface::readValue(const XmlElement* element, IReferenceBinder& binder)
	{
		static const Name& desc_LegacyType = Name::declare("Type", -1);
		static const Name& desc_LegacySurfaceInput = Name::declare("SurfaceInput", -1);
		static const Name& desc_LegacyParamA = Name::declare("ParamA", -1);
		static const Name& desc_LegacyParamB = Name::declare("ParamB", -1);
		static const Name& desc_LegacyConstraint = Name::declare("Constraint", -1);

		const XmlElement* child = element->firstChild();
		while (child)
		{
			const Name* name = NULL;
			if (!child->isXsiNil() && child->findAttributeValue(name_name, name))
			{
				if (name == &desc_LegacyType)
				{
					std::string sValue;
					if (child->getValue(sValue))
					{
						SurfaceType e;
						if (Reflection::EnumDesc<SurfaceType>::singleton().convertToValue(Name::lookup(sValue.c_str()), e))
							setSurfaceType(e);
						else
							setSurfaceType(NO_SURFACE);
					}
				}
				else if (name == &desc_LegacySurfaceInput)
				{
					std::string sValue;
					if (child->getValue(sValue))
					{
						Controller::InputType e;
						if (Reflection::EnumDesc<Controller::InputType>::singleton().convertToValue(Name::lookup(sValue.c_str()), e))
							setSurfaceInput(e);
					}
				}
				else if (name == &desc_LegacyParamA)
				{
					float value;
					if (child->getValue(value))
						setParamA(value);
				}
				else if (name == &desc_LegacyParamB)
				{
					float value;
					if (child->getValue(value))
						setParamB(value);
				}
				else if (name == &desc_LegacyConstraint)
				{
					std::string sValue;
					if (child->getValue(sValue))
					{
						SurfaceType e;
						if (Reflection::EnumDesc<SurfaceType>::singleton().convertToValue(Name::lookup(sValue.c_str()), e) && e != NO_SURFACE)
							setSurfaceType(e);
					}
				}
			}
			child = child->nextSibling();
		}
	}
}

namespace RBX {
Surface::Surface(PartInstance* partInstance, NormalId surfId)
		: partInstance(partInstance),
		  surfId(surfId)
	{
	}
}

namespace RBX {
bool Surface::isControllable() const
	{
		Controller::InputType inputType = getInput();
		return inputType != Controller::NO_INPUT && inputType != Controller::CONSTANT_INPUT && inputType != Controller::SIN_INPUT;
	}
}

#undef _RELEASEASSERT

namespace RBX {
void Surface::flat()
{
    if (partInstance->primitive.getSurfaceType(surfId) != NO_SURFACE) {
        partInstance->primitive.setSurfaceType(surfId, NO_SURFACE);
        partInstance->onSurfaceChanged(surfId);
        partInstance->raisePropertyChanged(partInstance->getSurfaces().getSurfaceType(surfId));
    }
    setSurfaceInput(SurfaceData::empty().inputType);
    setParamA(SurfaceData::empty().paramA);
    setParamB(SurfaceData::empty().paramB);
}
}

#undef _RELEASEASSERT
#include "v8datamodel/Surfaces.h"

namespace RBX {

SurfaceType Surface::getSurfaceType() const
{
	return partInstance->primitive.getSurfaceType(surfId);
}

void Surface::setSurfaceType(SurfaceType type)
{
	if (type != partInstance->primitive.getSurfaceType(surfId)) {
		partInstance->primitive.setSurfaceType(surfId, type);
		partInstance->onSurfaceChanged(surfId);
		partInstance->raisePropertyChanged(partInstance->getSurfaces().getSurfaceType(surfId));
	}
}

void Surface::setSurfaceInput(Controller::InputType value)
{
	SurfaceData data = partInstance->primitive.getSurfaceData(surfId);
	if (value != data.inputType) {
		data.inputType = value;
		partInstance->primitive.setSurfaceData(surfId, data);
		partInstance->onSurfaceChanged(surfId);
		partInstance->raisePropertyChanged(partInstance->getSurfaces().getSurfaceInput(surfId));
	}
}

void Surface::setParamA(float value)
{
	SurfaceData data = partInstance->primitive.getSurfaceData(surfId);
	if (data.paramA != value) {
		data.paramA = value;
		partInstance->primitive.setSurfaceData(surfId, data);
		partInstance->onSurfaceChanged(surfId);
		partInstance->raisePropertyChanged(partInstance->getSurfaces().getParamA(surfId));
	}
}

void Surface::setParamB(float value)
{
	SurfaceData data = partInstance->primitive.getSurfaceData(surfId);
	if (data.paramB != value) {
		data.paramB = value;
		partInstance->primitive.setSurfaceData(surfId, data);
		partInstance->onSurfaceChanged(surfId);
		partInstance->raisePropertyChanged(partInstance->getSurfaces().getParamB(surfId));
	}
}

}
