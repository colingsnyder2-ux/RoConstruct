#include "util/Sound.h"

#include "reflection/enumconverter.h"
#include "util/Events.h"
#include "util/Math.h"
#include "util/Name.h"
#include "util/StandardOut.h"
#include "util/Velocity.h"
#include "v8datamodel/Camera.h"
#include "v8datamodel/DebugSettings.h"
#include "v8datamodel/GameSettings.h"
#include "v8datamodel/PVInstance.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Stats.h"
#include "v8datamodel/Workspace.h"
#include "v8xml/XmlElement.h"

#include <G3D/System.h>
#include <G3D/format.h>
#include <G3D/g3dmath.h>
#include <algorithm>
// PORT: use period FMOD headers shipped with rbxgs.
#include "../../../../tools/rbxgs/Client/fmod/api/inc/fmod.hpp"
#include "../../../../tools/rbxgs/Client/fmod/api/inc/fmod_errors.h"
#include <stdexcept>


// PORT: retain donor constant and helper required by the selected methods.
static const double gcTime = 5.0;
bool convert(const G3D::Vector3& src, FMOD_VECTOR& dst);
static void releaseSound(const std::pair<RBX::Soundscape::SoundId, boost::shared_ptr<RBX::Soundscape::Sound> >& p)
{
	p.second->release();
}

// PORT: donor helper declaration; any selected caller still requires its provider.
void checkResultNoThrow(FMOD_RESULT result);

