// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/openrbx/Client/fmod/api/inc /I{headers}/../../../tools/openrbx/Client/fmod/api/inc
#include "util/Sound.h"
#include <G3D/System.h>
#include <fmod.hpp>
#include <stdlib.h>

namespace RBX {
namespace Soundscape {

void logFmodResult(FMOD_RESULT result);   // 005b87a0 (non-throwing check)
void checkFmodResult(FMOD_RESULT result); // 005b6fe0 (throwing check)

void SoundService::update3DSettings()
{
	if (system)
		logFmodResult(system->set3DSettings(dopplerscale, distancefactor, rolloffscale));
}

void SoundService::on3DSettingChanged(const Reflection::PropertyDescriptor&)
{
	update3DSettings();
}

// INFERRED: 005ba2e0 expands Sound::release inline (same TU as Sound.cpp): release the FMOD sound, log, null it.
inline void Sound::release()
{
	if (fmod_sound)
	{
		logFmodResult(fmod_sound->release());
		fmod_sound = NULL;
	}
}

static void releaseSound(const std::pair<const SoundId, boost::shared_ptr<Sound> >& p)
{
	p.second->release();
}

void SoundService::closeFmod()
{
	stockSounds.clear();
	removeAllChildren();
	std::for_each(loadedSounds.begin(), loadedSounds.end(), releaseSound);
	std::for_each(loaded3DSounds.begin(), loaded3DSounds.end(), releaseSound);
	loadedSounds.clear();
	loaded3DSounds.clear();
	if (system)
	{
		logFmodResult(system->release());
		system = NULL;
	}
}

void SoundService::loadStockSounds(SoundType soundType, std::string file)
{
	boost::shared_ptr<SoundChannel> sound = Creatable<Instance>::create<SoundChannel>();
	sound->setName(Reflection::EnumDesc<SoundType>::singleton().convertToString(soundType));
	sound->setSoundId(SoundId::fromAssets(file));
	sound->setParent(this);
	stockSounds[soundType] = sound;
}

void SoundService::gcSounds(std::map<SoundId, boost::shared_ptr<Sound> >& sounds)
{
	for (std::map<SoundId, boost::shared_ptr<Sound> >::iterator it = sounds.begin(); it != sounds.end();)
	{
		if (it->second->refCount == 0 && rand() * (1.0f / RAND_MAX) >= 0.7f)
		{
			it->second->release();
			it = sounds.erase(it);
		}
		else
		{
			++it;
		}
	}
}

boost::shared_ptr<Sound> SoundService::loadSound(SoundId id, bool is3D)
{
	std::map<SoundId, boost::shared_ptr<Sound> >& sounds = is3D ? loaded3DSounds : loadedSounds;
	std::map<SoundId, boost::shared_ptr<Sound> >::iterator it = sounds.find(id);
	if (it != sounds.end())
		return it->second;
	boost::shared_ptr<Sound> sound(new Sound(system, id, is3D));
	sounds[id] = sound;
	return sound;
}

}
}
