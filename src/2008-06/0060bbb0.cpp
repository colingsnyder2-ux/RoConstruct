// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_518ebf69a098e554.cpp

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
#define polarity polarity(); typedef int polarityNotInExe
#include "v8world/MotorJoint.h"
#undef polarity
#include "v8datamodel/PartInstance.h"
namespace RBX { class IJointOwnerExe : public IJointOwner { protected: boost::shared_ptr<PartInstance> exeParts[2]; }; }
#define IJointOwner IJointOwnerExe
#include "v8datamodel/JointInstance.h"
#undef IJointOwner
#include "v8datamodel/Feature.h"
namespace RBX
{
	VelocityMotor::VelocityMotor()
		: DescribedCreatable(new MotorJoint())
	{
		setName("VelocityMotor");
	}
}
