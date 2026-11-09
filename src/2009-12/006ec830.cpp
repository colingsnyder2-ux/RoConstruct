// from server: 80% by atomic.potato
struct GeometryVTable
{
    int pad0[4];
    int (__thiscall *f10)(void *);
    int (__thiscall *f14)(void *);
};

struct Geometry
{
    GeometryVTable *vtable;
};

int GeometryFunction(Geometry *value)
{
    if (value->vtable->f10(value) != 0)
        return 0;

    int result = value->vtable->f14(value);
    if (result == 8 || result == 0)
        return 1;

    return 0;
}
