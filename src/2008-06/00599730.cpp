// from server: 100% by king_originala
struct Frame {
    float data[12];
};

struct Device {
    Frame getFrame(int);
};

struct FrameHolder {
    void setFrame(const Frame&);
};

struct S {
    char pad0[0x19c];
    int value;
    char pad1[0x88];
    FrameHolder holder;
    void f(Device*);
};

void S::f(Device* device)
{
    Frame frame = device->getFrame(value);
    holder.setFrame(frame);
}
