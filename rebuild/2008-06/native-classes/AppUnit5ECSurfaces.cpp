// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 v8datamodel/Surfaces.cpp (application range 005ec000..005f0000): Surfaces members plus the 24 per-face
// property descriptor statics they return. Inactive native unit against the read-only native v8datamodel/Surfaces.h.
// Layout (constructor 005ecbb0): six 8-byte Surface members, Top +0x0 (NORM_Y), Bottom +0x8 (NORM_Y_NEG),
// Left +0x10 (NORM_X_NEG), Right +0x18 (NORM_X), Front +0x20 (NORM_Z_NEG), Back +0x28 (NORM_Z), each built by
// Surface(PartInstance*, NormalId) 005f1270.
#undef _RELEASEASSERT
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Surfaces.h"
#include "reflection/reflection.h"

namespace RBX
{
	// Per-face property descriptor templates. Names, template arguments (face NormalId, value type), the constructor
	// signature (name, category, Surface getter, Surface setter, Functionality) and the nested GetSetImpl come from the
	// decorated names in the target: ctor 005edd40 ??$?0...?$SurfacePropDescriptor@$00M@RBX@@QAE@PBD0P8Surface@1@BEMXZ
	// P821@AEXM@ZW4Functionality@PropertyDescriptor@Reflection@1@@Z, vtables 0083fe94..00840340, GetSetImpl
	// getValue/setValue 005ecd60..005ed0e0. Only the declarations the Surfaces lookups need are recovered here.
	// INFERRED: base classes Reflection::EnumPropertyDescriptor / TypedPropertyDescriptor<T>, by analogy with
	// Reflection::EnumPropDescriptor / PropDescriptor (same GetSetImpl nesting and constructor shape).
	template<NormalId face, typename Enum>
	class SurfaceEnumPropDescriptor : public Reflection::EnumPropertyDescriptor
	{
	public:
		template<typename GetFunction, typename SetFunction>
		SurfaceEnumPropDescriptor(char const* name, char const* category, GetFunction get, SetFunction set,
			Reflection::PropertyDescriptor::Functionality flags);
		// Overrides in vtables 0083fe94 / 0083fee4 (bodies not recovered in this unit).
		virtual bool isReadOnly() const;
		virtual bool equalValues(const Reflection::DescribedBase*, const Reflection::DescribedBase*) const;
		virtual bool hasStringValue() const;
		virtual std::string getStringValue(const Reflection::DescribedBase*) const;
		virtual bool setStringValue(Reflection::DescribedBase*, const std::string&) const;
		virtual void writeValue(const Reflection::DescribedBase*, XmlElement*) const;
		virtual void readValue(Reflection::DescribedBase*, const XmlElement*, IReferenceBinder&) const;
		virtual unsigned getIndexValue(const Reflection::DescribedBase*) const;
		virtual bool setIndexValue(Reflection::DescribedBase*, unsigned) const;
		virtual int getEnumValue(const Reflection::DescribedBase*) const;
		virtual bool setEnumValue(Reflection::DescribedBase*, int) const;
	};

	template<NormalId face, typename T>
	class SurfacePropDescriptor : public Reflection::TypedPropertyDescriptor<T>
	{
	public:
		template<typename GetFunction, typename SetFunction>
		SurfacePropDescriptor(char const* name, char const* category, GetFunction get, SetFunction set,
			Reflection::PropertyDescriptor::Functionality flags);
	};

