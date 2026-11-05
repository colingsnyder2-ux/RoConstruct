// from server: 31% by atomic.potato
struct SurfaceDescriptor
{
    float x;
    float y;
    float z;

    void f(SurfaceDescriptor *out) const;
};

void SurfaceDescriptor::f(SurfaceDescriptor *out) const
{
    out->y = y;
    out->x = x;
    out->z = z;
}
