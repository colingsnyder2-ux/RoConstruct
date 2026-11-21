// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 2008-06 native FactoryProduct<C, D, N>::creator static members: their dynamic initializers (??__E?creator@...)
// and atexit destructors (??__F?creator@...) in 007ee760..007fe8b0 (inactive). The donor 2007 util/Object.h defines
// Creator()/~Creator() and `creator` in the header; the native util/Object.h only declares them, so this unit is
// their definition (the pattern of AppUnit400_2008Creators.cpp for Creator::create()). Creator() ends with
// isConstructed = 666: iOS 2013 Object.h asserts Creator::wasConstructed() (isConstructed == 0x29a) and each 2008
// initializer stores 0x29a to its own instantiation. Byte-proved per class by native_creator_gate.py.
#include "v8datamodel/Accoutrement.h"
#include "v8tree/Instance.h"
#include "v8datamodel/Backpack.h"
#include "v8datamodel/Hopper.h"
#include "v8datamodel/BodyMovers.h"
#include "v8datamodel/BodyColors.h"
#include "v8datamodel/Clothing.h"
#include "v8datamodel/Camera.h"
#include "v8datamodel/ChangeHistoryService.h"
#include "reflection/Metadata.h"
#include "v8datamodel/ClickDetector.h"
#include "v8datamodel/UserController.h"
#include "v8datamodel/DebrisService.h"
#include "v8datamodel/DebugSettings.h"
#include "v8datamodel/Explosion.h"
#include "v8datamodel/FlagStandService.h"
#include "v8datamodel/FlagStand.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Flag.h"
#include "v8datamodel/Tool.h"
#include "v8datamodel/ForceField.h"
#include "v8datamodel/GameSettings.h"
#include "v8datamodel/GeometryService.h"
#include "v8datamodel/Feature.h"
#include "humanoid/Humanoid.h"
#include "v8datamodel/Lighting2008.h"
#include "script/Script.h"
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/PVInstance.h"
#include "v8datamodel/JointInstance.h"
#include "v8datamodel/Value.h"
#include "v8datamodel/Rocket.h"
#include "script/ScriptContext.h"
#include "v8datamodel/Seat.h"
#include "v8datamodel/Sky.h"
#include "v8datamodel/SpawnLocation.h"
#include "v8datamodel/SpawnerService.h"
#include "v8datamodel/SpecialShape.h"
#include "v8datamodel/Team.h"
#include "v8datamodel/Teams.h"
#include "v8datamodel/TimerService.h"
#include "v8datamodel/Visit.h"

namespace RBX
{
	template<typename Class, typename DerivedClass, const char* ClassName>
	const Name& FactoryProduct<Class, DerivedClass, ClassName>::className()
	{
		return Name::declare<ClassName>();
	}

	template<typename Class, typename DerivedClass, const char* ClassName>
	FactoryProduct<Class, DerivedClass, ClassName>::Creator::Creator()
	{
		getCreators()[&className()] = this;
		isConstructed = 666;
	}

	template<typename Class, typename DerivedClass, const char* ClassName>
	FactoryProduct<Class, DerivedClass, ClassName>::Creator::~Creator()
	{
		getCreators().erase(&className());
	}

	template<typename Class, typename DerivedClass, const char* ClassName>
	const typename FactoryProduct<Class, DerivedClass, ClassName>::Creator FactoryProduct<Class, DerivedClass, ClassName>::creator;
}