	// Dynamic initializers 007f7180..007f75d0 (in this order); data 0097b128..0097b468.
	static SurfaceEnumPropDescriptor<NORM_Y, SurfaceType> desc_TopType("TopSurface", "Surface", &Surface::getSurfaceType, &Surface::setSurfaceType, Reflection::PropertyDescriptor::STANDARD);
	static SurfaceEnumPropDescriptor<NORM_Y, Controller::InputType> desc_TopSurfaceInput("TopSurfaceInput", "Surface Inputs", &Surface::getInput, &Surface::setSurfaceInput, Reflection::PropertyDescriptor::STANDARD);
	static SurfacePropDescriptor<NORM_Y, float> desc_TopParamA("TopParamA", "Surface Inputs", &Surface::getParamA, &Surface::setParamA, Reflection::PropertyDescriptor::STANDARD);
	static SurfacePropDescriptor<NORM_Y, float> desc_TopParamB("TopParamB", "Surface Inputs", &Surface::getParamB, &Surface::setParamB, Reflection::PropertyDescriptor::STANDARD);
	static SurfaceEnumPropDescriptor<NORM_Y_NEG, SurfaceType> desc_BottomType("BottomSurface", "Surface", &Surface::getSurfaceType, &Surface::setSurfaceType, Reflection::PropertyDescriptor::STANDARD);
	static SurfaceEnumPropDescriptor<NORM_Y_NEG, Controller::InputType> desc_BottomSurfaceInput("BottomSurfaceInput", "Surface Inputs", &Surface::getInput, &Surface::setSurfaceInput, Reflection::PropertyDescriptor::STANDARD);
	static SurfacePropDescriptor<NORM_Y_NEG, float> desc_BottomParamA("BottomParamA", "Surface Inputs", &Surface::getParamA, &Surface::setParamA, Reflection::PropertyDescriptor::STANDARD);
	static SurfacePropDescriptor<NORM_Y_NEG, float> desc_BottomParamB("BottomParamB", "Surface Inputs", &Surface::getParamB, &Surface::setParamB, Reflection::PropertyDescriptor::STANDARD);
	static SurfaceEnumPropDescriptor<NORM_X_NEG, SurfaceType> desc_LeftType("LeftSurface", "Surface", &Surface::getSurfaceType, &Surface::setSurfaceType, Reflection::PropertyDescriptor::STANDARD);
	static SurfaceEnumPropDescriptor<NORM_X_NEG, Controller::InputType> desc_LeftSurfaceInput("LeftSurfaceInput", "Surface Inputs", &Surface::getInput, &Surface::setSurfaceInput, Reflection::PropertyDescriptor::STANDARD);
	static SurfacePropDescriptor<NORM_X_NEG, float> desc_LeftParamA("LeftParamA", "Surface Inputs", &Surface::getParamA, &Surface::setParamA, Reflection::PropertyDescriptor::STANDARD);
	static SurfacePropDescriptor<NORM_X_NEG, float> desc_LeftParamB("LeftParamB", "Surface Inputs", &Surface::getParamB, &Surface::setParamB, Reflection::PropertyDescriptor::STANDARD);
	static SurfaceEnumPropDescriptor<NORM_X, SurfaceType> desc_RightType("RightSurface", "Surface", &Surface::getSurfaceType, &Surface::setSurfaceType, Reflection::PropertyDescriptor::STANDARD);
	static SurfaceEnumPropDescriptor<NORM_X, Controller::InputType> desc_RightSurfaceInput("RightSurfaceInput", "Surface Inputs", &Surface::getInput, &Surface::setSurfaceInput, Reflection::PropertyDescriptor::STANDARD);
	static SurfacePropDescriptor<NORM_X, float> desc_RightParamA("RightParamA", "Surface Inputs", &Surface::getParamA, &Surface::setParamA, Reflection::PropertyDescriptor::STANDARD);
	static SurfacePropDescriptor<NORM_X, float> desc_RightParamB("RightParamB", "Surface Inputs", &Surface::getParamB, &Surface::setParamB, Reflection::PropertyDescriptor::STANDARD);
	static SurfaceEnumPropDescriptor<NORM_Z_NEG, SurfaceType> desc_FrontType("FrontSurface", "Surface", &Surface::getSurfaceType, &Surface::setSurfaceType, Reflection::PropertyDescriptor::STANDARD);
	static SurfaceEnumPropDescriptor<NORM_Z_NEG, Controller::InputType> desc_FrontSurfaceInput("FrontSurfaceInput", "Surface Inputs", &Surface::getInput, &Surface::setSurfaceInput, Reflection::PropertyDescriptor::STANDARD);
	static SurfacePropDescriptor<NORM_Z_NEG, float> desc_FrontParamA("FrontParamA", "Surface Inputs", &Surface::getParamA, &Surface::setParamA, Reflection::PropertyDescriptor::STANDARD);
	static SurfacePropDescriptor<NORM_Z_NEG, float> desc_FrontParamB("FrontParamB", "Surface Inputs", &Surface::getParamB, &Surface::setParamB, Reflection::PropertyDescriptor::STANDARD);
	static SurfaceEnumPropDescriptor<NORM_Z, SurfaceType> desc_BackType("BackSurface", "Surface", &Surface::getSurfaceType, &Surface::setSurfaceType, Reflection::PropertyDescriptor::STANDARD);
	static SurfaceEnumPropDescriptor<NORM_Z, Controller::InputType> desc_BackSurfaceInput("BackSurfaceInput", "Surface Inputs", &Surface::getInput, &Surface::setSurfaceInput, Reflection::PropertyDescriptor::STANDARD);
	static SurfacePropDescriptor<NORM_Z, float> desc_BackParamA("BackParamA", "Surface Inputs", &Surface::getParamA, &Surface::setParamA, Reflection::PropertyDescriptor::STANDARD);
	static SurfacePropDescriptor<NORM_Z, float> desc_BackParamB("BackParamB", "Surface Inputs", &Surface::getParamB, &Surface::setParamB, Reflection::PropertyDescriptor::STANDARD);

