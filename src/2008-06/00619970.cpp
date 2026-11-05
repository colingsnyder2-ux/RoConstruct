// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_57f017ca04ba9151.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
#define TSignalDesc(a,b) TSIG_##b)
#define TSIG_name TSignalDesc(classDescriptor, name
#define TSIG_const void tsdGroupDummy(); public: boost::signals::connection connect(SignalSource* source, const boost::slot<boost::function<CallbackSignature> >& slot, int group) { if (source) return sig(*source).connect(group, slot); return boost::signals::connection(); } protected: TSignalDesc(ClassDescriptor& classDescriptor, const
#include "reflection/signal.h"
#undef TSignalDesc
#undef TSIG_name
#undef TSIG_const
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
#include "util/IRenderable.h"
#include "v8datamodel/IEquipable.h"
namespace RBX { struct ExePad8 { virtual void exePadV(); char exePad[0x2c]; }; }
#include "v8datamodel/Tool.h"
#include "v8datamodel/Flag.h"
#include "v8datamodel/PartInstance.h"
namespace RBX
{
	void Flag::onChildAdded(Instance* instance)
	{
		if (dynamic_cast<PartInstance*>(instance))
		{
			if (PartInstance* handle = getHandle())
			{
				flagTouched = PartInstance::event_Touched.connect(handle, boost::bind(&Flag::onEvent_flagTouched, this, _1), 10);
			}
		}
	}
}
