// 2008-06 native Creatable / FactoryProduct / Name template instances of the application range 00418000..00424000
// (inactive). Verified by tests/record_native_app_unit418_2008.py. All headers are read-only here.
//
// Two COMDAT runs of compiler-emitted template instances, each class with, in link order:
//   * boost::detail::shared_count(C*, Creatable<Instance>::Deleter) (131 B; counted by creatable-shared-count);
//   * boost::shared_ptr<C>(C*, Creatable<Instance>::Deleter) (171 B, the enable_shared_from_this hook-up);
//   * Creatable<Instance>::create<C>() (120 / 122 B: malloc(sizeof(C)), C(), shared_ptr<C>(p, Deleter()));
//   * FactoryProduct<C, D, N>::Creator::create() const (175 B, slot 0 of the one-slot Creator vtable).
// The DHTMLWindowService run 0041ba00..0041cf5f (sizeof 0x130) and the insert-verb run 0041e100..0041ed5f: Decal
// (0x16c), Texture (0x174), PartInstance (0x404; its constructor takes the virtual-base flag, push 1) and SpecialShape;
// the ContentProvider rows of that run are built in AppUnit418_2008Content.cpp. sizeof(C) comes from the native
// headers and is checked against the malloc size by the recorder.
// Name::doDeclare<sC>() / callDoDeclare<sC>() (inline in native util/Name.h, instantiated through Name::declare<sC>())
// for Decal 0041de20, Texture 0041de90 and Part 0041df00 / 0041e0d0.
// DHTMLWindowService2008.h includes MFC and must precede the headers that include windows.h (afxv_w32.h C1189).
#include "AppLeaves2008/DHTMLWindowService2008.h"
#include "v8datamodel/Decal.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/SpecialShape.h"
#include "util/Object.h"

namespace RBX
{
	// util/Object.h declares Creator::create() only; this is the definition every Creator vtable slot 0 reaches.
	template<typename Class, typename DerivedClass, const char* ClassName>
	boost::shared_ptr<Object> FactoryProduct<Class, DerivedClass, ClassName>::Creator::create() const
	{
		return Creatable<Instance>::create<Class>();
	}

	template const Name& Name::declare<sDecal>();
	template const Name& Name::declare<sTexture>();
	template const Name& Name::declare<sPart>();
}

template boost::shared_ptr<DHTMLWindowService> RBX::Creatable<RBX::Instance>::create<DHTMLWindowService>();
template boost::shared_ptr<RBX::Decal> RBX::Creatable<RBX::Instance>::create<RBX::Decal>();
template boost::shared_ptr<RBX::Texture> RBX::Creatable<RBX::Instance>::create<RBX::Texture>();
template boost::shared_ptr<RBX::PartInstance> RBX::Creatable<RBX::Instance>::create<RBX::PartInstance>();
template boost::shared_ptr<RBX::SpecialShape> RBX::Creatable<RBX::Instance>::create<RBX::SpecialShape>();

template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<DHTMLWindowService, RBX::Instance, sDHTMLWindowService>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::Decal, RBX::FaceInstance, RBX::sDecal>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::Texture, RBX::Decal, RBX::sTexture>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::PartInstance, RBX::PVInstance, RBX::sPart>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::SpecialShape, RBX::Instance, RBX::sSpecialShape>::Creator::create() const;
