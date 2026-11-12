// from server: 84% by EspClaude
// from server: 76% by EspClaude
// from server: 100% by EspClaude
// from server: 89% by nuck16
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_claude_966538d1e77ce14c.cpp

// Candidate translation unit (score above; library headers required).
// 2007-08 layout from 004cf440: ViewG3D sky +4, holder +8, lightingValid +0x44, renderer +0x4c (direct setLighting call);
// Lighting parameters +0xe8, ambientBottom +0x1e0, ambientTop +0x1ec, skyEnabled +0x1f8, clearColor +0x1fc, skyParameters +0x218;
// Renderer clearColor +0x2f0; GImage::Error reason string at +0.
#define _CPPUNWIND 1
#include <string>
#include <boost/shared_ptr.hpp>
#include "G3D/ReferenceCount.h"
#include "G3D/Vector3.h"
#include "G3D/Color4.h"
#include "G3D/CoordinateFrame.h"
namespace G3D { class GImage { public: class Error { public: std::string reason; }; }; }

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
		char pad0[0xe8];
		LightingParameters parameters;
		G3D::Vector3 ambientBottom;
		G3D::Vector3 ambientTop;
		bool skyEnabled;
		char pad1f9[3];
		G3D::Color4 clearColor;
		char pad20c[0x218 - 0x20c];
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
		void setLighting(SkyRef sky, LightingParameters parameters, G3D::Vector3 ambientBottom, G3D::Vector3 ambientTop);
		char pad0[0x2f0];
		G3D::Color4 clearColor;
	};
	namespace ViewNew
	{
		class ViewG3D
		{
		public:
			virtual ~ViewG3D();
			SkyRef sky;
			LightingHolder* holder;
			char padc[0x44 - 0xc];
			bool lightingValid;
			char pad45[0x4c - 0x45];
			Renderer* renderer;
			void updateLighting();
			Renderer* getRenderer() const { return renderer; }
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
			getRenderer()->setLighting(sky, lighting->parameters, lighting->ambientBottom, lighting->ambientTop);
			renderer->clearColor = G3D::Color4(lighting->clearColor);
			lightingValid = true;
		}
	}
}

