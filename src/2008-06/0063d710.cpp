// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_c51be8ad36632363.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
#include "RbxGraphics/Adorn.h"
#include "AppDraw/SelectState.h"
#include "util/IndexArray.h"
#define private public
#include "util/IRenderable.h"
#undef private
#include "util/Object.h"
namespace RBX { template<class T> class GuidItem { public: virtual ~GuidItem() {} char guidPad[0xc]; }; }
#define AbstractFactoryProduct GuidItem<Instance>, public AbstractFactoryProduct
#include "util/Guid.h"
namespace RBX { class GuidStub { public: typedef Guid::Data Data; void assign(const Data&) {} operator const Guid&() const { return *(const Guid*)0; } }; }
#define Guid GuidStub
#include "v8tree/Instance.h"
#undef Guid
#undef AbstractFactoryProduct
#include "v8datamodel/Hopper.h"
#include "v8datamodel/PartInstance.h"
namespace RBX
{
	class SparkleAdorn
	{
	public:
		virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4();
		virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8(); virtual void a9();
		virtual void a10(); virtual void a11(); virtual void a12(); virtual void a13();
		virtual void setObjectToWorldMatrix(const G3D::CoordinateFrame& c) = 0;
		virtual void a15(); virtual void a16(); virtual void a17(); virtual void a18();
		virtual void sparkles() = 0;
	};
	class SparkleRenderable
	{
	public:
		virtual void render3dAdorn(SparkleAdorn* adorn);
		int index2d, index3d, bucket;
	};
	class Sparkles : public Instance, public SparkleRenderable
	{
		int unk;
		bool enabled;
	public:
		void render3dAdorn(SparkleAdorn* adorn);
	};
	void Sparkles::render3dAdorn(SparkleAdorn* adorn)
	{
		if (PartInstance* part = dynamic_cast<PartInstance*>(getParent()))
		{
			if (enabled)
			{
				adorn->setObjectToWorldMatrix(G3D::CoordinateFrame(part->getCoordinateFrame().translation));
				adorn->sparkles();
			}
		}
	}
}
