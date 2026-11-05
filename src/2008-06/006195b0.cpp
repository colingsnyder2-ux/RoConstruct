// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_b83817ce1c2ae7a8.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#undef _DEBUG
#define _DLL
#define private public
#include "util/IRenderable.h"
#undef private
#include "util/Object.h"
#define hasListeners() hasListeners() const { return listeners.size() > 0; } bool hasListenersEmpty()
#include "util/Events.h"
#undef hasListeners
namespace RBX { template<class T> class GuidItem { public: virtual ~GuidItem() {} char guidPad[0xc]; }; }
namespace RBX { template<class T> class GuidAFP : public AbstractFactoryProduct<T> { protected: virtual void onGuidChanged() {} }; }
#define AbstractFactoryProduct GuidItem<Instance>, public GuidAFP
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
#define SurfacesNeedAdorn SurfacesNeedAdorn; char exePartPad[0x118]
#include "v8datamodel/PartInstance.h"
#undef SurfacesNeedAdorn
#include "v8datamodel/FlagStand.h"
#include "humanoid/Humanoid.h"
#include "Network/Player.h"
#include "Network/Players.h"
namespace RBX
{
	void Flag::onEvent_flagTouched(boost::shared_ptr<Instance> other)
	{
		Instance* parent = other->getParent();

		Humanoid* humanoid = Humanoid::modelIsCharacter(parent);
		if (!humanoid)
			return;

		Network::Player* player = Network::Players::getPlayerFromCharacter(parent);
		if (!player)
			return;

		if (player->getNeutral() != false)
			return;

		BrickColor current = teamColor;
		if (player->getTeamColor() != current)
			return;

		FlagStandService* fss = ServiceProvider::create<FlagStandService>(this);
		if (!fss->FindStandWithFlag(this))
		{
			if (FlagStand* fs = fss->FindClosestEmptyStandForFlag(this))
			{
				fs->AffixFlag(this);
			}
		}
	}
}
