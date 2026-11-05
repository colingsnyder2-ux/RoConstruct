// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-net-dll roc_unit_c815068b43dd88be.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("util/IRenderable.h", "roc_unit_ae7c6fa24fc9f234.cpp")
#pragma include_alias("v8tree/Instance.h", "roc_unit_8c90d966c8b03227.cpp")
#include "Replicator.h"
#include "NetworkSettings.h"
#include "util/standardout.h"
#include <stdexcept>
namespace RBX { namespace Network {
void Replicator::DeleteInstanceItem::write(RakNet::BitStream& bitStream)
		{
			size_t erased = reinterpret_cast<std::set<const Instance*>*>(reinterpret_cast<char*>(&replicator) + 0x2cb0)->erase(instance.get());

			if (erased)
			{
				if (!instance.get())
				{
					StandardOut::singleton()->print(MESSAGE_ERROR, "Replication: ~NULL >> %s", reinterpret_cast<const SystemAddress*>(reinterpret_cast<const char*>(&replicator) + 0x2d54)->ToString(true));
					return;
				}
				
				try 
				{
					writeItemType(bitStream, ItemTypeDelete);
					replicator.serializeId(bitStream, instance.get());

					if (*reinterpret_cast<const bool*>(reinterpret_cast<const char*>(&NetworkSettings::singleton()) + 0x131))
					{
						StandardOut::singleton()->print(
							MESSAGE_INFO,
							"Replication: ~%s:%s >> %s",
							instance->getClassName().c_str(),
							instance->getGuid().readableString(4).c_str(),
							reinterpret_cast<const SystemAddress*>(reinterpret_cast<const char*>(&replicator) + 0x2d54)->ToString(true)
						);
					}
				}
				catch (std::runtime_error& e)
				{
					StandardOut::singleton()->print(
						MESSAGE_ERROR,
						"Replication: ~%s >> %s, %s",
						instance->getClassName().c_str(),
						reinterpret_cast<const SystemAddress*>(reinterpret_cast<const char*>(&replicator) + 0x2d54)->ToString(true),
						e.what()
					);
				}
			}
		}

}}
