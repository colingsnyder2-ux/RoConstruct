#pragma once
// >>> native-status (generated) -- do not edit >>>
// Surface | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 181a3af0 | roc native-status --write
#include "v8world/Controller.h"
#include "v8xml/XmlElement.h"
#include "util/SurfaceType.h"
#include "util/NormalId.h"

namespace RBX
{
	class PartInstance;
	class IReferenceBinder;

	class Surface
	{
	private:
		PartInstance* partInstance;
		NormalId surfId;
	public:
		void flat();
		Surface(PartInstance* partInstance, NormalId surfId);
		PartInstance* getPartInstance() const { return partInstance; }  // inline in the target: no function bound anywhere; field at +0, as in getSurfaceType 005f1290
		NormalId getNormalId() const { return surfId; }  // field at +4
		bool isControllable() const;
		SurfaceType getSurfaceType() const;
		void setSurfaceType(SurfaceType type);
		Controller::InputType getInput() const;
		void setSurfaceInput(Controller::InputType value);
		float getParamA() const;
		float getParamB() const;
		void setParamA(float value);
		void setParamB(float value);
		void toggleSurfaceType();
		void writeValue(XmlElement*) const;
		void readValue(const XmlElement*, IReferenceBinder&);
	};
}
