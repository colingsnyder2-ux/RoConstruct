// from server: 100% by EspClaude
// from server: 45% by colin
// roc 2007-08 00447790  unit: VCRenderSettings::?$FactoryProduct  size: 215 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00447790

struct PropertyDescriptor {
    int data;
};

class DescribedBase {
public:
    virtual ~DescribedBase();
};

struct BoolProperty {
    virtual void v0();
    virtual void v1();
    virtual void setValue(DescribedBase* instance, const bool& value) const;   // vtable +8
};

struct Vector2int16 {
    short x;
    short y;
    Vector2int16() {}
    Vector2int16(short x_, short y_) : x(x_), y(y_) {}
    bool operator!=(const Vector2int16& o) const { return ((int*)this)[0] != ((int*)&o)[0]; }   // as G3D 6.x Vector2int16::operator!=
};

class Node {
public:
    virtual ~Node();
};

unsigned int __cdecl getVideoMemory();   // 0x472f80

class CRenderSettings : public Node, public DescribedBase {
public:
    void setFlag(bool value);                                 // 0x447650
    void raisePropertyChanged(const PropertyDescriptor& d);   // 0x444710
    void reset();

    static const BoolProperty* prop_flag2;     // 0x8bbd30
    static PropertyDescriptor desc_mode;       // 0x8bbcf8
    static PropertyDescriptor desc_quality;    // 0x8bbc18
    static PropertyDescriptor desc_resolution; // 0x8bbc34
    static PropertyDescriptor desc_mode2;      // 0x8bbcc0
    static int mode;                           // 0x888554
    static int defaultQuality;                 // 0x888558
    static int mode2;                          // 0x897a60

    char pad[0x118 - 8];
    Vector2int16 resolution;   // +0x118
    int quality;             // +0x11c
};

void CRenderSettings::reset()
{
    setFlag(true);
    prop_flag2->setValue(this, true);
    if (mode != 1) {
        mode = 1;
        raisePropertyChanged(desc_mode);
    }
    if (defaultQuality != quality) {
        quality = defaultQuality;
        raisePropertyChanged(desc_quality);
    }
    Vector2int16 r;
    if (getVideoMemory() >= 16000000)
        r = Vector2int16(1024, 768);
    else
        r = Vector2int16(800, 600);
    if (r != resolution) {
        resolution = r;
        raisePropertyChanged(desc_resolution);
    }
    if (mode2 != 1) {
        mode2 = 1;
        raisePropertyChanged(desc_mode2);
    }
}
