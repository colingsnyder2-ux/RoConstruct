#pragma once
#include <GLG3D/LightingParameters.h>
#include "v8tree/Service.h"
#include "v8datamodel/Sky.h"

namespace RBX
{
	class Sky;

	extern const char* sLighting;
	class Lighting : public DescribedCreatable<Lighting, Instance, &sLighting>,
					 public Service
	{
	private:
		G3D::LightingParameters skyParameters;
		G3D::Color3 ambientTop;
		G3D::Color3 ambientBottom;
		bool hasSky;
		G3D::Color4 shadowColor;
		G3D::Color4 clearColor;
		boost::posix_time::time_duration timeOfDay;
		// Names are placeholders from the 100% codegen proof for the 2008 ctor;
		// the types and stores are what the target bytes prove (0x270..0x2d3).
		G3D::Color3 v0;	// ColorShift_Top (2008 PropDescriptor<Lighting, Color3>)
		G3D::Color3 v1;	// ColorShift_Bottom (2008 PropDescriptor<Lighting, Color3>)
		float f0;
		G3D::Color3 c0;
		G3D::Color3 c1;
		G3D::Color3 c2;
		G3D::Color3 c3;
		G3D::Vector3 v2;
		G3D::Vector3 v3;
	public:
		boost::shared_ptr<Sky> sky;

	public:
		static Reflection::SignalDesc<Lighting, void(bool)> event_LightingChanged;

	public:
		Lighting();
	public:
		void replaceSky(Sky* newSky);
		bool isSkySuppressed() const;
		void suppressSky(const bool);

		const G3D::LightingParameters& getSkyParameters() const
		{
			return skyParameters;
		}

		G3D::Color4 getClearColor() const
		{
			return clearColor;
		}

		void setClearColor(G3D::Color4 value);

		G3D::Color3 getLightColor() const
		{
			return skyParameters.lightColor;
		}

		void setLightColor(G3D::Color3 value);

		G3D::Color3 getAmbientTop() const
		{
			return ambientTop;
		}

		void setAmbientTop(G3D::Color3 value);

		G3D::Color3 getAmbientBottom() const
		{
			return ambientBottom;
		}

		void setAmbientBottom(G3D::Color3 value);
		std::string getTimeStr() const;
		void setTimeStr(const std::string& value);
		void setTime(const boost::posix_time::time_duration& value);
		double getGameTime() const;
		double getMinutesAfterMidnight();
		void setMinutesAfterMidnight(double value);

		float getMoonPhase()
		{
			return skyParameters.moonPhase;
		}

		G3D::Vector3 getMoonPosition();
		G3D::Vector3 getSunPosition();

		float getGeographicLatitude() const
		{
			return skyParameters.geoLatitude;
		}

		void setGeographicLatitude(float value);

		// 2008 "ColorShift_Top", "ColorShift_Bottom", "Brightness" and "Ambient"
		// properties (names from the 2008 descriptor strings; storage 0x270/0x27c/0x288/0x28c).
		G3D::Color3 getColorShift_Top() const
		{
			return v0;
		}

		void setColorShift_Top(G3D::Color3 value);

		G3D::Color3 getColorShift_Bottom() const
		{
			return v1;
		}

		void setColorShift_Bottom(G3D::Color3 value);

		float getBrightness() const
		{
			return f0;
		}

		void setBrightness(float value);

		G3D::Color3 getAmbient() const
		{
			return c0;
		}

		void setAmbient(G3D::Color3 value);

		G3D::Color3 getClearColor3() const
		{
			return G3D::Color3(clearColor.r, clearColor.g, clearColor.b);
		}

		void setClearColor3(G3D::Color3 value)
		{
			setClearColor(G3D::Color4(value));
		}

	protected:
		virtual void onChildAdded(Instance* child);
		virtual void onChildRemoving(Instance* child);
		virtual void onChildChanged(Instance* instance, const PropertyChanged& event);
		virtual bool askAddChild(const Instance* instance) const;
	private:
		void fireLightingChanged(bool value)
		{
			event_LightingChanged.fire(this, value);
		}
	};
}
