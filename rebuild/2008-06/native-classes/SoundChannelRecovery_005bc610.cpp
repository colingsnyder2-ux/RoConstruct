// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "SoundChannel/SoundChannel.h"
#include "v8tree/Service.h"
#include "util/ContentProvider.h"

// 005bc610: member, callgraph-adjacency: neighbours=1
// Called from onAncestorChanged at 005bd983: when sound is enabled it asks the context's ContentProvider for soundId.
// INFERRED: name from assembly analysis of FUN_005bc610
void SoundChannel::preloadSound() // 005bc610
{
    // Check global SoundService::soundDisabled flag (00976fc9)
    if (*(BYTE*)0x976fc9)
        return;

    // Check member soundDisabled bit (bit 2 at offset 0x165)
    if (soundDisabled)
        return;

    // Get ContentProvider from CRobloxModule (0044bee0 returns ContentProvider*)
    ContentProvider* globalProvider = reinterpret_cast<ContentProvider* ()>(0x44bee0)();
    if (!globalProvider)
        return;

    // Check requestQueue at offset 0x138 (std::list<ContentRequest>)
    // INFERRED: checking if request queue is non-empty
    if (*(BYTE*)((BYTE*)globalProvider + 0x138) == 0)
        return;

    // Get ContentProvider via ServiceProvider::create<ContentProvider>(this)
    // 00465210 = ServiceProvider::create<ContentProvider>(const Instance*)
    ContentProvider* provider = reinterpret_cast<ContentProvider(*)(const Instance*)>(0x465210)(this);
    if (!provider)
        return;

    // Call ContentProvider::sub_00562730 to resolve soundId
    // INFERRED: signature from NativeContentProvider.h and assembly analysis
    // Returns boost::shared_ptr<const std::string> but called with output buffer
    std::string resolvedId;
    boost::shared_ptr<const std::string> result = provider->sub_00562730(soundId);

    // The assembly shows a boost::shared_ptr<Instance> cleanup on stack at 005bc656
    // INFERRED: ServiceProvider::create returns a shared_ptr that we don't store
    boost::shared_ptr<Instance> tempProviderHolder; // placeholder for cleanup
}

// 005bd360: 194 bytes, member, descriptor-ptm
// Constructs PropDescriptor for soundId and handles sound initialization.
// Called during SoundChannel construction and ancestor changes.
// INFERRED: from assembly at 005bd360, sets up the soundId property descriptor infrastructure
void SoundChannel::setSoundId(SoundId value) // 005bd360
{
    // INFERRED: construct sound ID string representation for descriptor
    // The assembly at 005bd360 constructs a basic_string<char> and stores it
    // as the PropDescriptor for the soundId property

    // Set the soundId member
    soundId = value;

    // INFERRED: update PropDescriptor infrastructure
    // The assembly stores the string descriptor at offset 0x1c from the
    // this+0x140 position (i.e., offset 0x15c from this), which corresponds
    // to the property descriptor for soundId

    // Call preloadSound to initialize the sound if enabled
    preloadSound();

    // If sound exists, manage reference count (INFERRED from assembly:
    // decrements ref count and calls stats when sound is present)
    if (sound)
    {
        // INFERRED: decrement reference count on sound shared_ptr
        sound->refCount--;

        // INFERRED: call stats tracking for sound ref count change
        // Assembly at 005bd3ec calls 0x456e80 which is a stats recording function
        // when the sound object's ref count changes
        if (sound->refCount == 0)
        {
            sound.reset();
        }
    }

    // Clear FMOD channel if previously set (INFERRED: assembly at
    // 005bd3cf moves 0 into [esi+0x13c], clearing fmod_channel)
    fmod_channel = 0;

    // INFERRED: register the soundId property with reflection metadata
    // The assembly calls 0x40db00 (Reflection::Metadata::VMember::FactoryProduct)
    // to register the soundId property descriptor at 005bd3f1/005bd3f8
}
}