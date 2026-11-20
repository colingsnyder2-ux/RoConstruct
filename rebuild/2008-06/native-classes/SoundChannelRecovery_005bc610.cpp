// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// SoundChannel::preloadSound 005bc610 and SoundChannel::setSoundId 005bd360 now live in SoundChannel.cpp, the original
// util/Sound.cpp unit: setSoundId expands releaseChannel 005b97f0 inline, which needs the same translation unit.
// The earlier draft here called raw addresses and did not compile into either target; nothing is defined here now.
