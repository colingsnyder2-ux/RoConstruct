// from server: 100% by king_originala
struct Frame
{
    virtual bool unavailable() = 0;
    char data[40];
};

struct Material
{
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual int ready() = 0;

    int padding[2];
    Frame* frames;
    int count;

    Frame* select(float position);
};

Frame* Material::select(float position)
{
    if (!ready())
        return 0;

    int last = count - 1;
    int index = (int)(count * position);
    if (index <= 0)
        index = 0;
    else if (index >= last)
        index = last;

    Frame* frame = frames + index;
    return frame->unavailable() ? 0 : frame;
}
