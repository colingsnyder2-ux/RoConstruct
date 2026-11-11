#pragma once
// >>> native-status (generated) -- do not edit >>>
// Surfaces | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src ad58e20e | roc native-status --write
#include <boost/noncopyable.hpp>
#include "v8datamodel/Surface.h"
#include "util/Vector6.h"

namespace RBX
{
	namespace Reflection { class PropertyDescriptor; }
	class PartInstance;

	class Surfaces : public boost::noncopyable
	{
	private:
		Surface Top, Bottom, Left, Right, Front, Back;
	public:
		Surfaces(PartInstance*);
		const Surface& operator[](NormalId) const;
		Surface& operator[](NormalId);
		Vector6<SurfaceType> surf6() const;
		const Reflection::PropertyDescriptor& getSurfaceType(NormalId) const;
		const Reflection::PropertyDescriptor& getSurfaceInput(NormalId) const;
		const Reflection::PropertyDescriptor& getParamA(NormalId) const;
		const Reflection::PropertyDescriptor& getParamB(NormalId) const;
		const bool isStandardPart() const;
		static bool isSurfaceDescriptor(const Reflection::PropertyDescriptor&);
	};
}
