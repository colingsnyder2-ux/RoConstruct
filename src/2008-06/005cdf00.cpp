// from server: 100% by king_originala
struct Matrix3 {
    float elements[9];
};

struct Frame {
    Matrix3 rotation;
    float x, y, z;

    bool operator!=(const Frame& other) const;
    __forceinline Frame& operator=(const Frame& other);
};

__forceinline Frame& Frame::operator=(const Frame& other)
{
    rotation = other.rotation;
    x = other.x;
    y = other.y;
    z = other.z;
    return *this;
}

struct Property {
    char unused;
};

extern Property frameProperty;

struct ICameraOwner {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void changed();
};

struct Camera {
    char padding[0x1a4];
    Frame frame;

    void notify(const Property& property);
    ICameraOwner* getCameraOwner();
    void setFrame(const Frame& value);
};

void Camera::setFrame(const Frame& value)
{
    if (value != frame) {
        frame = value;
        notify(frameProperty);
        ICameraOwner* owner = getCameraOwner();
        if (owner)
            owner->changed();
    }
}
