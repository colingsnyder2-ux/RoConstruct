// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// Live implementations for sret-returning stubs (which would otherwise leave caller std::string uninitialized
// and corrupt the heap on destruction), Reflection::Tuple ctor/copy-ctor/dtor (18 call sites),
// RBX::Render::getShaderModel, and non-zero scalar globals (Body::getNextStateIndex::p, decalTextureScale).
// INFERRED: authentic 2008 signatures verified against stub_sret_audit.json, stubcall_audit.json,
// clients/2008-06/Roblox.exe (005011d0, 0095a898, 00826fd4), and reflection.h.
#include <stdio.h>
#include <string>
#include <vector>
#include <boost/any.hpp>
#include <boost/shared_ptr.hpp>
#include <G3D/Color3.h>
#include <G3D/Vector3.h>
#include <G3D/CoordinateFrame.h>
#include <G3D/Vector2int16.h>
#include "GLG3D/GLCaps.h"
#include "util/Utilities.h"
#include "util/ContentId.h"
#include "util/TextureId.h"
#include "util/Sound.h"
#include "v8datamodel/BrickColor.h"
#include "reflection/reflection.h"

namespace RBX { class Instance; }

extern "C" int _roc_body_next_state_idx = 1;       // INFERRED: orig 0095a898 dword = 1
extern "C" const float _roc_decalTextureScale = 2.0f; // INFERRED: orig 00826fd4 float = 2.0f

// INFERRED: authentic 2008 physics/profiler constants from orig Roblox.exe (006492f0..00649310, 00563170..00563180)
// whose converted objs had mis-relocated __FInf/__Inf/zeroed .data constants (0.0f froze all physics!).
extern "C" float _roc_const_uiDt() { return 1.0f / 30.0f; }
extern "C" float _roc_const_worldStepDt() { return 1.0f / 240.0f; }
extern "C" float _roc_const_kernelDt() { return 1.0f / (240.0f * 19.0f); }
extern "C" double _roc_debug_profilerWindow() { return 3.0; }
extern "C" double _roc_debug_profilerBucket() { return 0.01; }

namespace RBX
{
	template<>
	std::string StringConverter<BrickColor>::convertToString(const BrickColor& value)
	{
		return value.name();
	}

	template<>
	std::string StringConverter<G3D::Color3>::convertToString(const G3D::Color3& value)
	{
		char buf[96];
		_snprintf(buf, sizeof(buf), "%g, %g, %g", value.r, value.g, value.b);
		buf[sizeof(buf) - 1] = '\0';
		return std::string(buf);
	}

	template<>
	std::string StringConverter<G3D::Vector2int16>::convertToString(const G3D::Vector2int16& value)
	{
		char buf[64];
		_snprintf(buf, sizeof(buf), "%d, %d", (int)value.x, (int)value.y);
		buf[sizeof(buf) - 1] = '\0';
		return std::string(buf);
	}

	template<>
	std::string StringConverter<TextureId>::convertToString(const TextureId& value)
	{
		return value.toString();
	}

	template<>
	std::string StringConverter<Soundscape::SoundId>::convertToString(const Soundscape::SoundId& value)
	{
		return value.toString();
	}

	namespace Render
	{
		float getShaderModel()
		{
			if (G3D::GLCaps::supports_GL_ARB_vertex_program() && G3D::GLCaps::supports_GL_ARB_fragment_program())
				return 2.0f;
			if (G3D::GLCaps::supports("GL_ATI_fragment_shader") || G3D::GLCaps::supports("GL_NV_fragment_program"))
				return 2.0f;
			return 0.0f;
		}
	}

	namespace Reflection
	{
		Tuple::Tuple(size_t count) : values(count) {}
		Tuple::Tuple(const Tuple& other) : values(other.values) {}
		Tuple::~Tuple() {}

		std::string RefPropertyDescriptor::getStringValue(const DescribedBase*) const
		{
			return std::string();
		}

		bool RefPropertyDescriptor::setStringValue(DescribedBase*, const std::string&) const
		{
			return false;
		}

		// Authentic Type::singleton<T>() replacing 11 converted 0056c*.obj units whose relocs pointed at
		// "Object" and/or typeid(shared_ptr<DescribedBase>) (broke int/bool/float/double reflection casts).
		template<> const Type& Type::singleton<int>()
		{
			static Type type("int", typeid(int));
			return type;
		}
		template<> const Type& Type::singleton<bool>()
		{
			static Type type("bool", typeid(bool));
			return type;
		}
		template<> const Type& Type::singleton<float>()
		{
			static Type type("float", typeid(float));
			return type;
		}
		template<> const Type& Type::singleton<double>()
		{
			static Type type("double", typeid(double));
			return type;
		}
		template<> const Type& Type::singleton<boost::shared_ptr<Instance> >()
		{
			static Type type("Instance", typeid(boost::shared_ptr<Instance>));
			return type;
		}
		template<> const Type& Type::singleton<boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > >()
		{
			static Type type("Objects", typeid(boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > >));
			return type;
		}
		template<> const Type& Type::singleton<TextureId>()
		{
			static Type type("Content", typeid(ContentId));
			return type;
		}
		template<> const Type& Type::singleton<std::string>()
		{
			static Type type("string", typeid(std::string));
			return type;
		}
		template<> const Type& Type::singleton<G3D::Vector3>()
		{
			static Type type("Vector3", typeid(G3D::Vector3));
			return type;
		}
		template<> const Type& Type::singleton<G3D::Color3>()
		{
			static Type type("Color3", typeid(G3D::Color3));
			return type;
		}
		template<> const Type& Type::singleton<std::vector<Value> >()
		{
			static Type type("Table", typeid(std::vector<Value>));
			return type;
		}
	}
}

namespace boost
{
	// Explicit instantiations replacing stubbed func_004459f0 and 8 corrupted any_cast<T>(any*) objs
	// (00415b90..0056c7d0 whose converted relocs pointed at the wrong type_info).
	template const G3D::Vector2int16& any_cast<const G3D::Vector2int16&>(const any&);
	template int* any_cast<int>(any*);
	template bool* any_cast<bool>(any*);
	template float* any_cast<float>(any*);
	template RBX::ContentId* any_cast<RBX::ContentId>(any*);
	template G3D::Vector3* any_cast<G3D::Vector3>(any*);
	template G3D::CoordinateFrame* any_cast<G3D::CoordinateFrame>(any*);
	template G3D::Color3* any_cast<G3D::Color3>(any*);
	template RBX::BrickColor* any_cast<RBX::BrickColor>(any*);
}

// Force out-of-line emission of G3D::CoordinateFrame::toObjectSpace(const CoordinateFrame&) const
// (?toObjectSpace@CoordinateFrame@G3D@@QBE?AV12@ABV12@@Z) for 6 converted objs whose relocs pointed at Box overload.
typedef G3D::CoordinateFrame (G3D::CoordinateFrame::*CFToObjFn)(const G3D::CoordinateFrame&) const;
extern "C" CFToObjFn _roc_force_cf_toObjectSpace = &G3D::CoordinateFrame::toObjectSpace;
