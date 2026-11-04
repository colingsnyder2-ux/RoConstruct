#pragma once
// 2008-06 native RBX::Feature, RBX::Hole and RBX::MotorFeature (inactive). Shape after the donor
// tools/rbxgs v8datamodel/Feature.h; every field, virtual and descriptor below is read from the 2008-06 binary.
// VelocityMotor (same source unit, JointInstance-derived) is not part of this recovery.
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
		static void join(Instance* a, Instance* b);    // 0060ca00 (needs VelocityMotor: NATIVE_FEATURE_PENDING)
	};
}
