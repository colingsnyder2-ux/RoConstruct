// from server: 57% by atomic.potato
struct Geometry
{
    unsigned char padding[0x102];
    unsigned char enabled;
    unsigned char padding2[1];
    void (*update)(Geometry *);

    void setEnabled(unsigned char value);
};

void Geometry::setEnabled(unsigned char value)
{
    if (enabled != value)
    {
        enabled = value;
        if (update != 0)
            update(this);
    }
}
