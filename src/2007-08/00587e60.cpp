// from server: 100% by colin
struct SoundChannel {
    char pad[0xec];
    int fmod_channel;
    char pad2[0x100 - 0xf0];
    float f100;
    float f104;
    float f108;
    void method(int);
};

extern "C" void __stdcall sub_62fbde(int, float, float, float);

void SoundChannel::method(int arg) {
    int ch = fmod_channel;
    if (ch != 0) {
        sub_62fbde(ch, f100, f104, f108);
    }
}
