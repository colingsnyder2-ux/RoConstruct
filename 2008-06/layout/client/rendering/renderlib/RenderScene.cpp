#include "axis-vector-negation/G3D/Vector3.h"
#include "util/Handle.h"
#include "util/Sound.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Camera.h"
#include "v8datamodel/PVInstance.h"
#include "v8datamodel/Stats.h"
#include <G3D/System.h>
#include <fmod.hpp>

namespace RBX
{
	bool InstanceHandle::empty() const
	{
		return !target;
	}
}

void countSounds(const std::map<RBX::Soundscape::SoundId, boost::shared_ptr<RBX::Soundscape::Sound> >& sounds,
                 size_t& numSounds, size_t& numUnusedSounds);

void SoundServiceStatsItem::update()
{
	if (service->system)
	{
		formatValue(service->fmod_version, "fmod %08x", service->fmod_version);

		int current, max;
		if (FMOD::Memory_GetStats(&current, &max) == FMOD_OK)
		{
			currentalloced = current;
			maxalloced = max;
		}

		size_t* unused = &numUnusedSounds;
		size_t* sounds = &numSounds;
		const RBX::Soundscape::SoundService* soundService = service;
		*unused = 0;
		*sounds = 0;
		countSounds(soundService->loadedSounds, *sounds, *unused);
		countSounds(soundService->loaded3DSounds, *sounds, *unused);
	}
	else
	{
		std::string disabled("-disabled-");
		val = 0;
		sValue = disabled;
	}
}

namespace RBX
{
	namespace Soundscape
	{

		void SoundService::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
		{
			Notifier<RunService, Heartbeat>::disconnect(ServiceProvider::find<RunService>(oldProvider), this);

			if (statsItem)
			{
				statsItem->setParent(NULL);
				statsItem.reset();
			}

			if (oldProvider)
				closeFmod();

			Notifier<RunService, Heartbeat>::connect(ServiceProvider::find<RunService>(newProvider), this);

			if (newProvider)
			{
				openFmod();
				loadStockSounds();

				if (Stats::StatsService* stats = newProvider->create<Stats::StatsService>())
				{
					statsItem = Creatable<Instance>::create<SoundServiceStatsItem>(this);
					statsItem->setParent(stats);
				}
			}
		}
	}
}

// INFERRED: the original most likely had these as header-inline members, emitted out of line where render calls
#include "ViewNew/RenderBaseMesh.h"
#include <exception>

namespace RBX
{
	namespace RenderBase
	{
		const G3D::Vector3& Mesh::getVertex(int index) const
		{
			if (index < 0 || index >= visibleGeometry.vertexArray.size())
				throw std::exception("RBX Mesh::getVertex() index out of range");
			return visibleGeometry.vertexArray[index];
		}

		const G3D::Vector3& Mesh::getNormal(int index) const
		{
			if (index < 0 || index >= visibleGeometry.normalArray.size())
				throw std::exception("RBX Mesh::getNormal() index out of range");
			return visibleGeometry.normalArray[index];
		}
	}
}
