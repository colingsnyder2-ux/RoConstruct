// from server: 100% by king_originala
struct Vector {
    float x, y, z;
    Vector operator-(const Vector&) const;
    float length() const;
    float distance(class Provider*) const;
};

struct Transform {
    char padding[0x24];
    Vector translation;
};

class Provider {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual const Transform& getTransform();
};

#pragma optimize("", off)
float Vector::distance(Provider* provider) const {
    Vector difference = provider->getTransform().translation - *this;
    return difference.length();
}
#pragma optimize("", on)
