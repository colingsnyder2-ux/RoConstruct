// from server: 100% by king_originala
struct Frame {
    float data[12];
    bool changed() const;
};

struct Ray {
    char data[0x44];
    Frame difference(const Frame& other) const;
    void setFrame(const Frame& other);
};

struct Observer {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void update() = 0;
};

extern const char property;
extern bool __cdecl validateFrame(const Frame& frame);

struct Camera {
    char prefix[0x130];
    Ray ray;
    Frame frame;
    char padding[0x40];
    bool dirty;

    void notify(const char* property);
    Observer* g();
    void update();
};

void Camera::update()
{
    if (ray.difference(frame).changed()) {
        dirty = true;
        if (validateFrame(frame))
            ray.setFrame(frame);
        notify(&property);
        Observer* observer = g();
        if (observer)
            observer->update();
    }
}