namespace RBX { namespace Soundscape {

// PORT: selective unit; remaining functions use the 2008 object.

int SoundChannel::getPlayCount() const
{
	return playCount;
}

bool SoundChannel::isPaused() const
{
	if (fmod_channel == NULL) {
		return true;
	}

	bool paused;
	if (fmod_channel->getPaused(&paused) == FMOD_ERR_INVALID_HANDLE) {
		return true;
	}

	return paused;
}

bool SoundChannel::isPlaying() const
{
	if (fmod_channel == NULL) {
		return false;
	}

	bool playing;
	if (fmod_channel->isPlaying(&playing) == FMOD_ERR_INVALID_HANDLE) {
		return false;
	}

	return playing;
}

SoundId SoundChannel::getSoundId() const
{
	return soundId;
}

float SoundChannel::getVolume() const
{
	return volume;
}

bool SoundChannel::getLooped() const
{
	return looped;
}

void SoundService::updateAmbientReverb()
{
	if (!system) {
		return;
	}

	switch (ambientReverb) {
	case NoReverb: {
		FMOD_REVERB_PROPERTIES p = FMOD_PRESET_OFF;
		checkResultNoThrow(system->setReverbProperties(&p));
		break;
	}
	case GenericReverb: {
		FMOD_REVERB_PROPERTIES p = FMOD_PRESET_GENERIC;
		checkResultNoThrow(system->setReverbProperties(&p));
		break;
	}
	case PaddedCell: {
		FMOD_REVERB_PROPERTIES p = FMOD_PRESET_PADDEDCELL;
		checkResultNoThrow(system->setReverbProperties(&p));
		break;
	}
	case Room: {
		FMOD_REVERB_PROPERTIES p = FMOD_PRESET_PADDEDCELL;
		checkResultNoThrow(system->setReverbProperties(&p));
		break;
	}
	case Bathroom: {
		FMOD_REVERB_PROPERTIES p = FMOD_PRESET_BATHROOM;
		checkResultNoThrow(system->setReverbProperties(&p));
		break;
	}
	case LivingRoom: {
		FMOD_REVERB_PROPERTIES p = FMOD_PRESET_LIVINGROOM;
		checkResultNoThrow(system->setReverbProperties(&p));
		break;
	}
	case StoneRoom: {
		FMOD_REVERB_PROPERTIES p = FMOD_PRESET_STONEROOM;
		checkResultNoThrow(system->setReverbProperties(&p));
		break;
	}
	case Auditorium: {
		FMOD_REVERB_PROPERTIES p = FMOD_PRESET_AUDITORIUM;
		checkResultNoThrow(system->setReverbProperties(&p));
		break;
	}
	case ConcertHall: {
		FMOD_REVERB_PROPERTIES p = FMOD_PRESET_CONCERTHALL;
		checkResultNoThrow(system->setReverbProperties(&p));
		break;
	}
	case Cave: {
		FMOD_REVERB_PROPERTIES p = FMOD_PRESET_CAVE;
		checkResultNoThrow(system->setReverbProperties(&p));
		break;
	}
	case Arena: {
		FMOD_REVERB_PROPERTIES p = FMOD_PRESET_ARENA;
		checkResultNoThrow(system->setReverbProperties(&p));
		break;
	}
	case Hangar: {
		FMOD_REVERB_PROPERTIES p = FMOD_PRESET_HANGAR;
		checkResultNoThrow(system->setReverbProperties(&p));
		break;
	}
	case CarpettedHallway: {
		FMOD_REVERB_PROPERTIES p = FMOD_PRESET_CARPETTEDHALLWAY;
		checkResultNoThrow(system->setReverbProperties(&p));
		break;
	}
	case Hallway: {
		FMOD_REVERB_PROPERTIES p = FMOD_PRESET_HALLWAY;
		checkResultNoThrow(system->setReverbProperties(&p));
		break;
	}
	case StoneCorridor: {
		FMOD_REVERB_PROPERTIES p = FMOD_PRESET_STONECORRIDOR;
		checkResultNoThrow(system->setReverbProperties(&p));
		break;
	}
	case Alley: {
		FMOD_REVERB_PROPERTIES p = FMOD_PRESET_ALLEY;
		checkResultNoThrow(system->setReverbProperties(&p));
		break;
	}
	case Forest: {
		FMOD_REVERB_PROPERTIES p = FMOD_PRESET_FOREST;
		checkResultNoThrow(system->setReverbProperties(&p));
		break;
	}
	case City: {
		FMOD_REVERB_PROPERTIES p = FMOD_PRESET_CITY;
		checkResultNoThrow(system->setReverbProperties(&p));
		break;
	}
	case Mountains: {
		FMOD_REVERB_PROPERTIES p = FMOD_PRESET_MOUNTAINS;
		checkResultNoThrow(system->setReverbProperties(&p));
		break;
	}
	case Quarry: {
		FMOD_REVERB_PROPERTIES p = FMOD_PRESET_QUARRY;
		checkResultNoThrow(system->setReverbProperties(&p));
		break;
	}
	case Plain: {
		FMOD_REVERB_PROPERTIES p = FMOD_PRESET_PLAIN;
		checkResultNoThrow(system->setReverbProperties(&p));
		break;
	}
	case ParkingLot: {
		FMOD_REVERB_PROPERTIES p = FMOD_PRESET_PARKINGLOT;
		checkResultNoThrow(system->setReverbProperties(&p));
		break;
	}
	case SewerPipe: {
		FMOD_REVERB_PROPERTIES p = FMOD_PRESET_SEWERPIPE;
		checkResultNoThrow(system->setReverbProperties(&p));
		break;
	}
	case UnderWater: {
		FMOD_REVERB_PROPERTIES p = FMOD_PRESET_UNDERWATER;
		checkResultNoThrow(system->setReverbProperties(&p));
		break;
	}
	}
}

void SoundService::update3DSettings()
{
	if (system) {
		checkResultNoThrow(system->set3DSettings(dopplerscale, distancefactor, rolloffscale));
	}
}

void SoundService::gcSounds(LoadedSounds& sounds)
{
	LoadedSounds::iterator iter = sounds.begin();
	while (iter != sounds.end()) {
		if (iter->second->refCount == 0 && G3D::uniformRandom() >= 0.7f) {
			iter->second->release();
			iter = sounds.erase(iter);
		}
		else {
			++iter;
		}
	}
}

void Sound::release()
{
	if (fmod_sound) {
		checkResultNoThrow(fmod_sound->release());
		fmod_sound = NULL;
	}
}

void SoundService::closeFmod()
{
	stockSounds.clear();
	removeAllChildren();

	std::for_each(loadedSounds.begin(), loadedSounds.end(), releaseSound);
	std::for_each(loaded3DSounds.begin(), loaded3DSounds.end(), releaseSound);

	loadedSounds.clear();
	loaded3DSounds.clear();

	if (system) {
		checkResultNoThrow(system->release());

		system = NULL;
	}
}

void SoundChannel::releaseChannel()
{
	if (fmod_channel) {
		checkResultNoThrow(fmod_channel->setUserData(NULL));

		fmod_channel = NULL;
	}

	if (sound) {
		sound->refCount--;
		sound.reset();
	}
}

void SoundChannel::updateLooped()
{
	if (fmod_channel) {
		FMOD_MODE mode;
		checkResultNoThrow(fmod_channel->getMode(&mode));
		mode |= looped ? FMOD_LOOP_NORMAL : FMOD_LOOP_OFF;
		mode &= looped ? ~FMOD_LOOP_OFF : ~FMOD_LOOP_NORMAL;
		checkResultNoThrow(fmod_channel->setMode(mode));
		checkResultNoThrow(fmod_channel->setLoopCount(looped ? -1 : 0));
	}
}

void SoundChannel::update3D(FMOD::Channel* channel)
{
	if (is3D && part) {
		FMOD_VECTOR pos;
		if (convert(part->getCoordinateFrame().translation, pos)) {
			FMOD_VECTOR vel;
			if (convert(part->getLinearVelocity(), vel)) {
				checkResultNoThrow(channel->set3DAttributes(&pos, &vel));
			}
		}
	}
}

void SoundService::garbageCollectSounds()
{
	if (!(G3D::System::getTick() < nextGarbageCollectTime)) {
		gcSounds(loadedSounds);
		gcSounds(loaded3DSounds);
		nextGarbageCollectTime = G3D::System::getTick() + gcTime;
	}
}

} } // namespace RBX::Soundscape
