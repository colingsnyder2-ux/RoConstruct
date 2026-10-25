// Rebuild glue: PartInstance surfaces (v8datamodel/Surfaces.h), which rbxgs declares but never defines,
// and the per-face reflected properties. Property names and categories are the 2008-06 Roblox.exe
// strings ("TopSurface", "TopSurfaceInput", "Surface Inputs", "TopParamA", "TopParamB", ... for Top,
// Bottom, Left, Right, Front, Back); InputType names are the exe strings before "InputType" ("Strafe"
// is pooled with the Humanoid string). Behavioural reconstruction, not byte-verified.
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Surfaces.h"
#include "v8datamodel/Surface.h"
#include "reflection/enumconverter.h"
#include "v8xml/XmlElement.h"

namespace RBX
{
	Reflection::EnumDesc<Controller::InputType>::EnumDesc()
		: EnumDescriptor("InputType", typeid(Controller::InputType))
	{
		addPair(Controller::NO_INPUT, "NoInput");
		addPair(Controller::LEFT_TRACK_INPUT, "LeftTread");
		addPair(Controller::RIGHT_TRACK_INPUT, "RightTread");
		addPair(Controller::RIGHT_LEFT_INPUT, "Steer");
		addPair(Controller::BACK_FORWARD_INPUT, "Throtle");
		addPair(Controller::STRAFE_INPUT, "Strafe");
		addPair(Controller::UP_DOWN_INPUT, "UpDown");
		addPair(Controller::BUTTON_1_INPUT, "Action1");
		addPair(Controller::BUTTON_2_INPUT, "Action2");
		addPair(Controller::BUTTON_3_INPUT, "Action3");
		addPair(Controller::BUTTON_4_INPUT, "Action4");
		addPair(Controller::BUTTON_3_4_INPUT, "Action5");
		addPair(Controller::CONSTANT_INPUT, "Constant");
		addPair(Controller::SIN_INPUT, "Sin");
	}

	namespace
	{
		Surface& faceOf(const Reflection::DescribedBase* instance, NormalId face)
		{
			PartInstance* part = const_cast<PartInstance*>(static_cast<const PartInstance*>(instance));
			return const_cast<Surfaces&>(part->getSurfaces())[face];
		}

		// an enum-valued face property (surface type or input), read and written through Surface
		template<typename Enum>
		class FaceEnumDescriptor : public Reflection::EnumPropertyDescriptor
		{
			NormalId face;
			Enum (Surface::*get)() const;
			void (Surface::*set)(Enum);

			const Reflection::EnumDesc<Enum>& desc() const { return Reflection::EnumDesc<Enum>::singleton(); }

		public:
			FaceEnumDescriptor(NormalId face, const char* name, const char* category, Enum (Surface::*get)() const, void (Surface::*set)(Enum))
				: EnumPropertyDescriptor(PartInstance::classDescriptor(), Reflection::EnumDesc<Enum>::singleton(), name, category, STANDARD),
				  face(face), get(get), set(set)
			{
			}

			Enum value(const Reflection::DescribedBase* instance) const { return (faceOf(instance, face).*get)(); }

			virtual bool isReadOnly() const { return false; }
			virtual bool equalValues(const Reflection::DescribedBase* a, const Reflection::DescribedBase* b) const { return value(a) == value(b); }
			virtual bool hasStringValue() const { return true; }
			virtual std::string getStringValue(const Reflection::DescribedBase* instance) const { return desc().convertToString(value(instance)); }
			virtual bool setStringValue(Reflection::DescribedBase* instance, const std::string& text) const
			{
				Enum v;
				if (!desc().convertToValue(text, v))
					return false;
				(faceOf(instance, face).*set)(v);
				return true;
			}
			virtual int getEnumValue(const Reflection::DescribedBase* instance) const { return value(instance); }
			virtual bool setEnumValue(Reflection::DescribedBase* instance, int v) const
			{
				(faceOf(instance, face).*set)(static_cast<Enum>(v));
				return true;
			}
			virtual unsigned getIndexValue(const Reflection::DescribedBase* instance) const { return (unsigned)desc().convertToIndex(value(instance)); }
			virtual bool setIndexValue(Reflection::DescribedBase* instance, unsigned index) const
			{
				Enum v;
				if (!desc().convertToValue((size_t)index, v))
					return false;
				(faceOf(instance, face).*set)(v);
				return true;
			}
			virtual void writeValue(const Reflection::DescribedBase* instance, XmlElement* element) const
			{
				element->setValue(static_cast<int>(value(instance)));
			}
			virtual void readValue(Reflection::DescribedBase* instance, const XmlElement* element, IReferenceBinder&) const
			{
				int v;
				if (!element->isXsiNil() && element->getValue(v))
					(faceOf(instance, face).*set)(static_cast<Enum>(v));
			}
		};

		// a float face parameter (motor speed etc.)
		class FaceParamGetSet : public Reflection::TypedPropertyDescriptor<float>::GetSet
		{
			NormalId face;
			float (Surface::*get)() const;
			void (Surface::*set)(float);

