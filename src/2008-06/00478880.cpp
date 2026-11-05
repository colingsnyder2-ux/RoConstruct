// from server: 88% by king_originala
struct HeightSource {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual int getHeight() = 0;
};

struct HeightData {
    char padding[0x40];
    int height;
};

struct Rect {
    float left;
    float top;
    float right;
    float bottom;
};

extern "C" void __cdecl setViewport(double, double, double, double);

struct S {
    HeightSource* source;
    char padding0[0x6C];
    int revision;
    char padding1[0x34C];
    Rect rect;
    char padding2[0x18];
    HeightData* heightData;

    void setRect(const Rect& value);
};

void S::setRect(const Rect& value)
{
    if (value.bottom == rect.bottom)
        return;

    int height;
    if (heightData == 0)
        height = source->getHeight();
    else
        height = heightData->height;

    setViewport(value.left,
                height - value.bottom,
                value.right - value.left,
                value.bottom - value.top);

    volatile Rect& destination = rect;
    destination.left = value.left;
    destination.top = value.top;
    destination.right = value.right;
    destination.bottom = value.bottom;
    ++revision;
}
