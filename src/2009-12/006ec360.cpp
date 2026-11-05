// from server: 93% by atomic.potato
struct Guid
{
    void assign(int, int);
};

extern "C" void __stdcall Guid_assign(Guid *, int, int);

struct Geometry
{
    void setGuid(const Guid *);
};

void Geometry::setGuid(const Guid *value)
{
    Guid_assign((Guid *)((char *)this + 132), ((const int *)value)[0], ((const int *)value)[1]);
    *((unsigned char *)this + 140) = 1;
}
