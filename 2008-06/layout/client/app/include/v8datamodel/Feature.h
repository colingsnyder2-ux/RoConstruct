#pragma once
#include "v8tree/Instance.h"
#include "util/IRenderable.h"
#include "util/NormalId.h"
#include "v8datamodel/JointInstance.h"
#include <boost/shared_ptr.hpp>
#include <boost/signals/connection.hpp>

struct NativeFeatureLayout;

namespace RBX
{
	extern const char sFeature[];

	class Feature : public DescribedNonCreatable<Feature, Instance, sFeature>,
					public IRenderable
	{
		friend struct ::NativeFeatureLayout; // tests/NativeFeatureLayout.cpp offset asserts
	public:
		enum TopBottom
		{
			TOP = 0,
			CENTER_TB = 1,
			BOTTOM = 2
		};

		enum LeftRight
		{
			LEFT = 0,
			CENTER_LR = 1,
			RIGHT = 2
		};

		enum InOut
		{
			EDGE = 0,
			INSET = 1,
			CENTER_IO = 2
		};

		enum InOutZ
		{
			Z_IN = 0,
			Z_OUT = 1
		};

	protected:
		NormalId faceId;           // +0x140
		TopBottom topBottom;       // +0x144
		LeftRight leftRight;       // +0x148
		InOut inOut;               // +0x14c

	private:
		virtual bool askSetParent(const Instance* instance) const
		{
			return true;           // 00565ff0 (ICF-shared)
		}
		virtual bool shouldRender3dAdorn() const
		{
			return true;           // 00565950 (ICF-shared)
		}
		virtual void render3dSelect(Adorn* adorn, SelectState selectState); // 0060a520

	protected:
		bool getRenderCoord(G3D::CoordinateFrame& c) const;                 // 0060a490
		virtual InOutZ getCoordOrientation() const
		{
			return Z_OUT;          // 007286a0 (ICF-shared)
		}

	public:
		Feature();                 // 0060be60
		virtual ~Feature();        // 0060a360 (deleting 0060ab00)

		NormalId getFaceId() const          // 00609a30 (ICF-shared getter)
		{
			return faceId;
		}
		void setFaceId(NormalId value);     // 0060c340

		TopBottom getTopBottom() const      // 004a1560 (ICF-shared getter)
		{
			return topBottom;
		}
		void setTopBottom(TopBottom value); // 0060c370

		LeftRight getLeftRight() const      // 00609a40
		{
			return leftRight;
		}
		void setLeftRight(LeftRight value); // 0060c3a0

		InOut getInOut() const              // 00609a50
		{
			return inOut;
		}
		void setInOut(InOut value);         // 0060c3d0

		G3D::CoordinateFrame computeLocalCoordinateFrame() const; // 00609da0
	};

	extern const char sHole[];

	class Hole : public DescribedCreatable<Hole, Feature, sHole>
	{
	private:
		virtual void render3dAdorn(Adorn* adorn); // 0060a580
		virtual InOutZ getCoordOrientation() const
		{
			return Z_IN;           // 00416690 (ICF-shared)
		}

	public:
		Hole();                    // 0060c840
	};

	extern const char sMotorFeature[];

	class MotorFeature : public DescribedCreatable<MotorFeature, Feature, sMotorFeature>
	{
	private:
		virtual void render3dAdorn(Adorn* adorn); // 0060a5e0

	public:
		MotorFeature();            // 0060c910

		static bool canJoin(Instance* a, Instance* b); // 00609a60
		static void join(Instance* a, Instance* b);    // 0060ca00
	};

	class MotorJoint;
	extern const char sVelocityMotor[];

	class VelocityMotor : public DescribedCreatable<VelocityMotor, JointInstance, sVelocityMotor>
	{
		friend struct ::NativeFeatureLayout; // tests/NativeFeatureLayout.cpp offset asserts
	private:
		boost::shared_ptr<Hole> hole;                            // +0x154
		boost::signals::scoped_connection holeAncestorChanged;  // +0x15c

		const MotorJoint* motorJoint() const;        // inline (Feature.cpp)
		MotorJoint* motorJoint();

		void onEvent_HoleAncestorChanged();          // 0060a230
		void setPart(int i, Feature* feature);       // 0060a020

		virtual bool askSetParent(const Instance* instance) const
		{
			return true;                             // 00565ff0 (ICF-shared)
		}
		virtual void onAncestorChanged(const AncestorChanged& event); // 0060a0f0

	public:
		VelocityMotor();                             // 0060bbb0
		virtual ~VelocityMotor();                    // 0060a650 (deleting 0060ab20)

		Hole* getHole() const                        // 005b0820 (ICF-shared getter)
		{
			return hole.get();
		}
		void setHole(Hole* value);                   // 0060c400

		float getMaxVelocity() const;                // 0060a240
		void setMaxVelocity(float value);            // 0060c580

		float getDesiredAngle() const;               // 0060a250
		void setDesiredAngle(float value);           // 0060c5c0

		float getCurrentAngle() const;               // 005e2900 (ICF-shared)
		void setCurrentAngle(float value);           // 0060c600
	};
}
