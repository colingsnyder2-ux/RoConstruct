// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native NativeClassRegistration::NativeClassRegistration() 005c3ca0 (inactive; InitInstance's function-local static
// `classes`). The body is only calls: every registered class's Described<>::classDescriptor() accessor in a fixed order (it
// creates the function-local ClassDescriptor, which links it under its base), then SoundChannel/StockSound/SoundService
// (005bbeb0, inlined here), registerBodyMovers 00630860 and registerValueClasses 00637ae0. Call order and class list were
// read from the 2008 disassembly (class names from each accessor's descriptor string / mangled name).
// INFERRED: the registrar class name and that the three trailing registration functions are plain free functions.
#include "v8datamodel/Accoutrement.h"
#include "v8datamodel/Backpack.h"
#include "v8datamodel/BodyColors.h"
#include "v8datamodel/ClickDetector.h"
#include "v8datamodel/UserController.h"
#include "v8datamodel/Explosion.h"
#include "v8datamodel/Flag.h"
#include "v8datamodel/FlagStand.h"
#include "v8datamodel/FlagStandService.h"
#include "v8datamodel/ForceField.h"
#include "v8datamodel/GameSettings.h"
#include "v8datamodel/GeometryService.h"
#include "v8datamodel/GlobalSettings.h"
#include "v8datamodel/Message.h"
#include "humanoid/Humanoid.h"
#include "v8tree/Instance.h"
#include "util/RunStateOwner.h"
#include "v8datamodel/Hopper.h"
#include "LocalBackpack2008/LocalBackpack2008.h"
#include "script/Script.h"
#include "v8datamodel/Selection.h"
#include "v8datamodel/Clothing.h"
#include "v8datamodel/Seat.h"
#include "v8datamodel/Sparkles.h"
#include "v8datamodel/Stats.h"
#include "v8datamodel/Visit.h"
#include "v8datamodel/DebrisService.h"
#include "v8datamodel/TimerService.h"
#include "v8datamodel/SpawnerService.h"
#include "util/ContentProvider.h"
#include "v8datamodel/ChangeHistoryService.h"
#include "v8datamodel/JointInstance.h"
#include "v8datamodel/Feature.h"
#include "util/Sound.h"

namespace RBX
{
	extern const char sContentProvider[];
	void registerBodyMovers();     // 00630860
	void registerValueClasses();   // 00637ae0
}

class NativeClassRegistration
{
public:
	NativeClassRegistration();
};

NativeClassRegistration::NativeClassRegistration()
{
	using namespace RBX;
	Accoutrement::classDescriptor();
	Backpack::classDescriptor();
	BodyColors::classDescriptor();
	ClickDetector::classDescriptor();
	ControllerService::classDescriptor();
	Explosion::classDescriptor();
	Flag::classDescriptor();
	FlagStand::classDescriptor();
	FlagStandService::classDescriptor();
	ForceField::classDescriptor();
	GameSettings::classDescriptor();
	GeometryService::classDescriptor();
	GlobalSettings::classDescriptor();
	Hat::classDescriptor();
	Hint::classDescriptor();
	Humanoid::classDescriptor();
	Instance::classDescriptor();
	RunService::classDescriptor();
	Hopper::classDescriptor();
	LocalBackpack::classDescriptor();
	LocalBackpackItem::classDescriptor();
	LocalScript::classDescriptor();
	Message::classDescriptor();
	Selection::classDescriptor();
	ShirtGraphic::classDescriptor();
	Shirt::classDescriptor();
	Pants::classDescriptor();
	Seat::classDescriptor();
	Sparkles::classDescriptor();
	StarterPackService::classDescriptor();
	Stats::StatsService::classDescriptor();
	Visit::classDescriptor();
	DebrisService::classDescriptor();
	TimerService::classDescriptor();
	SpawnerService::classDescriptor();
	Reflection::Described<ContentProvider, sContentProvider, NonFactoryProduct<Instance, sContentProvider> >::classDescriptor();
	ChangeHistoryService::classDescriptor();
	Glue::classDescriptor();
	Motor::classDescriptor();
	Rotate::classDescriptor();
	RotateP::classDescriptor();
	RotateV::classDescriptor();
	Snap::classDescriptor();
	Weld::classDescriptor();
	MotorFeature::classDescriptor();
	Hole::classDescriptor();
	Soundscape::SoundChannel::classDescriptor();
	StockSound::classDescriptor();
	Soundscape::SoundService::classDescriptor();
	registerBodyMovers();
	registerValueClasses();
}
