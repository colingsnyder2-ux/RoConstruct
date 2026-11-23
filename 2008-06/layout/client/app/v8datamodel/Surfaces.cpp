#undef _RELEASEASSERT
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Surfaces.h"
#include "reflection/reflection.h"

namespace RBX
{
	// INFERRED: base classes Reflection::EnumPropertyDescriptor / TypedPropertyDescriptor<T>, by analogy with
	inline Surface& Surfaces::operator[](NormalId face)
	{
		switch (face)
		{
		case NORM_Y: return Top;
		case NORM_Y_NEG: return Bottom;
		case NORM_X_NEG: return Left;
		case NORM_X: return Right;
		case NORM_Z_NEG: return Front;
		default: return Back;
		}
	}

	// INFERRED: nested GetSetImpl modelled on Reflection::PropDescriptor::GetSetImpl; the object is the PartInstance
	// (DescribedBase +0x14, null-checked cast) and the member pointers (+4 getter, +8 setter) are Surface members.
	template<NormalId face, typename Enum>
	class SurfaceEnumPropDescriptor : public Reflection::EnumPropertyDescriptor
	{
	private:
		template<typename GetFunction, typename SetFunction>
		class GetSetImpl : public Reflection::TypedPropertyDescriptor<Enum>::GetSet
		{
		private:
			GetFunction get;
			SetFunction set;
		public:
			GetSetImpl(GetFunction get, SetFunction set) : get(get), set(set) {}
			virtual bool isReadOnly() const { return false; }
			virtual bool isWriteOnly() const { return false; }
			virtual Enum getValue(const Reflection::DescribedBase* object) const
			{
				PartInstance* o = (PartInstance*)object;
				return (o->getSurfaces()[face].*get)();
			}
			virtual void setValue(Reflection::DescribedBase* object, const Enum& value) const
			{
				PartInstance* o = (PartInstance*)object;
				(o->getSurfaces()[face].*set)(value);
			}
		};
		std::auto_ptr<typename Reflection::TypedPropertyDescriptor<Enum>::GetSet> getset;
	public:
		template<typename GetFunction, typename SetFunction>
		SurfaceEnumPropDescriptor(char const* name, char const* category, GetFunction get, SetFunction set,
			Reflection::PropertyDescriptor::Functionality flags)
			: Reflection::EnumPropertyDescriptor(PartInstance::classDescriptor(), Reflection::EnumDesc<Enum>::singleton(), name, category, flags),
			  getset(new GetSetImpl<GetFunction, SetFunction>(get, set))
		{
		}
		virtual bool isReadOnly() const;
		virtual int getEnumValue(const Reflection::DescribedBase*) const;
		virtual bool setEnumValue(Reflection::DescribedBase*, int) const;
		virtual bool equalValues(const Reflection::DescribedBase*, const Reflection::DescribedBase*) const;
		virtual bool hasStringValue() const;
		virtual std::string getStringValue(const Reflection::DescribedBase*) const;
		virtual bool setStringValue(Reflection::DescribedBase*, const std::string&) const;
		virtual void writeValue(const Reflection::DescribedBase*, XmlElement*) const;
		virtual void readValue(Reflection::DescribedBase*, const XmlElement*, IReferenceBinder&) const;
		virtual unsigned getIndexValue(const Reflection::DescribedBase*) const;
		virtual bool setIndexValue(Reflection::DescribedBase*, unsigned) const;
	};

	template<NormalId face, typename T>
	class SurfacePropDescriptor : public Reflection::TypedPropertyDescriptor<T>
	{
	private:
		template<typename GetFunction, typename SetFunction>
		class GetSetImpl : public Reflection::TypedPropertyDescriptor<T>::GetSet
		{
		private:
			GetFunction get;
			SetFunction set;
		public:
			GetSetImpl(GetFunction get, SetFunction set) : get(get), set(set) {}
			virtual bool isReadOnly() const { return false; }
			virtual bool isWriteOnly() const { return false; }
			virtual T getValue(const Reflection::DescribedBase* object) const
			{
				PartInstance* o = (PartInstance*)object;
				return (o->getSurfaces()[face].*get)();
			}
			virtual void setValue(Reflection::DescribedBase* object, const T& value) const
			{
				PartInstance* o = (PartInstance*)object;
				(o->getSurfaces()[face].*set)(value);
			}
		};
	public:
		template<typename GetFunction, typename SetFunction>
		SurfacePropDescriptor(char const* name, char const* category, GetFunction get, SetFunction set,
			Reflection::PropertyDescriptor::Functionality flags)
			: Reflection::TypedPropertyDescriptor<T>(PartInstance::classDescriptor(), name, category,
				std::auto_ptr<typename Reflection::TypedPropertyDescriptor<T>::GetSet>(new GetSetImpl<GetFunction, SetFunction>(get, set)), flags)
		{
		}
	};

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

	Surfaces::Surfaces(PartInstance* partInstance)
		: Top(partInstance, NORM_Y), Bottom(partInstance, NORM_Y_NEG), Left(partInstance, NORM_X_NEG),
		  Right(partInstance, NORM_X), Front(partInstance, NORM_Z_NEG), Back(partInstance, NORM_Z)
	{
	}

	const bool Surfaces::isStandardPart() const
	{
		return Bottom.getSurfaceType() == INLET && Front.getSurfaceType() == NO_SURFACE
			&& Back.getSurfaceType() == NO_SURFACE && Left.getSurfaceType() == NO_SURFACE
			&& Right.getSurfaceType() == NO_SURFACE;
	}
}

#include "v8datamodel/Surface.h"

namespace RBX
{
	namespace Reflection
	{
		template<>
		const Type& Type::singleton<Surface>()
		{
			static Type type("Surface", typeid(Surface), "Complex");
			return type;
		}

		// INFERRED: stand-in, no exe counterpart.
		template<>
		const Type& Type::singleton<Tuple>()
		{
			static Type type("Tuple", typeid(Tuple), "Complex");
			return type;
		}

		// INFERRED: stand-in, no exe counterpart.
		template<>
		const Type& Type::singleton<PartInstance::FormFactor>()
		{
			static Type type("FormFactor", typeid(PartInstance::FormFactor), "Enum");
			return type;
		}
	}
}
