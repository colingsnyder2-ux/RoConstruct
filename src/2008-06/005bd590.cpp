// from server: 100% by king_originala
extern "C" int __stdcall soundStop(void *, int);
extern "C" int __stdcall soundRelease(void *);
extern "C" void __cdecl checkSoundResult(int);

extern char changedProperty;

struct Sound {
    char padding0[0x13c];
    void *handle;
    char padding1[0x28];
    int state;

    void reset();
    void update();
    void notify(const void *);
};

void Sound::reset()
{
    if (handle) {
        checkSoundResult(soundStop(handle, 0));
        checkSoundResult(soundRelease(handle));
        handle = 0;
    }

    update();

    if (state != -1) {
        state = -1;
        notify(&changedProperty);
    }
}
