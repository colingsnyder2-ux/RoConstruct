// 2008-06 native RBX::DebugSettings (inactive); evidence in native-headers/v8datamodel/DebugSettings.h.
// Verified by tests/record_native_settings_items.py (unit profile: document-swap flags). Bodies that need a declaration
// the shared headers lack (World::EThrottle) are guarded by NATIVE_DEBUGSETTINGS_PENDING and checked only against a
// generated header copy (recorded pending-build-only, not counted).
// >>> native-status (generated) -- do not edit >>>
// DebugSettings | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | 1 referenced strings (not rechecked) | by king_originala (chatgpt:gpt-6.1-sol)
// <<< native-status | src 81554b5f | roc native-status --write
#include "v8datamodel/DebugSettings.h"
#include "v8datamodel/PartInstance.h"
#ifdef NATIVE_DEBUGSETTINGS_PENDING
#include "v8datamodel/ModelInstance.h" // pulls the donor Camera.h, which needs the 2008 class-name declaration
#endif
#include "reflection/enumconverter.h"
#include <G3D/format.h>
#include <stdexcept>

namespace RBX
{
	const char sDebugSettings[] = "DebugSettings"; // 0082dfb8

	// Template members the shared headers only declare (same definitions as native-classes/NetworkSettings.cpp).
	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::FactoryProduct() : D() {}

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	template<class C, class D, const char* N>
	DescribedCreatable<C, D, N>::DescribedCreatable()
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}

	template<typename Class, const char* ClassName>
	GlobalSettingsItem<Class, ClassName>* GlobalSettingsItem<Class, ClassName>::sing = NULL; // 0096c318

	// 005655b0: the 2008 item names itself after its class and refuses a second instance.
	template<typename Class, const char* ClassName>
	GlobalSettingsItem<Class, ClassName>::GlobalSettingsItem()
	{
		setName(ClassName);
		if (sing)
			throw std::runtime_error(G3D::format("singleton %s already exists", ClassName));
		sing = this;
	}

	// 005640a0 (deleting 00565bd0).
	template<typename Class, const char* ClassName>
	GlobalSettingsItem<Class, ClassName>::~GlobalSettingsItem()
	{
		sing = NULL;
	}

	Reflection::EnumDesc<DebugSettings::ErrorReporting>::EnumDesc()         // 00564a60
		: EnumDescriptor("ErrorReporting", typeid(DebugSettings::ErrorReporting))
	{
		addPair(DebugSettings::DontReport, "DontReport");
		addPair(DebugSettings::Prompt, "Prompt");
		addPair(DebugSettings::Report, "Report");
	}

#ifdef NATIVE_DEBUGSETTINGS_PENDING
	Reflection::EnumDesc<World::EThrottle>::EnumDesc()                      // 00564be0
		: EnumDescriptor("EnviromentalPhysicsThrottle", typeid(World::EThrottle))
	{
		addPair(World::DefaultAuto, "DefaultAuto");
		addPair(World::Disabled, "Disabled");
		addPair(World::Random, "Random");
		addPair(World::Always, "Always");
	}
