// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers}/../../../tools/rbxgs/Client/App/include /I{headers}/../../../tools/rbxgs/Client/RbxGraphics/include /I{headers}/../../../tools/rbxgs/Client/Network/include /I{headers}/../../../tools/rbxgs/Client/RbxView/include /I{headers}/../../../tools/rbxgs/Client/Rendering/g3d/include /I{headers}/../../../tools/rbxgs/Client/Rendering/g3d/zlib /I{headers}/../../../tools/rbxgs/Client/Rendering/RenderLib/include /I{headers}/../../../tools/rbxgs/Client/Rendering/AppDraw/include /I{headers}/../../../tools/rbxgs/Client/boost_1_34_1/src /I{headers}/../../../tools/rbxgs/Client/App/lua-5.1.1/src /I{headers}/../../../tools/rbxgs/Client/Rendering/SDL-1.2.6/include /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
#include "v8datamodel/Surfaces.h"
#include "v8datamodel/PartInstance.h"
namespace RBX {
	template<NormalId id, typename Type, typename GetFunction, typename SetFunction>
	class SurfaceGetSet : public Reflection::TypedPropertyDescriptor<Type>::GetSet
	{
	private:
		GetFunction get;
		SetFunction set;

	public:
		SurfaceGetSet(GetFunction g, SetFunction s)
			: get(g),
			  set(s)
		{
		}

		virtual bool isReadOnly() const
		{
			return false;
		}
		virtual Type getValue(const Reflection::DescribedBase* instance) const
		{
			return (static_cast<const PartInstance*>(instance)->getSurfaces()[id].*get)();
		}
		virtual void setValue(Reflection::DescribedBase* instance, const Type& value) const
		{
			(static_cast<PartInstance*>(instance)->getSurfaces()[id].*set)(value);
		}
	};

	template<NormalId id, typename Type>
	class SurfacePropDescriptor : public Reflection::TypedPropertyDescriptor<Type>
	{
	public:
		template<typename GetFunction, typename SetFunction>
		SurfacePropDescriptor(const char* name, const char* category, GetFunction get, SetFunction set, Functionality flags) 
			: Reflection::TypedPropertyDescriptor<Type>::TypedPropertyDescriptor(PartInstance::classDescriptor(), name, category, 
			  std::auto_ptr<Reflection::TypedPropertyDescriptor<Type>::GetSet>(new SurfaceGetSet<id, Type, GetFunction, SetFunction>(get, set)), flags)
		{
		}
	};

template SurfacePropDescriptor<(NormalId)1, float>::SurfacePropDescriptor(const char*, const char*, float (Surface::*)() const, void (Surface::*)(float), Reflection::PropertyDescriptor::Functionality);
template SurfacePropDescriptor<(NormalId)4, float>::SurfacePropDescriptor(const char*, const char*, float (Surface::*)() const, void (Surface::*)(float), Reflection::PropertyDescriptor::Functionality);
template SurfacePropDescriptor<(NormalId)3, float>::SurfacePropDescriptor(const char*, const char*, float (Surface::*)() const, void (Surface::*)(float), Reflection::PropertyDescriptor::Functionality);
template SurfacePropDescriptor<(NormalId)0, float>::SurfacePropDescriptor(const char*, const char*, float (Surface::*)() const, void (Surface::*)(float), Reflection::PropertyDescriptor::Functionality);
template SurfacePropDescriptor<(NormalId)5, float>::SurfacePropDescriptor(const char*, const char*, float (Surface::*)() const, void (Surface::*)(float), Reflection::PropertyDescriptor::Functionality);
template SurfacePropDescriptor<(NormalId)2, float>::SurfacePropDescriptor(const char*, const char*, float (Surface::*)() const, void (Surface::*)(float), Reflection::PropertyDescriptor::Functionality);
}

// Donor template instantiations.
