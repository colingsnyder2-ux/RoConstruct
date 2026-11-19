// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/openrbx/Client/fmod/api/inc
// SoundServiceStatsItem::SoundServiceStatsItem 005bcc40 (util/Sound.h declaration; service +0x158,
// currentalloced +0x15c, maxalloced +0x160, numSounds +0x164 and numUnusedSounds +0x168 are bound by the
// child items "Current" 00837fc8, "Max" 00837fc4, "# Sounds" 00837fb8, "# Unused" 00837fac; name "Sound" 00818748).
#include "util/Sound.h"
#include "v8datamodel/Stats.h"

SoundServiceStatsItem::SoundServiceStatsItem(const RBX::Soundscape::SoundService* service)
	: service(service)
	, currentalloced(0)
	, maxalloced(0)
{
	setName("Sound");
	createBoundMemChildItem("Current", currentalloced);
	createBoundMemChildItem("Max", maxalloced);
	createBoundChildItem("# Sounds", numSounds);
	createBoundChildItem("# Unused", numUnusedSounds);
}