#endif

	Reflection::EnumDesc<Debugable::AssertAction>::EnumDesc()               // 00564d70
		: EnumDescriptor("AssertAction", typeid(Debugable::AssertAction))
	{
		addPair(Debugable::CrashOnAssert, "CrashOnAssert");
		addPair(Debugable::IgnoreAssert, "IgnoreAssert");
	}

	// Dynamic initializers 007f2c30..007f3200, in this order (Functionality 5 = STANDARD, 4 = STREAMING).
	static Reflection::PropDescriptor<DebugSettings, float> prop_ShaderModel("ShaderModel", "Profile", &DebugSettings::shaderModel, NULL, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<DebugSettings, int> prop_VideoMemory("VideoMemory", "Profile", &DebugSettings::videoMemory, NULL, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<DebugSettings, int> prop_CpuSpeed("CpuSpeed", "Profile", &DebugSettings::cpuSpeed, NULL, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<DebugSettings, int> prop_CpuCount("CpuCount", "Profile", &DebugSettings::cpuCount, NULL, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<DebugSettings, int> prop_OsPlatformId("OsPlatformId", "Profile", &DebugSettings::osPlatformId, NULL, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<DebugSettings, std::string> prop_OsVer("OsVer", "Profile", &DebugSettings::osVer, NULL, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<DebugSettings, std::string> prop_SystemProductName("SystemProductName", "Profile", &DebugSettings::systemProductName, NULL, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<DebugSettings, std::string> prop_GlVendor("GlVendor", "Profile", &DebugSettings::glVendor, NULL, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<DebugSettings, std::string> prop_GfxCard("GfxCard", "Profile", &DebugSettings::gfxcard, NULL, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<DebugSettings, std::string> prop_CPU("CPU", "Profile", &DebugSettings::cpu, NULL, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<DebugSettings, int> prop_RAM("RAM", "Profile", &DebugSettings::ram, NULL, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<DebugSettings, std::string> prop_Resolution("Resolution", "Profile", &DebugSettings::resolution, NULL, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::BoundProp<bool, 1> prop_SoundWarnings("SoundWarnings", "Errors", &DebugSettings::soundWarnings, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::BoundProp<bool, 1> prop_StackTracingEnabled("stackTracingEnabled", "Scripts", &DebugSettings::stackTracingEnabled, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::BoundProp<bool, 1> prop_IoEnabled("ioEnabled", "Scripts", &DebugSettings::ioEnabled, Reflection::PropertyDescriptor::STREAMING);
	static Reflection::PropDescriptor<DebugSettings, bool> prop_ShowAnchors("ShowAnchors", "Display", &DebugSettings::getShowAnchoredParts, &DebugSettings::setShowAnchoredParts, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<DebugSettings, bool> prop_ShowPartCoords("ShowPartCoords", "Display", &DebugSettings::getShowPartCoordinateFrames, &DebugSettings::setShowPartCoordinateFrames, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<DebugSettings, bool> prop_ShowUnalignedParts("ShowUnalignedParts", "Display", &DebugSettings::getShowUnalignedParts, &DebugSettings::setShowUnalignedParts, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<DebugSettings, bool> prop_ShowModelCoords("ShowModelCoords", "Display", &DebugSettings::getShowModelCoordinateFrames, &DebugSettings::setShowModelCoordinateFrames, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<DebugSettings, bool> prop_ShowWorldCoords("ShowWorldCoords", "Display", &DebugSettings::getShowWorldCoordinateFrames, &DebugSettings::setShowWorldCoordinateFrames, Reflection::PropertyDescriptor::STANDARD);
#ifdef NATIVE_DEBUGSETTINGS_PENDING
	static Reflection::EnumPropDescriptor<DebugSettings, World::EThrottle> prop_PhysicsEnviromentalThrottle("PhysicsEnviromentalThrottle", "Throttle", &DebugSettings::getEnvironmentalThrottle, &DebugSettings::setEnvironmentalThrottle, Reflection::PropertyDescriptor::STANDARD);
#endif
	static Reflection::PropDescriptor<DebugSettings, bool> prop_30FpsThrottle("30FpsThrottle", "Throttle", &DebugSettings::get30FpsThrottle, &DebugSettings::set30FpsThrottle, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<DebugSettings, bool> prop_DistributedPhysics("DistributedPhysics", "Throttle", &DebugSettings::getDistributedPhysics, &DebugSettings::setDistributedPhysics, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<DebugSettings, double> prop_ProfilerWindow("ProfilerWindow", "Profiling", &DebugSettings::getProfilerWindow, &DebugSettings::setProfilerWindow, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<DebugSettings, double> prop_ProfilerBucketTimeSpan("ProfilerBucketTimeSpan", "Profiling", &DebugSettings::getProfilerBucketTimeSpan, &DebugSettings::setProfilerBucketTimeSpan, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<DebugSettings, bool> prop_ValidatingDebug("ValidatingDebug", "Errors", &DebugSettings::getValidatingDebug, &DebugSettings::setValidatingDebug, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::EnumPropDescriptor<DebugSettings, Debugable::AssertAction> prop_AssertAction("AssertAction", "Errors", &DebugSettings::getAssertAction, &DebugSettings::setAssertAction, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::EnumPropDescriptor<DebugSettings, DebugSettings::ErrorReporting> prop_ErrorReporting("errorReporting", "Errors", &DebugSettings::getErrorReporting, &DebugSettings::setErrorReporting, Reflection::PropertyDescriptor::STANDARD);

	DebugSettings::DebugSettings()
		: stackTracingEnabled(true),
		  ioEnabled(false),
		  soundWarnings(false),
		  errorReporting(Prompt)
	{
		setName("Diagnostics");
	}

	bool DebugSettings::getValidatingDebug() const
	{
		return Debugable::validatingDebug;
	}

	Debugable::AssertAction DebugSettings::getAssertAction() const
	{
		return Debugable::assertAction;
	}

	bool DebugSettings::getShowAnchoredParts() const
	{
		return PartInstance::showAnchoredParts;
	}

	bool DebugSettings::getShowUnalignedParts() const
	{
		return PartInstance::showUnalignedParts;
	}

	bool DebugSettings::getShowPartCoordinateFrames() const
	{
		return PartInstance::showPartCoord;
	}

#ifdef NATIVE_DEBUGSETTINGS_PENDING
	bool DebugSettings::getShowModelCoordinateFrames() const
	{
		return ModelInstance::showModelCoord;
	}
#endif

	void DebugSettings::setShowAnchoredParts(bool value)
	{
		if (value != PartInstance::showAnchoredParts)
		{
			PartInstance::showAnchoredParts = value;
			raisePropertyChanged(prop_ShowAnchors);
		}
	}

	void DebugSettings::setShowUnalignedParts(bool value)
	{
		if (value != PartInstance::showUnalignedParts)
		{
			PartInstance::showUnalignedParts = value;
			raisePropertyChanged(prop_ShowPartCoords); // 00565c20 pushes prop_ShowPartCoords (009745dc), as the donor
		}
	}

	void DebugSettings::setShowPartCoordinateFrames(bool value)
	{
		if (value != PartInstance::showPartCoord)
		{
			PartInstance::showPartCoord = value;
			raisePropertyChanged(prop_ShowPartCoords);
		}
	}

#ifdef NATIVE_DEBUGSETTINGS_PENDING
	void DebugSettings::setShowModelCoordinateFrames(bool value)
	{
		if (value != ModelInstance::showModelCoord)
		{
			ModelInstance::showModelCoord = value;
			raisePropertyChanged(prop_ShowModelCoords);
		}
	}
#endif

	void DebugSettings::setValidatingDebug(bool value)
	{
		if (value != Debugable::validatingDebug)
		{
			Debugable::validatingDebug = value;
			raisePropertyChanged(prop_ValidatingDebug);
		}
	}

	void DebugSettings::setAssertAction(Debugable::AssertAction value)
	{
		if (value != Debugable::assertAction)
		{
			Debugable::assertAction = value;
			raisePropertyChanged(prop_AssertAction);
		}
	}

#ifdef NATIVE_DEBUGSETTINGS_PENDING
	World::EThrottle DebugSettings::getEnvironmentalThrottle() const
	{
		return World::environmentalThrottle;
	}

	void DebugSettings::setEnvironmentalThrottle(World::EThrottle value)
	{
		if (value != World::environmentalThrottle)
		{
			World::environmentalThrottle = value;
			raisePropertyChanged(prop_PhysicsEnviromentalThrottle);
		}
	}
#endif

	void DebugSettings::setErrorReporting(ErrorReporting value)
	{
		if (value != errorReporting)
		{
			errorReporting = value;
			raisePropertyChanged(prop_ErrorReporting);
		}
	}
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class RBX::Reflection::TypedPropertyDescriptor<enum RBX::DebugSettings::ErrorReporting>;
template class RBX::Reflection::TypedPropertyDescriptor<enum RBX::Debugable::AssertAction>;
template class std::_Container_base_aux_alloc_real<std::allocator<enum RBX::DebugSettings::ErrorReporting> >;
template class std::_Container_base_aux_alloc_real<std::allocator<enum RBX::Debugable::AssertAction> >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<RBX::Name const * const,enum RBX::DebugSettings::ErrorReporting> > >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<RBX::Name const * const,enum RBX::Debugable::AssertAction> > >;
template class std::_Tmap_traits<RBX::Name const *,enum RBX::DebugSettings::ErrorReporting,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::DebugSettings::ErrorReporting> >,0>;
template class std::_Tmap_traits<RBX::Name const *,enum RBX::Debugable::AssertAction,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::Debugable::AssertAction> >,0>;
template class std::_Tree<std::_Tmap_traits<RBX::Name const *,enum RBX::DebugSettings::ErrorReporting,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::DebugSettings::ErrorReporting> >,0> >;
template class std::_Tree<std::_Tmap_traits<RBX::Name const *,enum RBX::Debugable::AssertAction,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::Debugable::AssertAction> >,0> >;
template class std::_Vector_const_iterator<enum RBX::DebugSettings::ErrorReporting,std::allocator<enum RBX::DebugSettings::ErrorReporting> >;
template class std::_Vector_const_iterator<enum RBX::Debugable::AssertAction,std::allocator<enum RBX::Debugable::AssertAction> >;
template class std::_Vector_iterator<enum RBX::DebugSettings::ErrorReporting,std::allocator<enum RBX::DebugSettings::ErrorReporting> >;
template class std::_Vector_iterator<enum RBX::Debugable::AssertAction,std::allocator<enum RBX::Debugable::AssertAction> >;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<RBX::Name const *,enum RBX::DebugSettings::ErrorReporting,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::DebugSettings::ErrorReporting> >,0> >::_Node *>;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<RBX::Name const *,enum RBX::Debugable::AssertAction,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::Debugable::AssertAction> >,0> >::_Node *>;
template class std::allocator<std::pair<RBX::Name const * const,enum RBX::DebugSettings::ErrorReporting> >;
template class std::allocator<std::pair<RBX::Name const * const,enum RBX::Debugable::AssertAction> >;
template class std::vector<enum RBX::DebugSettings::ErrorReporting,std::allocator<enum RBX::DebugSettings::ErrorReporting> >;
template class std::vector<enum RBX::Debugable::AssertAction,std::allocator<enum RBX::Debugable::AssertAction> >;

// Name registrations emitted by this unit (bytes and sX relocation identity proven against the 2008-06 client).
template void RBX::Name::callDoDeclare<RBX::sDebugSettings>();
