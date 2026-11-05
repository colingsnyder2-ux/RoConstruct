// from server: 100% by colin
struct FMOD_Channel;

extern "C" int __stdcall FMOD_Channel_isPlaying(FMOD_Channel *channel, bool *playing);

struct DropperTool {
    char padding[0x13c];
    FMOD_Channel *channel;
    bool isPlaying();
};

bool DropperTool::isPlaying()
{
    if (!channel)
        return false;

    bool playing;
    if (FMOD_Channel_isPlaying(channel, &playing) == 0x24)
        return false;
    return playing;
}
