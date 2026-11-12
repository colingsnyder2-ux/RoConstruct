// 2008-06 native rows of the util/Sound.cpp unit inside the application range 005b4000..005bc000 (inactive).
// Verified by tests/record_native_app_unit5b4.py. All headers are read-only here: util/Sound.h (SoundChannel,
// SoundService, StockSound, SoundServiceStatsItem, the SoundType / ReverbType enums), reflection/*.h, v8datamodel/Stats.h.
//
// Evidence: RTTI .?AV?$DescribedCreatable@VSoundService@Soundscape@RBX@@VInstance@3@$1?sSoundService@23@3PADA@RBX@@
// (vtable 00837d84) and ...SoundChannel... (00837e44) - the class names are char arrays (3PADA) as util/Sound.h
// declares them; PropDescriptor<SoundChannel, SoundId / float / int / bool> vtables 00837c34 / 00837c68 / 00837c9c /
// 00837cd0; GetSetImpl vtables 00837648 / 00837570 / 0083765c / 00837584 (SoundChannel getter/setter pairs) and
// 00837634 (SoundService ReverbType); GetImpl 00837598 (read-only bool); BoundPropGetSet<SoundService> (float)
// 0083760c and <SoundChannel> (bool) 00837620; EnumDesc<ReverbType> constructor 005bb330 ("ReverbType", type
// descriptor 0094df74, 24 addPair calls through the ICF-shared addPair 0064d530, names 00837c18..00837b1c).
// SoundChannel field offsets read by the getters below: fmod_channel +0x13c, volume +0x160, the bit fields at +0x165
// (looped = bit 1), playCount +0x168 - the util/Sound.h layout.
//
// The rows are the template instances and small members of the unit; the static descriptor objects themselves are
// constructed by the static initializers outside this range and are not defined here.
#include "util/Sound.h"
#include "reflection/enumconverter.h"
#include "v8datamodel/Stats.h"
#include <fmod.hpp>

namespace RBX
{
	template<typename Class, typename DerivedClass, const char* ClassName>
	FactoryProduct<Class, DerivedClass, ClassName>::FactoryProduct() {}

	template<typename Class, typename DerivedClass, const char* ClassName>
	DescribedCreatable<Class, DerivedClass, ClassName>::DescribedCreatable() {}

	namespace Soundscape
	{
		int SoundChannel::getPlayCount() const                     // 005b65a0
		{
			return playCount;
		}

		bool SoundChannel::isPaused() const                        // 005b6960
		{
			if (!fmod_channel)
				return true;
			bool paused;
			if (fmod_channel->getPaused(&paused) == FMOD_ERR_INVALID_HANDLE)
				return true;
			return paused;
		}

		bool SoundChannel::isPlaying() const                       // 005b6990
		{
			if (!fmod_channel)
				return false;
			bool playing;
			if (fmod_channel->isPlaying(&playing) == FMOD_ERR_INVALID_HANDLE)
				return false;
			return playing;
		}

		float SoundChannel::getVolume() const                      // 005b69c0
		{
			return volume;
		}

		bool SoundChannel::getLooped() const                       // 005b69d0
		{
			return looped;
		}
	}

	Reflection::EnumDesc<Soundscape::ReverbType>::EnumDesc()        // 005bb330
		: EnumDescriptor("ReverbType", typeid(Soundscape::ReverbType))
	{
		addPair(Soundscape::NoReverb, "NoReverb");
		addPair(Soundscape::GenericReverb, "GenericReverb");
		addPair(Soundscape::PaddedCell, "PaddedCell");
		addPair(Soundscape::Room, "Room");
		addPair(Soundscape::Bathroom, "Bathroom");
		addPair(Soundscape::LivingRoom, "LivingRoom");
		addPair(Soundscape::StoneRoom, "StoneRoom");
		addPair(Soundscape::Auditorium, "Auditorium");
		addPair(Soundscape::ConcertHall, "ConcertHall");
		addPair(Soundscape::Cave, "Cave");
		addPair(Soundscape::Arena, "Arena");
		addPair(Soundscape::Hangar, "Hangar");
		addPair(Soundscape::CarpettedHallway, "CarpettedHallway");
		addPair(Soundscape::Hallway, "Hallway");
		addPair(Soundscape::StoneCorridor, "StoneCorridor");
		addPair(Soundscape::Alley, "Alley");
		addPair(Soundscape::Forest, "Forest");
		addPair(Soundscape::City, "City");
		addPair(Soundscape::Mountains, "Mountains");
		addPair(Soundscape::Quarry, "Quarry");
		addPair(Soundscape::Plain, "Plain");
		addPair(Soundscape::ParkingLot, "ParkingLot");
		addPair(Soundscape::SewerPipe, "SewerPipe");
		addPair(Soundscape::UnderWater, "UnderWater");
	}
}

namespace S = RBX::Soundscape;
namespace R = RBX::Reflection;
typedef R::PropertyDescriptor::Functionality F;

