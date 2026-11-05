// from server: 50% by colin
struct StreamBuf {
    int pubsync();
};

struct Compressor {
    char pad[0x8c];
    StreamBuf* buf;
    void reset();
};

void sub_552090();

void Compressor::reset()
{
    buf = 0;
    sub_552090();
    if (buf) {
        buf->pubsync();
    }
}
