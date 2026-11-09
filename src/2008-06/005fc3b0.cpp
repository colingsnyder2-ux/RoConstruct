// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_1d1dc8be5ba96da0.cpp

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
#include "v8datamodel/GuiBuilder.h"
#include "v8datamodel/LocalBackpack.h"
#include "v8datamodel/Backpack.h"
namespace RBX
{
	void LocalBackpack::clearLocalCharacter()
	{
		if (localCharacter)
		{
			Notifier<Instance, DescendentAdded>::disconnect(localCharacter, this);
			Notifier<Instance, DescendentRemoving>::disconnect(localCharacter, this);

			localCharacter.reset();
		}
	}

	void LocalBackpack::clearAll()
	{
		clearLocalCharacter();
		clearLocalPlayer();
		clearLocalBackpack();

		if (players)
		{
			Notifier<Instance, ChildAdded>::disconnect(players.get(), this);
			Notifier<Instance, ChildRemoved>::disconnect(players.get(), this);

			players.reset();
		}
	}
}