	// 005ec9f0 (target decorated name returns const bool: ?isSurfaceDescriptor@Surfaces@RBX@@SA?B_N...; the read-only
	// header declares plain bool). The if chain gives the target's mov al,1 / final sete al; an || chain and an if chain
	// ending in "return &descriptor == &desc_BackType" do not.
	bool Surfaces::isSurfaceDescriptor(const Reflection::PropertyDescriptor& descriptor)
	{
		if (&descriptor == &desc_TopType) return true;
		if (&descriptor == &desc_BottomType) return true;
		if (&descriptor == &desc_LeftType) return true;
		if (&descriptor == &desc_RightType) return true;
		if (&descriptor == &desc_FrontType) return true;
		if (&descriptor == &desc_BackType) return true;
		return false;
	}

	// 005eca30, 005eca90, 005ecaf0, 005ecb50: the four lookups compile byte-identical to the target with relocations
	// masked (jump table NORM_X..NORM_Z_NEG -> Right/Top/Back/Left/Bottom/Front; default shares the Top block). Their
	// return targets are the descriptors constructed by the initializers 007f7180..007f75d0 (e.g. 005eca90 returns
	// 0097b164 = desc_TopSurfaceInput for NORM_Y), which fixes which accessor each address is.
	// 005eca30
	const Reflection::PropertyDescriptor& Surfaces::getSurfaceType(NormalId face) const
	{
		switch (face)
		{
		case NORM_X:
			return desc_RightType;
		case NORM_Z:
			return desc_BackType;
		case NORM_X_NEG:
			return desc_LeftType;
		case NORM_Y_NEG:
			return desc_BottomType;
		case NORM_Z_NEG:
			return desc_FrontType;
		default:
		case NORM_Y:
			return desc_TopType;
		}
	}

	// 005eca90
	const Reflection::PropertyDescriptor& Surfaces::getSurfaceInput(NormalId face) const
	{
		switch (face)
		{
		case NORM_X:
			return desc_RightSurfaceInput;
		case NORM_Z:
			return desc_BackSurfaceInput;
		case NORM_X_NEG:
			return desc_LeftSurfaceInput;
		case NORM_Y_NEG:
			return desc_BottomSurfaceInput;
		case NORM_Z_NEG:
			return desc_FrontSurfaceInput;
		default:
		case NORM_Y:
			return desc_TopSurfaceInput;
		}
	}

	// 005ecaf0
	const Reflection::PropertyDescriptor& Surfaces::getParamA(NormalId face) const
	{
		switch (face)
		{
		case NORM_X:
			return desc_RightParamA;
		case NORM_Z:
			return desc_BackParamA;
		case NORM_X_NEG:
			return desc_LeftParamA;
		case NORM_Y_NEG:
			return desc_BottomParamA;
		case NORM_Z_NEG:
			return desc_FrontParamA;
		default:
		case NORM_Y:
			return desc_TopParamA;
		}
	}

	// 005ecb50
	const Reflection::PropertyDescriptor& Surfaces::getParamB(NormalId face) const
	{
		switch (face)
		{
		case NORM_X:
			return desc_RightParamB;
		case NORM_Z:
			return desc_BackParamB;
		case NORM_X_NEG:
			return desc_LeftParamB;
		case NORM_Y_NEG:
			return desc_BottomParamB;
		case NORM_Z_NEG:
			return desc_FrontParamB;
		default:
		case NORM_Y:
			return desc_TopParamB;
		}
	}

	// 005ecbb0
	Surfaces::Surfaces(PartInstance* partInstance)
		: Top(partInstance, NORM_Y), Bottom(partInstance, NORM_Y_NEG), Left(partInstance, NORM_X_NEG),
		  Right(partInstance, NORM_X), Front(partInstance, NORM_Z_NEG), Back(partInstance, NORM_Z)
	{
	}

	// 005ecc50: Bottom INLET (4), then Front / Back / Left / Right NO_SURFACE (Surface::getSurfaceType 005f1290)
	const bool Surfaces::isStandardPart() const
	{
		return Bottom.getSurfaceType() == INLET && Front.getSurfaceType() == NO_SURFACE
			&& Back.getSurfaceType() == NO_SURFACE && Left.getSurfaceType() == NO_SURFACE
			&& Right.getSurfaceType() == NO_SURFACE;
	}
}