// One explicit instantiation per class (getCreator() is public; creator is private): it instantiates that class's creator object, initializer and atexit destructor.
template const RBX::ICreator& RBX::FactoryProduct<RBX::Accoutrement, RBX::Instance, RBX::sAccoutrement>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::Backpack, RBX::Hopper, RBX::sBackpack>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::BodyAngularVelocity, RBX::BodyMover, RBX::sBodyAngularVelocity>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::BodyColors, RBX::CharacterAppearance, RBX::sBodyColors>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::BodyForce, RBX::BodyMover, RBX::sBodyForce>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::BodyGyro, RBX::BodyMover, RBX::sBodyGyro>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::BodyPosition, RBX::BodyMover, RBX::sBodyPosition>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::BodyThrust, RBX::BodyMover, RBX::sBodyThrust>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::BodyVelocity, RBX::BodyMover, RBX::sBodyVelocity>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::Camera, RBX::Instance, RBX::sCamera>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::ChangeHistoryService, RBX::Instance, RBX::sChangeHistoryService>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::Reflection::Metadata::Class, RBX::Reflection::Metadata::Item, RBX::Reflection::Metadata::sClass>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::Reflection::Metadata::Classes, RBX::Instance, RBX::Reflection::Metadata::sClasses>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::ClickDetector, RBX::Instance, RBX::sClickDetector>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::Clothing, RBX::CharacterAppearance, RBX::sClothing>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::ControllerService, RBX::Instance, RBX::sControllerService>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::DebrisService, RBX::Instance, RBX::sDebrisService>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::DebugSettings, RBX::GlobalSettings::Item, RBX::sDebugSettings>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::Reflection::Metadata::Events, RBX::Reflection::Metadata::Members, RBX::Reflection::Metadata::sEvents>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::Explosion, RBX::Instance, RBX::sExplosion>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::FlagStandService, RBX::Instance, RBX::sFlagStandService>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::FlagStand, RBX::PartInstance, RBX::sFlagStand>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::Flag, RBX::Tool, RBX::sFlag>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::ForceField, RBX::Instance, RBX::sForceField>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::Reflection::Metadata::Functions, RBX::Reflection::Metadata::Members, RBX::Reflection::Metadata::sFunctions>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::GameSettings, RBX::GlobalSettings::Item, RBX::sGameSettings>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::GeometryService, RBX::Instance, RBX::sGeometryService>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::Hat, RBX::Accoutrement, RBX::sHat>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::Hole, RBX::Feature, RBX::sHole>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::HopperBin, RBX::BackpackItem, RBX::sHopperBin>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::Humanoid, RBX::Instance, RBX::sHumanoid>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::LegacyHopperService, RBX::Hopper, RBX::sLegacyHopperService>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::Lighting, RBX::Instance, RBX::sLighting>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::LocalScript, RBX::Script, RBX::sLocalScript>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::Reflection::Metadata::Member, RBX::Reflection::Metadata::Item, RBX::Reflection::Metadata::sMember>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::ModelInstance, RBX::PVInstance, RBX::sModel>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::MotorFeature, RBX::Feature, RBX::sMotorFeature>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::Motor, RBX::JointInstance, RBX::sMotor>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::ObjectValue, RBX::Instance, RBX::sObjectValue>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::Pants, RBX::Clothing, RBX::sPants>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::PartInstance, RBX::PVInstance, RBX::sPart>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::Reflection::Metadata::Properties, RBX::Reflection::Metadata::Members, RBX::Reflection::Metadata::sProperties>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::Rocket, RBX::BodyMover, RBX::sRocket>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::ScriptContext, RBX::Instance, RBX::sScriptContext>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::Script, RBX::Instance, RBX::sScript>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::Seat, RBX::PartInstance, RBX::sSeat>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::ShirtGraphic, RBX::CharacterAppearance, RBX::sShirtGraphic>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::Shirt, RBX::Clothing, RBX::sShirt>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::Skin, RBX::CharacterAppearance, RBX::sSkin>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::Sky, RBX::Instance, RBX::sSky>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::SpawnLocation, RBX::PartInstance, RBX::sSpawnLocation>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::SpawnerService, RBX::Instance, RBX::sSpawnerService>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::SpecialShape, RBX::Instance, RBX::sSpecialShape>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::StarterPackService, RBX::Hopper, RBX::sStarterPackService>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::Team, RBX::Instance, RBX::sTeam>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::Teams, RBX::Instance, RBX::sTeams>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::TimerService, RBX::Instance, RBX::sTimerService>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::Tool, RBX::BackpackItem, RBX::sTool>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::VelocityMotor, RBX::JointInstance, RBX::sVelocityMotor>::getCreator();
template const RBX::ICreator& RBX::FactoryProduct<RBX::Visit, RBX::Instance, RBX::sVisit>::getCreator();