		public:
			FaceParamGetSet(NormalId face, float (Surface::*get)() const, void (Surface::*set)(float)) : face(face), get(get), set(set) {}
			virtual bool isReadOnly() const { return false; }
			virtual float getValue(const Reflection::DescribedBase* instance) const { return (faceOf(instance, face).*get)(); }
			virtual void setValue(Reflection::DescribedBase* instance, const float& v) const { (faceOf(instance, face).*set)(v); }
		};

		class FaceParamDescriptor : public Reflection::TypedPropertyDescriptor<float>
		{
		public:
			FaceParamDescriptor(NormalId face, const char* name, float (Surface::*get)() const, void (Surface::*set)(float))
				: TypedPropertyDescriptor<float>(PartInstance::classDescriptor(), name, "Surface Inputs",
												 std::auto_ptr<GetSet>(new FaceParamGetSet(face, get, set)), STANDARD)
			{
			}
		};

		struct FaceProperties
		{
			FaceEnumDescriptor<SurfaceType> type;
			FaceEnumDescriptor<Controller::InputType> input;
			FaceParamDescriptor paramA, paramB;

			FaceProperties(NormalId face, const char* surface, const char* input, const char* a, const char* b)
				: type(face, surface, "Surface", &Surface::getSurfaceType, &Surface::setSurfaceType),
				  input(face, input, "Surface Inputs", &Surface::getInput, &Surface::setSurfaceInput),
				  paramA(face, a, &Surface::getParamA, &Surface::setParamA),
				  paramB(face, b, &Surface::getParamB, &Surface::setParamB)
			{
			}
		};

		const FaceProperties& faceProperties(NormalId face)
		{
			static FaceProperties top(NORM_Y, "TopSurface", "TopSurfaceInput", "TopParamA", "TopParamB");
			static FaceProperties bottom(NORM_Y_NEG, "BottomSurface", "BottomSurfaceInput", "BottomParamA", "BottomParamB");
			static FaceProperties left(NORM_X_NEG, "LeftSurface", "LeftSurfaceInput", "LeftParamA", "LeftParamB");
			static FaceProperties right(NORM_X, "RightSurface", "RightSurfaceInput", "RightParamA", "RightParamB");
			static FaceProperties front(NORM_Z_NEG, "FrontSurface", "FrontSurfaceInput", "FrontParamA", "FrontParamB");
			static FaceProperties back(NORM_Z, "BackSurface", "BackSurfaceInput", "BackParamA", "BackParamB");
			switch (face)
			{
			case NORM_Y: return top;
			case NORM_Y_NEG: return bottom;
			case NORM_X_NEG: return left;
			case NORM_X: return right;
			case NORM_Z_NEG: return front;
			default: return back;
			}
		}

		// declared at startup so every part exposes the face properties
		struct DeclareFaceProperties
		{
			DeclareFaceProperties()
			{
				for (int face = 0; face < 6; ++face)
					faceProperties((NormalId)face);
			}
		} declareFaceProperties;
	}

	Surfaces::Surfaces(PartInstance* part)
		: Top(part, NORM_Y), Bottom(part, NORM_Y_NEG), Left(part, NORM_X_NEG),
		  Right(part, NORM_X), Front(part, NORM_Z_NEG), Back(part, NORM_Z)
	{
	}

	Surface& Surfaces::operator[](NormalId face)
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

	const Surface& Surfaces::operator[](NormalId face) const
	{
		return const_cast<Surfaces&>(*this)[face];
	}

	Vector6<SurfaceType> Surfaces::surf6() const
	{
		Vector6<SurfaceType> result;
		for (int face = 0; face < 6; ++face)
			result[face] = (*this)[(NormalId)face].getSurfaceType();
		return result;
	}

	const Reflection::PropertyDescriptor& Surfaces::getSurfaceType(NormalId face) const { return faceProperties(face).type; }
	const Reflection::PropertyDescriptor& Surfaces::getSurfaceInput(NormalId face) const { return faceProperties(face).input; }
	const Reflection::PropertyDescriptor& Surfaces::getParamA(NormalId face) const { return faceProperties(face).paramA; }
	const Reflection::PropertyDescriptor& Surfaces::getParamB(NormalId face) const { return faceProperties(face).paramB; }

	// the stock brick: studs on top, inlets underneath, smooth sides
	const bool Surfaces::isStandardPart() const
	{
		for (int face = 0; face < 6; ++face)
		{
			SurfaceType expected = face == NORM_Y ? STUDS : face == NORM_Y_NEG ? INLET : NO_SURFACE;
			if ((*this)[(NormalId)face].getSurfaceType() != expected)
				return false;
		}
		return true;
	}

	bool Surfaces::isSurfaceDescriptor(const Reflection::PropertyDescriptor& desc)
	{
		for (int face = 0; face < 6; ++face)
		{
			const FaceProperties& p = faceProperties((NormalId)face);
			if (&desc == &p.type || &desc == &p.input || &desc == &p.paramA || &desc == &p.paramB)
				return true;
		}
		return false;
	}
}
