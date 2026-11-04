#pragma once
// 2008-06 native RBX::Feature, RBX::Hole and RBX::MotorFeature (inactive). Shape after the donor
// tools/rbxgs v8datamodel/Feature.h; every field, virtual and descriptor below is read from the 2008-06 binary.
// VelocityMotor (same source unit) is declared at the end of this header: see its block comment.
//   RTTI       Feature vtable 00842c74 .?AVFeature@RBX@@ -> DescribedNonCreatable<Feature, Instance, sFeature>
//              (22 bases, IRenderable at +0x130); Hole vtable 0084356c -> DescribedCreatable<Hole, Feature, sHole>,
//              MotorFeature vtable 00843654 -> DescribedCreatable<MotorFeature, Feature, sMotorFeature> (26 bases each).
//              Names mangle $1?s..@2@3QBDB: const char arrays in .rdata (sFeature 00842998, sHole 008429a0,
//              sMotorFeature 008429a8, pushed by doDeclare 00609c60 / 0057d6e0 / 0057d670).
//   size       0x150: Creatable<Instance>::create<Hole> 00580230 and create<MotorFeature> 0057ffc0 allocate 0x150.
//              Feature constructor 0060be60: IRenderable at +0x130 (+0x134/+0x138 = -1, +0x13c = 0), then
//              faceId +0x140 = 0, topBottom +0x144 = 1, leftRight +0x148 = 1, inOut +0x14c = 2, setName("Feature").
//   vtable     Instance slot 2 askAddChild stays Instance's 0068e880; slot 3 askSetParent -> 00565ff0 (return true,
//              ICF-shared); a new slot 16 getCoordOrientation: Feature/MotorFeature 007286a0 (return 1),
//              Hole 00416690 (return 0), both ICF-shared.
//              IRenderable (+0x130): shouldRender2d 0060a2f0 (default false), shouldRender3dAdorn 00565950 (true),
//              render2d default, render3dAdorn default / Hole 0060a580 / MotorFeature 0060a5e0,
//              render3dSelect Feature 0060a520.
//   descriptors (dynamic initializers 007f7bc0..007f7c80, "Data" category 00822490, all Functionality 5):
//              prop_FaceId 0097be5c (EnumPropDescriptor<Feature, NormalId>, getter 00609a30, setter 0060c340),
//              prop_TopBottom 0097bdd8 (004a1560 / 0060c370), prop_LeftRight 0097bdb4 (00609a40 / 0060c3a0),
//              prop_InOut 0097be38 (00609a50 / 0060c3d0); EnumDesc<TopBottom/LeftRight/InOut> constructors
//              0060b1d0 / 0060b350 / 0060b4d0 ("Top"/"Center"/"Bottom", "Left"/"Center"/"Right",
//              "Edge"/"Inset"/"Center").
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

	// VelocityMotor
	//   RTTI       vtable 00842d54 .?AVVelocityMotor@RBX@@ -> DescribedCreatable<VelocityMotor, JointInstance,
	//              sVelocityMotor> (27 bases: IRenderable +0x130, IJointOwner +0x140). sVelocityMotor 008429b8 is a
	//              const char array ($1?sVelocityMotor@2@3QBDB, pushed by doDeclare 0057d750).
	//   size       0x170: Creatable<Instance>::create<VelocityMotor> 005804a0 allocates 0x170, then calls 0060bbb0.
	//   fields     constructor 0060bbb0 (after DescribedCreatable(Joint*) 0060bab0 with new MotorJoint, 0x98 bytes,
	//              005e5bf0): hole shared_ptr +0x154/+0x158 = 0; holeAncestorChanged scoped_connection +0x15c
	//              (connection shared_ptr +0x160/+0x164, controlling +0x168, released +0x16c); setName("VelocityMotor").
	//              Destructor 0060a650: ~scoped_connection 005954b0 on +0x15c, then the shared_ptr at +0x154, then
	//              ~FactoryProduct 00609af0 (declaration order below). Both fields follow JointInstance, whose 2008
	//              layout ends at +0x154 (joint +0x150, JointInstance constructor 005e3870).
	//   vtable     slot 3 askSetParent -> 00565ff0 (return true, ICF-shared), slot 4 onAncestorChanged 0060a0f0
	//              (JointInstance's are 005e3790 / 005e3a80).
	//   descriptors (dynamic initializers 007f7ac0..007f7b80, "Data", Functionality 5): prop_Hole 0097bdfc
	//              (RefPropDescriptor<VelocityMotor, Hole>, getter 005b0820 ICF-shared, setter 0060c400),
	//              prop_MaxVelocity 0097be1c (0060a240 / 0060c580), prop_DesiredAngle 0097be9c (0060a250 / 0060c5c0),
	//              prop_CurrentAngle 0097be80 (005e2900 ICF-shared / 0060c600).
	//   joint      MotorJoint (constructor 005e5bf0): currentAngle +0x8c, maxVelocity +0x90, desiredAngle +0x94.
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
