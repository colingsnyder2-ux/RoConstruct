#pragma once
// 2008-06 native RBX::DebugSettings (inactive). Shape after the donor tools/rbxgs v8datamodel/DebugSettings.h; every
// base, field, accessor and descriptor below is read from the 2008-06 binary:
//   RTTI       vtable 0082e6e4 .?AVDebugSettings@RBX@@ -> GlobalSettingsItem<DebugSettings, sDebugSettings> (vtable
//              0082e2ac) -> DescribedCreatable<DebugSettings, GlobalSettings::Item, sDebugSettings> (0082e534) ->
//              FactoryProduct (0082e1a4), and the empty Service (mdisp 0x130). sDebugSettings is mangled
//              $1?sDebugSettings@2@3QBDB: a const char array in .rdata at 0082dfb8 holding "DebugSettings" (pushed by
//              the GlobalSettingsItem constructor 005655b0 and the class descriptor 00564ee0).
//   size       0x138: Creatable<Instance>::create<DebugSettings> 00407820 allocates 0x138 and calls the constructor
//              00565ac0, which stores +0x130 = true, +0x131 = false, +0x133 = false, +0x134 = 1 (Prompt) and calls
//              setName("Diagnostics") (string 008243a0). +0x132 is not written by the constructor; the bound properties
//              push +0x133 for SoundWarnings, so a byte member sits at +0x132 (the donor's validatingDebug, same place).
//   fields     property initializers 007f2e70..007f2ed0 push the member offsets: +0x130 stackTracingEnabled ("Scripts",
//              STANDARD), +0x131 ioEnabled ("Scripts", Functionality 4 = STREAMING), +0x133 SoundWarnings ("Errors").
//   accessors  types from the GetImpl / GetSetImpl RTTI names (.?AV?$GetSetImpl@P8DebugSettings@RBX@@BE_NXZP812@AEX_N@Z
//              etc.): getters `T () const`, setters `void (T)` by value; addresses are the ones the property
//              initializers 007f2c30..007f3200 push (noted per member). Getter names follow the donor where it has the
//              property, otherwise the 2008 property name (osVer / osPlatformId are evidence names).
//   enums      EnumDesc<ErrorReporting> 00564a60 ("ErrorReporting": DontReport 0, Prompt 1, Report 2);
//              EnumDesc<Debugable::AssertAction> 00564d70 ("AssertAction"); EnumDesc<World::EThrottle> 00564be0
//              ("EnviromentalPhysicsThrottle"; needs a World.h declaration, NATIVE_DEBUGSETTINGS_PENDING only).
#include "v8datamodel/GlobalSettings.h"
#include "util/Debug.h"
#include <string>
#ifdef NATIVE_DEBUGSETTINGS_PENDING
#include "v8world/World.h"
#endif

struct NativeSettingsItemsLayout;

namespace RBX
{
	extern const char sDebugSettings[];

	class DebugSettings : public GlobalSettingsItem<DebugSettings, sDebugSettings>
	{
		friend struct ::NativeSettingsItemsLayout; // tests/NativeSettingsItemsLayout.cpp offset asserts

	public:
		enum ErrorReporting
		{
			DontReport,
			Prompt,
			Report
		};

	public:
		bool stackTracingEnabled;      // +0x130
		bool ioEnabled;                // +0x131
	private:
		bool validatingDebug;          // +0x132 (never written in 2008; the property uses Debugable::validatingDebug)
	public:
		bool soundWarnings;            // +0x133
		ErrorReporting errorReporting; // +0x134

	public:
		DebugSettings();                                   // 00565ac0

		// "Profile" (read only)
		float shaderModel() const;                         // 00563a50
		int videoMemory() const;                           // 00563230
		int cpuSpeed() const;                              // 00563260
		int cpuCount() const;                              // 00563290
		int osPlatformId() const;                          // 00563330
		std::string osVer() const;                         // 005632c0
		std::string systemProductName() const;             // 00563370
		std::string glVendor() const;                      // 00563430
		std::string gfxcard() const;                       // 005634b0
		std::string cpu() const;                           // 005638c0
		int ram() const;                                   // 00563940
		std::string resolution() const;                    // 00563970

		// "Display"
		bool getShowAnchoredParts() const;                 // 00563120
		void setShowAnchoredParts(bool value);             // 00565bf0
		bool getShowUnalignedParts() const;                // 00563130
		void setShowUnalignedParts(bool value);            // 00565c20
		bool getShowPartCoordinateFrames() const;          // 00563140
		void setShowPartCoordinateFrames(bool value);      // 00565c50
		bool getShowModelCoordinateFrames() const;         // 00563150
		void setShowModelCoordinateFrames(bool value);     // 00565c80
		bool getShowWorldCoordinateFrames() const;         // 00563160
		void setShowWorldCoordinateFrames(bool value);     // 00565cb0

		// "Throttle"
#ifdef NATIVE_DEBUGSETTINGS_PENDING
		World::EThrottle getEnvironmentalThrottle() const; // 005631b0
		void setEnvironmentalThrottle(World::EThrottle value); // 00565d40
#endif
		bool get30FpsThrottle() const;                     // 005631a0
		void set30FpsThrottle(bool value);                 // 00565d10
		bool getDistributedPhysics() const;                // 00563190
		void setDistributedPhysics(bool value);            // 00565ce0

		// "Profiling"
		double getProfilerWindow() const;                  // 00563170
		void setProfilerWindow(double value);              // 005639f0
		double getProfilerBucketTimeSpan() const;          // 00563180
		void setProfilerBucketTimeSpan(double value);      // 00563a20

		// "Errors"
		bool getValidatingDebug() const;                   // 00563100
		void setValidatingDebug(bool value);               // 00565d70
		Debugable::AssertAction getAssertAction() const;   // 00563110
		void setAssertAction(Debugable::AssertAction value); // 00565da0
		ErrorReporting getErrorReporting() const           // ICF-shared 00445220
		{
			return errorReporting;
		}
		void setErrorReporting(ErrorReporting value);      // 00565dd0
	};
}
