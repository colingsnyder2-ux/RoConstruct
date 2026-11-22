// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/openrbx/Client/fmod/api/inc /I{headers}/../../../tools/openrbx/Client/fmod/api/inc
#include "util/Sound.h"
#include <G3D/System.h>
#include <fmod.hpp>
#include <fmod_errors.h>
#include <stdlib.h>
#include <stdexcept>
#include <G3D/format.h>
#include "util/standardout.h"
#include "util/Math.h"

namespace RBX {
namespace Soundscape {

void logFmodResult(FMOD_RESULT result);   // 005b87a0 (non-throwing check)

// 005b6fe0 (placeholder func_005b6fe0, 216 B; INFERRED name, openrbx util/Sound.cpp checkResult): FMOD_ErrorString
// 005b65b0 (the static fmod_errors.h switch; not exact: the binary has the FMOD 4.14.06 table, 0..0x57, while the tree
// header is 4.08.08 with 85 cases), G3D::format 00509b10 with "FMOD %d: %s" 008375f8, StandardOut::singleton
// 00569620 / print(MESSAGE_WARNING = 2) 005693a0, std::runtime_error 00409d50 thrown (_CxxThrowException, 008d1bc8).
void checkFmodResult(FMOD_RESULT result)
{
	if (result != FMOD_OK)
	{
		std::string message = G3D::format("FMOD %d: %s", result, FMOD_ErrorString(result));
		StandardOut::singleton()->print(MESSAGE_WARNING, message.c_str());
		throw std::runtime_error(message);
	}
}

// 005b70c0 (placeholder func_005b70c0, 193 B; INFERRED name, openrbx util/Sound.cpp convert): Math::isDenormal 005dd7b0
// per component, then the Vector3 NaN/Inf/denormal test 005dd8b0, Vector3::clamp(-5000 00837604, 5000 00826de0)
// 005b6ed0 (emitted here as a COMDAT). NEAR MISS, byte-identical: the original calls 005dd8b0 (registry placeholder
// func_005dd8b0, the Vector3 variant with the inlined denormal test, see _unsplit/AppUnit5DC_2008_unsplit.cpp), which
// core util/Math.h does not declare; Math::isNanInfDenormVector3 binds to 005dd860. Blocked on util/Math.h + registry.
bool toFmodVector(const G3D::Vector3& src, FMOD_VECTOR& dst)
{
	G3D::Vector3 filter = src;

	if (Math::isDenormal(filter.x))
		filter.x = 0.0f;
	if (Math::isDenormal(filter.y))
		filter.y = 0.0f;
	if (Math::isDenormal(filter.z))
		filter.z = 0.0f;

	if (Math::isNanInfDenormVector3(filter))
		return false;

	filter = filter.clamp(-5000.0f, 5000.0f);
	dst.x = filter.x;
	dst.y = filter.y;
	dst.z = filter.z;

	return true;
}

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

// 005ba410 (placeholder func_005ba410, 97 B; openrbx util/Sound.cpp Sound::~Sound): release() inlined (fmod_sound +0,
// FMOD::Sound::release import, logFmodResult 005b87a0), then the SoundId member (+0xc) std::string destructor.
Sound::~Sound()
{
	release();
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
