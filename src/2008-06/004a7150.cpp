// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-net-dll roc_espclaude_e352497fd30fc5e7.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
#define canStreamWrite() canStreamWriteX(); virtual bool isWriteOnlyX() const { return false; } virtual void getVariantX() const {} virtual void setVariantX() const {} bool canStreamWrite()
#include "reflection/property.h"
#undef canStreamWrite
#include "util/Object.h"
#define hasListeners() hasListeners() const { return listeners.size() > 0; } bool hasListenersEmpty()
#include "util/Events.h"
#undef hasListeners
namespace RBX { template<class T> class GuidItem { public: virtual ~GuidItem() {} char guidPad[0xc]; }; }
#define AbstractFactoryProduct GuidItem<Instance>, public AbstractFactoryProduct
#include "util/Guid.h"
namespace RBX { class GuidStub { public: typedef Guid::Data Data; void assign(const Data&) {} operator const Guid&() const { return *(const Guid*)0; } }; }
#define Guid GuidStub
#include "v8tree/Instance.h"
#undef Guid
#undef AbstractFactoryProduct
#include <BitStream.h>
#include <StringCompressor.h>
#include "Streaming.h"
namespace RBX
{
	namespace Network
	{
		void StringReceiver::deserializeString(Reflection::Property& property, RakNet::BitStream& bitStream)
		{
			std::string value;
			receive(bitStream, value);
			
			if (property.getInstance())
			{
				Instance* instance = static_cast<Instance*>(property.getInstance());
				const Reflection::PropertyDescriptor& desc = property.getDescriptor();
				desc.setStringValue(instance, value);
			}
		}
	}
}
