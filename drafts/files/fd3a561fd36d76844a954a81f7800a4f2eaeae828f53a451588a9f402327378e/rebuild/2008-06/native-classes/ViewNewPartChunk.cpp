// 2008-06 native RBX::ViewNew::PartChunk / Decal / Texture destructors and PartChunk::getMesh (inactive). This
// unit needs the complete RenderBase::MaterialBase (the material pointer at +0xc4 is released through its virtual
// destructor), so it includes RenderLib/Material2008.h and not PartInstance.h; see native-headers/ViewNew/PartChunk.h.
#include "ViewNew/PartChunk.h"
#include "RenderLib/Material2008.h"

namespace RBX
{
	namespace ViewNew
	{
		PartChunk::~PartChunk()
		{
		}

		G3D::ReferenceCountedPointer<RenderBase::Mesh> PartChunk::getMesh()
		{
			if (mesh.isNull())
				updateMesh();

			return mesh;
		}

		Decal::~Decal()
		{
		}

		Texture::~Texture()
		{
		}
	}
}

// boost::function plumbing of the slots the PartChunk / Part / Decal / Texture constructors connect (bind_t RTTI
// .?AV?$bind_t@XV?$mf1@XVPartChunk@ViewNew@RBX@@... at 00941700, 009417c8, 00941888, 00941678 (Part, mf0),
// 00941918, 009419d8, 00941a90, 00941b50). The constructors are not built here (they need the 2008 view type with
// the scene manager at +4), so the managers and the Decal invokers are instantiated explicitly; each compiles to the
// functor_manager::manage body the original keeps at 004e7100..004e7340 / 004e70c0 (+ manager 004e63a0) and the
// invokers at 004e80a0 / 004e8140 (the identical PartChunk / Texture invokers are folded onto them).
#include <boost/bind.hpp>
#include <boost/function.hpp>

namespace RBX
{
	namespace ViewNew
	{
		template<class C, class A>
		struct SlotBind1
		{
			typedef boost::_bi::bind_t<void, boost::_mfi::mf1<void, C, A>, boost::_bi::list2<boost::_bi::value<C*>, boost::arg<1> > > type;
		};

		template<class C>
		struct SlotBind0
		{
			typedef boost::_bi::bind_t<void, boost::_mfi::mf0<void, C>, boost::_bi::list1<boost::_bi::value<C*> > > type;
		};
	}
}

#define NATIVE_VIEWNEW_MANAGE(F) \
	template void boost::detail::function::functor_manager<F, std::allocator<void> >::manage( \
		const boost::detail::function::function_buffer&, boost::detail::function::function_buffer&, \
		boost::detail::function::functor_manager_operation_type);
#define NATIVE_VIEWNEW_INVOKE(F, A) \
	template void boost::detail::function::void_function_obj_invoker1<F, void, A>::invoke( \
		boost::detail::function::function_buffer&, A);

typedef boost::shared_ptr<RBX::Instance> NativeViewNewInstancePtr;
typedef const RBX::Reflection::PropertyDescriptor* NativeViewNewDescriptorPtr;
typedef RBX::ViewNew::SlotBind1<RBX::ViewNew::PartChunk, NativeViewNewInstancePtr>::type NativeViewNewPartChunkInstanceBind;
typedef RBX::ViewNew::SlotBind1<RBX::ViewNew::PartChunk, NativeViewNewDescriptorPtr>::type NativeViewNewPartChunkDescriptorBind;
typedef RBX::ViewNew::SlotBind0<RBX::ViewNew::PartChunk>::type NativeViewNewPartChunkBind;
typedef RBX::ViewNew::SlotBind0<RBX::ViewNew::Part>::type NativeViewNewPartBind;
typedef RBX::ViewNew::SlotBind1<RBX::ViewNew::Decal, NativeViewNewInstancePtr>::type NativeViewNewDecalInstanceBind;
typedef RBX::ViewNew::SlotBind1<RBX::ViewNew::Decal, NativeViewNewDescriptorPtr>::type NativeViewNewDecalDescriptorBind;
typedef RBX::ViewNew::SlotBind1<RBX::ViewNew::Texture, NativeViewNewInstancePtr>::type NativeViewNewTextureInstanceBind;
typedef RBX::ViewNew::SlotBind1<RBX::ViewNew::Texture, NativeViewNewDescriptorPtr>::type NativeViewNewTextureDescriptorBind;

NATIVE_VIEWNEW_MANAGE(NativeViewNewPartChunkInstanceBind)      // 004e7100
NATIVE_VIEWNEW_MANAGE(NativeViewNewPartChunkDescriptorBind)    // 004e7160
NATIVE_VIEWNEW_MANAGE(NativeViewNewPartChunkBind)              // 004e71c0
NATIVE_VIEWNEW_MANAGE(NativeViewNewPartBind)                   // 004e70c0 (manager 004e63a0)
NATIVE_VIEWNEW_MANAGE(NativeViewNewDecalInstanceBind)          // 004e7220
NATIVE_VIEWNEW_MANAGE(NativeViewNewDecalDescriptorBind)        // 004e7280
NATIVE_VIEWNEW_MANAGE(NativeViewNewTextureInstanceBind)        // 004e72e0
NATIVE_VIEWNEW_MANAGE(NativeViewNewTextureDescriptorBind)      // 004e7340
NATIVE_VIEWNEW_INVOKE(NativeViewNewDecalInstanceBind, NativeViewNewInstancePtr)       // 004e80a0
NATIVE_VIEWNEW_INVOKE(NativeViewNewDecalDescriptorBind, NativeViewNewDescriptorPtr)   // 004e8140
