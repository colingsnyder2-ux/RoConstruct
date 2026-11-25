// from server: 100% by Xemicl
﻿// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Buffer {
    __declspec(dllimport) int pubsync();
};
struct Stream {
    int padding;
    Buffer buffer;
};
struct Device {
    Stream* stream;
};

inline void close(Device& device, int which)
{
    Stream* stream = device.stream;
    if (which & 2)
        stream->buffer.pubsync();
}

struct external_device_closer {
    ~external_device_closer();
    Device* device_;
    int which_;
    bool dummy_;
    bool& nothrow_;
};

external_device_closer::~external_device_closer()
{
    try {
        close(*device_, which_);
    } catch (...) {
        if (!nothrow_) {
            nothrow_ = true;
            throw;
        }
    }
}
