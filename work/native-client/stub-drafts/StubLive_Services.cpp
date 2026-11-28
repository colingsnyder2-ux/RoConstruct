// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// Explicit instantiations for remaining stubbed ServiceProvider::create<T> / find<T> templates
// (fixes NULL GeometryService crash in HumanoidState::climbableInFront + FlagStandService/Teams/Selection/Stats).
// INFERRED: authentic 2008 ServiceProvider::create/find bodies matching WorldServiceFactories.cpp and Service.h.
#include <boost/thread/once.hpp>
#include "v8tree/Service.h"
#include "v8datamodel/GeometryService.h"
#include "v8datamodel/FlagStandService.h"
#include "v8datamodel/Teams.h"
#include "v8datamodel/Selection.h"
#include "v8datamodel/Stats.h"
#include "v8datamodel/DebrisService.h"
#include "util/Sound.h"
#include "util/Extents.h"

namespace RBX {

extern template boost::shared_ptr<GeometryService> Creatable<Instance>::create<GeometryService>();
extern template boost::shared_ptr<FilteredSelection<Instance> > Creatable<Instance>::create<FilteredSelection<Instance> >();
extern template boost::shared_ptr<DebrisService> Creatable<Instance>::create<DebrisService>();

template<class Class> size_t ServiceProvider::doGetClassIndex() {
	static size_t index = newIndex();
	return index;
}
template<class Class> void ServiceProvider::callDoGetClassIndex() {
	doGetClassIndex<Class>();
}
template<class Class> size_t ServiceProvider::getClassIndex() {
	static boost::once_flag flag = BOOST_ONCE_INIT;
	boost::call_once(&callDoGetClassIndex<Class>, flag);
	return doGetClassIndex<Class>();
}

template<class Class> Class* ServiceProvider::find() const {
	size_t index = getClassIndex<Class>();
	if (index < serviceArray.size()) {
		if (Instance* raw = serviceArray[index].get())
			return static_cast<Class*>(raw);
	}
	boost::shared_ptr<Instance> found = findServiceByClassName(Class::className());
	if (found) {
		if (serviceArray.size() <= index)
			serviceArray.resize(index + 1);
		serviceArray[index] = found;
		return static_cast<Class*>(found.get());
	}
	return NULL;
}

template<class Class> Class* ServiceProvider::create() const {
	Class* service = find<Class>();
	if (!service) {
		boost::shared_ptr<Class> value = Creatable<Instance>::create<Class>();
		service = value.get();
		size_t index = getClassIndex<Class>();
		if (serviceArray.size() <= index)
			serviceArray.resize(index + 1);
		serviceArray[index] = value;
		service->setParent(const_cast<ServiceProvider*>(this));
	}
	return service;
}

template<class Class> Class* ServiceProvider::create(const Instance* context) {
	while (context) {
		if (const ServiceProvider* sp = dynamic_cast<const ServiceProvider*>(context))
			return sp->create<Class>();
		context = context->getParent();
	}
	return NULL;
}

template GeometryService* ServiceProvider::create<GeometryService>() const;
template GeometryService* ServiceProvider::create<GeometryService>(const Instance*);
template FilteredSelection<Instance>* ServiceProvider::create<FilteredSelection<Instance> >(const Instance*);
template Stats::Item* ServiceProvider::find<Stats::Item>() const;
template DebrisService* ServiceProvider::create<DebrisService>() const;

// Force out-of-line emission of inline static overloads taking const ServiceProvider*
typedef FlagStandService* (*CreateFlagStandSPFn)(const ServiceProvider*);
typedef Teams* (*CreateTeamsSPFn)(const ServiceProvider*);
typedef Teams* (*FindTeamsSPFn)(const ServiceProvider*);
extern "C" {
	CreateFlagStandSPFn _roc_force_sp_create_flagstand = &ServiceProvider::create<FlagStandService>;
	CreateTeamsSPFn _roc_force_sp_create_teams = &ServiceProvider::create<Teams>;
	FindTeamsSPFn _roc_force_sp_find_teams = &ServiceProvider::find<Teams>;
}

// INFERRED: authentic 2008 SoundChannel property descriptors declared extern in SoundChannel.cpp (00977010, 00977118, 00977064)
namespace Reflection {
	// INFERRED: SoundId Type singleton forwards to ContentId (matching TextureId/MeshId); Ref pointers forward to RefType::singleton
	template<> const Type& Type::singleton<Soundscape::SoundId>() { return Type::singleton<ContentId>(); }
	template<> const Type& Type::singleton<Instance*>() { return RefType::singleton<Instance*>(); }
	template<> const Type& Type::singleton<PartInstance*>() { return RefType::singleton<PartInstance*>(); }
	template const RefType& RefType::singleton<PartInstance*>();
}

namespace Soundscape {
	SoundId SoundChannel::getSoundId() const { return soundId; }
	Reflection::PropDescriptor<SoundChannel, int> playCountProperty(
		"PlayCount", "Data", &SoundChannel::getPlayCount, &SoundChannel::setPlayCount, Reflection::PropertyDescriptor::STREAMING);
	Reflection::PropDescriptor<SoundChannel, bool> loopedProperty(
		"Looped", "Behavior", &SoundChannel::getLooped, &SoundChannel::setLooped, Reflection::PropertyDescriptor::STANDARD);
	Reflection::PropDescriptor<SoundChannel, SoundId> soundIdProperty(
		"SoundId", "Data", &SoundChannel::getSoundId, &SoundChannel::setSoundId, Reflection::PropertyDescriptor::STANDARD);
}

// INFERRED: authentic 2008 Extents::zero() (00583860) — fixes ModelInstance::computeLocalGridExtents crash on empty Models
const Extents& Extents::zero() {
	static Extents e(G3D::Vector3::zero(), G3D::Vector3::zero());
	return e;
}

}

// INFERRED: authentic 2008 boost::function0(bind_t) ctor (0048e5d0) called by Player::doPeriodicIdleCheck -> TimerService::delay
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)
struct _RocSpControl0048e5d0 {
	virtual void unused();
	virtual void dispose();
	virtual void destroy();
	volatile long strong;
	volatile long weak;
};
struct _RocFn0048e5d0 { void* vtable; };
extern "C" void __fastcall fn_0048e3b0(_RocFn0048e5d0* self, int unusedEdx, unsigned long* a1);
extern "C" _RocFn0048e5d0* __fastcall fn_0048e5d0(_RocFn0048e5d0* self, int unusedEdx,
	unsigned long a1, unsigned long a2, unsigned long a3, _RocSpControl0048e5d0* control, unsigned long last)
{
	self->vtable = 0;
	fn_0048e3b0(self, 0, &a1);
	if (control && _InterlockedDecrement(&control->strong) == 0) {
		control->dispose();
		if (_InterlockedDecrement(&control->weak) == 0)
			control->destroy();
	}
	return self;
}

// INFERRED: authentic 2008 Color::lightGreen() (005d7560) — overrides mis-alias to Humanoid::renderMultiplayer
extern "C" const G3D::Color3& fn_005d7560() {
	static const G3D::Color3 c(0.50588238f, 0.77254903f, 0.08627451f);
	return c;
}
