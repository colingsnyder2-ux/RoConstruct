#pragma once
// >>> native-status (generated) -- do not edit >>>
// Lighting2008 | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 52e9143d | roc native-status --write
// 2008-06 native RBX::Lighting (inactive). A new, non-colliding header (the donor v8datamodel/Lighting.h keeps
// its path and is not shadowed). Shape after the donor tools/rbxgs Lighting.h; every base, field and virtual below
// is read from the 2008-06 binary (verified by tests/record_native_lighting2008.py):
//   RTTI       vtable 0083deec .?AVLighting@RBX@@: DescribedCreatable<Lighting, Instance, sLighting> (name mangled
//              $1?sLighting@2@3PADA, a char array in .data at 0095442c) and Service at +0x130 (22 bases).
//   size       0x2e0: Creatable<Instance>::create<Lighting> 004adb60 allocates 0x2e0 (8-aligned: time_duration).
//   ctor       005e1a40: LightingParameters ctor 007b6860 on +0x130 (0xf8 bytes, ends +0x228); ambientTop
//              (209,208,217)/255 +0x228; ambientBottom (122,134,120)/255 +0x234; hasSky = 1 +0x240; clearColor =
//              Color4(Color3::white() 00514a60, 1) +0x244; Color4(0.7, 0.7, 0.72, 1) +0x254 (read back by the
//              getter 005df4a0); timeOfDay = duration_from_string("14:00:00") +0x268 (int64 ticks); the 0x64-byte
//              value group +0x270..+0x2d4 that ViewRbxGfx 004dab50 copies to the render scene (colour shifts 0,
//              brightness 1, ambient 0.5, then three white Color3, one zero Color3, one white Color3); sky
//              shared_ptr +0x2d4/+0x2d8 = 0; then skyParameters.lightColor (+0x154) = (152,137,102)/255,
//              skyParameters.setTime(timeOfDay.total_seconds()) (__alldiv by 1000000, 007b59b0), setName("Lighting").
//   dtor       005e1d60 (implicit: no vtable pointer stores): releases the sky shared_ptr (+0x2d8 count), then
//              ~FactoryProduct 005df560; deleting destructor 005e1de0.
//   vtable     overrides askAddChild (slot 2, 005df530: dynamic_cast<const Sky*>), onChildAdded (slot 7, 005e2160),
//              onChildRemoving (slot 8, 005e2100) and onChildChanged (slot 15, 005e2260); the last three fire
//              event_LightingChanged(true) (0097a88c) and RunService::invalidateRunViews 00555350.
// The names of the +0x298..+0x2d0 Color3 group follow the render-scene use recorded in tests/LightingRecovery.md
// (main diffuse / specular, fill diffuse / specular / scale); no reflected property names them.
#include "v8tree/Instance.h"
#include "v8tree/Service.h"
#include <GLG3D/LightingParameters.h>
#include <G3D/Color4.h>
#include <boost/date_time/posix_time/posix_time_types.hpp>

namespace RBX
{
	namespace ViewNew { class ViewRbxGfx; }
	class Sky;

	extern char sLighting[];

	class Lighting
		: public DescribedCreatable<Lighting, Instance, sLighting>,
		  public Service
	{
		// INFERRED access relationship; 004dab50 directly reads the proven lighting fields.
		friend class ViewNew::ViewRbxGfx;
	private:
		G3D::LightingParameters skyParameters;          // +0x130
		G3D::Color3 ambientTop;                         // +0x228
		G3D::Color3 ambientBottom;                      // +0x234
		bool hasSky;                                    // +0x240
		G3D::Color4 clearColor;                         // +0x244
		G3D::Color4 shadowColor;                        // +0x254
		boost::posix_time::time_duration timeOfDay;     // +0x268
		G3D::Color3 colorShiftTop;                      // +0x270 (ColorShift_Top)
		G3D::Color3 colorShiftBottom;                   // +0x27c (ColorShift_Bottom)
		float brightness;                               // +0x288 (Brightness)
		G3D::Color3 ambient;                            // +0x28c (Ambient)
		G3D::Color3 mainDiffuse;                        // +0x298
		G3D::Color3 mainSpecular;                       // +0x2a4
		G3D::Color3 fillDiffuse;                        // +0x2b0
		G3D::Color3 fillSpecular;                       // +0x2bc
		G3D::Color3 fillScale;                          // +0x2c8
	public:
		boost::shared_ptr<Sky> sky;                     // +0x2d4

	public:
		// SignalDesc ctor 005e1490 ("LightingChanged", "skyboxChanged"); initializer 007f69b0, atexit 007ff8c0.
		static Reflection::SignalDesc<Lighting, void(bool)> event_LightingChanged;   // 0097a88c

	public:
		Lighting();                                     // 005e1a40

	public:
		void replaceSky(Sky* newSky);                   // 005e0650

		G3D::Vector3 getMoonPosition();                 // 005df4d0
		G3D::Vector3 getSunPosition();                  // 005df500
		std::string getTimeStr() const;                 // 005e0be0

	protected:
		virtual bool askAddChild(const Instance* instance) const;   // 005df530
		virtual void onChildAdded(Instance* child);                  // 005e2160
		virtual void onChildRemoving(Instance* child);               // 005e2100
		virtual void onChildChanged(Instance* instance, const PropertyChanged& event);   // 005e2260

	private:
		void fireLightingChanged(bool value)            // inline in 005e2100 / 005e2160 / 005e2260
		{
			event_LightingChanged.fire(this, value);
		}
	};
}
