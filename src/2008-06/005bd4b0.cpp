// from server: 100% by king_originala
extern unsigned char loopingProperty;

struct SoundChannel {
    unsigned char padding0[0x13c];
    void *handle;
    unsigned char padding1[0x25];
    unsigned char unused : 1;
    unsigned char looping : 1;
    unsigned char remaining : 6;

    void setLooping(bool value);
    void updateLooping();
    void notifyProperty(const void *property);
};

void SoundChannel::setLooping(bool value)
{
    if (looping != value) {
        looping = value;
        updateLooping();
        notifyProperty(&loopingProperty);
    }
}
