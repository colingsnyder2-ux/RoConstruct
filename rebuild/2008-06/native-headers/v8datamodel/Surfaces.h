#pragma once
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
	public:
		void readProperties(const XmlElement* element, IReferenceBinder& binder);   // INFERRED (header-add): evidence: 005eece0 call 0x5f17a0 with ecx = result of PartInstance::getSurfaces (Surfaces&), args (const XmlElement*, IReferenceBinder&) - byte-proved by 005eecc0
	};
}