// FactoryProduct() 005b6b60 / 005b6bc0 and DescribedCreatable() 005bbec0 / 005bbfb0 (base constructors of
// SoundService() / SoundChannel()); their vtables bring the destructors and deleting destructors of the chain.
template RBX::FactoryProduct<S::SoundService, RBX::Instance, S::sSoundService>::FactoryProduct();
template RBX::FactoryProduct<S::SoundChannel, RBX::Instance, S::sSoundChannel>::FactoryProduct();
template RBX::FactoryProduct<StockSound, S::SoundChannel, sStockSound>::FactoryProduct();
template RBX::DescribedCreatable<S::SoundService, RBX::Instance, S::sSoundService>::DescribedCreatable();
template RBX::DescribedCreatable<S::SoundChannel, RBX::Instance, S::sSoundChannel>::DescribedCreatable();

// Name::declare<sC>() 005b8450 / 005b8470 / 005b8490 (doDeclare<sStockSound> 005b6ce0, callDoDeclare 005b73b0)
template const RBX::Name& RBX::Name::declare<S::sSoundService>();
template const RBX::Name& RBX::Name::declare<S::sSoundChannel>();
template const RBX::Name& RBX::Name::declare<sStockSound>();

// Described<C>::classDescriptor() 005bb7f0 / 005bb860 / 005bb8d0
template R::ClassDescriptor& R::Described<S::SoundService, S::sSoundService,
	RBX::FactoryProduct<S::SoundService, RBX::Instance, S::sSoundService> >::classDescriptor();
template R::ClassDescriptor& R::Described<S::SoundChannel, S::sSoundChannel,
	RBX::FactoryProduct<S::SoundChannel, RBX::Instance, S::sSoundChannel> >::classDescriptor();
template R::ClassDescriptor& R::Described<StockSound, sStockSound,
	RBX::FactoryProduct<StockSound, S::SoundChannel, sStockSound> >::classDescriptor();

// shared_ptr<T>(T*, Creatable<Instance>::Deleter) 005b7c50 / 005b7d00 / 005b7f50, emitted by the Creatable<Instance>
// factories of StockSound and the two sound stats items (the factory bodies themselves are not rows of this range)
template boost::shared_ptr<StockSound> RBX::Creatable<RBX::Instance>::create<StockSound>();
template boost::shared_ptr<SoundServiceStatsItem> RBX::Creatable<RBX::Instance>::create<SoundServiceStatsItem,
	const S::SoundService*>(const S::SoundService*);
template boost::shared_ptr<RBX::Stats::TypedStatsItem<unsigned> > RBX::Creatable<RBX::Instance>::create<
	RBX::Stats::TypedStatsItem<unsigned>, const unsigned*>(const unsigned*);

// property descriptor constructors 005bba10..005bbcd0, BoundProp constructors 005bb940 / 005bbd70 and their getset
// factories 005b7320 / 005b7370 / 005b7db0..005b7ea0
template R::PropDescriptor<S::SoundChannel, S::SoundId>::PropDescriptor(const char*, const char*,
	S::SoundId (S::SoundChannel::*)() const, void (S::SoundChannel::*)(S::SoundId), F);
template R::PropDescriptor<S::SoundChannel, float>::PropDescriptor(const char*, const char*,
	float (S::SoundChannel::*)() const, void (S::SoundChannel::*)(float), F);
template R::PropDescriptor<S::SoundChannel, int>::PropDescriptor(const char*, const char*,
	int (S::SoundChannel::*)() const, void (S::SoundChannel::*)(int), F);
template R::PropDescriptor<S::SoundChannel, bool>::PropDescriptor(const char*, const char*,
	bool (S::SoundChannel::*)() const, void (S::SoundChannel::*)(bool), F);
template R::PropDescriptor<S::SoundChannel, bool>::PropDescriptor(const char*, const char*,
	bool (S::SoundChannel::*)() const, int, F);
template R::BoundProp<float, 1>::BoundProp(const char*, const char*, float S::SoundService::*,
	void (S::SoundService::*)(const R::PropertyDescriptor&), F);
template R::BoundProp<bool, 1>::BoundProp(const char*, const char*, bool S::SoundChannel::*, F);
template std::auto_ptr<R::TypedPropertyDescriptor<S::ReverbType>::GetSet> R::PropDescriptor<S::SoundService, S::ReverbType>::getset(
	S::ReverbType (S::SoundService::*)() const, void (S::SoundService::*)(const S::ReverbType&));

// EnumDesc<ReverbType>::singleton() 005bbe40 and EnumDesc<SoundType>::singleton() 005bb2c0 (its constructor
// 00629120 is ScriptApp2008SoundType.cpp's)
template const R::EnumDesc<S::ReverbType>& R::EnumDesc<S::ReverbType>::singleton();
template const R::EnumDesc<RBX::SoundType>& R::EnumDesc<RBX::SoundType>::singleton();

// boost::any support of the SoundId property values (Reflection::Value holds a boost::any):
// any_cast<SoundId>(any*) 005b6ca0, holder<SoundId>(const SoundId&) 005b6d50, holder<SoundId>::type() 005b6db0
template class boost::any::holder<S::SoundId>;
template S::SoundId* boost::any_cast<S::SoundId>(boost::any*);
