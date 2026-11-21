// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/openrbx/Client/fmod/api/inc
// countSounds 005b83d0 of the SoundService object (flags copied from SoundServiceStatsItemCtor.cpp). Identity: registry
// ?countSounds@@YAXABV?$map@VSoundId@Soundscape@RBX@@V?$shared_ptr@VSound@Soundscape@RBX@@@boost@@...@std@@AAI1@Z (global
// namespace, cdecl), called twice by SoundServiceStatsItem::update 005bcd80 (ViewRenderLeftovers.cpp declares it).
// Body from the bytes (iterator declared in the for statement: declaring it before the loop loads begin() into
// another register): a checked const_iterator walk (end() re-read each pass, _Tree const_iterator ++ 00409f60),
// ++numSounds per entry and ++numUnusedSounds when the Sound's refCount (+0x8, util/Sound.h) is 0.
#include "util/Sound.h"
#include <map>
#include <boost/shared_ptr.hpp>

// 005b83d0
void countSounds(const std::map<RBX::Soundscape::SoundId, boost::shared_ptr<RBX::Soundscape::Sound> >& sounds,
                 size_t& numSounds, size_t& numUnusedSounds)
{
	for (std::map<RBX::Soundscape::SoundId, boost::shared_ptr<RBX::Soundscape::Sound> >::const_iterator iter = sounds.begin();
	     iter != sounds.end(); ++iter)
	{
		++numSounds;
		if (iter->second->refCount == 0)
			++numUnusedSounds;
	}
}
