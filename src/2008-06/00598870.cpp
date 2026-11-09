// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_8a8912a8f8ce25f9.cpp

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
#include "reflection/reflection.h"
#include "util/NormalId.h"
#define FaceInstance FaceInstanceOrig
#include "v8datamodel/FaceInstance.h"
#undef FaceInstance
namespace RBX
{
	class FaceInstance : public Reflection::Described<FaceInstance, &sFaceInstance, Instance>, public IRenderable
	{
	private:
		NormalId face;
	public:
		static const Reflection::EnumPropDescriptor<FaceInstance,NormalId> prop_Face;
		FaceInstance();
		NormalId getFace() const;
		void setFace(NormalId);
	protected:
		virtual bool askSetParent(const Instance*) const;
	};
}
#include "v8datamodel/Decal.h"
namespace RBX
{
	Texture::Texture()
		: studsPerTile(2.0f, 2.0f)
	{
		setName("Texture");
	}
}
