#include "../native-classes/ProfiledRakPeer.cpp"

typedef char ProfiledRakPeerSize[sizeof(ProfiledRakPeer) == 0x910 ? 1 : -1];
ProfiledRakPeer* makeProfiledRakPeer(RBX::Profiling::CodeProfiler* profiler)
{
    return new ProfiledRakPeer(profiler);
}
