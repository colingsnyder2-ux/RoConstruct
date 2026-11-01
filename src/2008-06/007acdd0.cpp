// from server: 100% by king_originala
struct Frame {
    virtual bool unavailable();
    char padding[52];
};

struct Material {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int ready();

    char padding[8];
    Frame* frames;
    int count;

    Frame* select(float position);
};

Frame* Material::select(float position)
{
    if (!ready())
        return 0;

    int upper = count - 1;
    int index = (int)(count * position);

    if (index <= 0)
        index = 0;
    else if (index >= upper)
        index = upper;

    Frame* frame = frames + index;
    return frame->unavailable() ? 0 : frame;
}
