// from server: 100% by king_originala
extern "C" int __stdcall getMode(void *, unsigned int *);
extern "C" int __stdcall setMode(void *, unsigned int);
extern "C" int __stdcall setLoopCount(void *, int);
void __cdecl checkResult(int);

struct SoundChannel {
    unsigned char padding0[0x13c];
    void *handle;
    unsigned char padding1[0x25];
    unsigned char unused : 1;
    unsigned char looping : 1;
    unsigned char remaining : 6;

    void updateLooping();
};

void SoundChannel::updateLooping()
{
    if (handle) {
        unsigned int mode;
        checkResult(getMode(handle, &mode));
        mode |= looping ? 2 : 1;
        mode &= looping ? -2 : -3;
        checkResult(setMode(handle, mode));
        checkResult(setLoopCount(handle, looping ? -1 : 0));
    }
}
