// from server: 100% by EspClaude
// from server: 89% by nuck16
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_6308dc69f389a1dd.cpp

// Candidate translation unit (score above; library headers required).
#define _CPPUNWIND 1
#include <string>
#include <boost/shared_ptr.hpp>
#include "G3D/ReferenceCount.h"
#include "G3D/Vector3.h"
#include "G3D/Color4.h"
#include "G3D/CoordinateFrame.h"
namespace G3D { class GImage { public: class Error { public: char prefix[0x28]; std::string reason; }; }; }

namespace G3D {
class LightingParameters {
public:
    Color3 emissiveScale; Color3 skyAmbient; Color3 diffuseAmbient; Color3 lightColor; Color3 ambient;
    Vector3 lightDirection;
    enum {SUN, MOON} source;
    bool physicallyCorrect;
    Vector3 trueSunPosition; Vector3 sunPosition; Vector3 trueMoonPosition; Vector3 moonPosition;
    double moonPhase;
    CoordinateFrame starFrame; CoordinateFrame trueStarFrame;
    Vector3 starVec;
    float geoLatitude;
    LightingParameters();
};
}
namespace RBX
{
	using G3D::LightingParameters;
	enum MessageType { MESSAGE_OUTPUT, MESSAGE_INFO, MESSAGE_WARNING, MESSAGE_ERROR };
	class StandardOut
	{
	public:
		static boost::shared_ptr<StandardOut> singleton();
		void __cdecl print(MessageType type, const char* format, ...);
	};
	class SkyParameters;
	class Sky : public G3D::ReferenceCountedObject
	{
	public:
		static G3D::ReferenceCountedPointer<Sky> create(SkyParameters* parameters);
	};
	typedef G3D::ReferenceCountedPointer<Sky> SkyRef;
	class Lighting
	{
	public:
		char pad0[0x130];
		LightingParameters parameters;
		G3D::Vector3 ambientBottom;
		G3D::Vector3 ambientTop;
		bool skyEnabled;
		char pad241[3];
		G3D::Color4 clearColor;
		char pad254[0x2d4 - 0x254];
		SkyParameters* skyParameters;
	};
	class LightingHolder
	{
	public:
		Lighting* getLighting();
	};
	class Renderer
	{
	public:
		virtual void v0();
		virtual void setLighting(SkyRef sky, LightingParameters parameters, G3D::Vector3 ambientBottom, G3D::Vector3 ambientTop);
		char pad4[0x10];
		G3D::Color4 clearColor;
	};
	namespace ViewNew
	{
		class ViewG3D
		{
		public:
			virtual ~ViewG3D();
			int pad4;
			Renderer* renderer;
			char padc[8];
			LightingHolder* holder;
			char pad18[0x44 - 0x18];
			bool lightingValid;
			SkyRef sky;
			void updateLighting();
		};

		struct EmptyD { int v; EmptyD(int x):v(x){} ~EmptyD(){} int get() const { return v; } };
		void ViewG3D::updateLighting()
		{
			if (lightingValid)
				return;
			Lighting* lighting = (holder && EmptyD(1).get()) ? holder->getLighting() : NULL;
			if (!lighting->skyEnabled)
			{
				sky = NULL;
			}
			else if (sky.isNull())
			{
				try
				{
					SkyParameters* sp = lighting->skyParameters;
					sky = Sky::create(sp);
				}
				catch (G3D::GImage::Error& e)
				{
					StandardOut::singleton()->print(MESSAGE_ERROR, "Failed to load sky box. %s", e.reason.c_str());
				}
				catch (...)
				{
					StandardOut::singleton()->print(MESSAGE_ERROR, "Failed to load sky box");
				}
			}
			Renderer* r = renderer;
			r->setLighting(sky, lighting->parameters, lighting->ambientBottom, lighting->ambientTop);
			renderer->clearColor = G3D::Color4(lighting->clearColor);
			lightingValid = true;
		}
	}
}

