// from server: 65% by atomic.potato
struct GeometryService
{
    int f(int, void *);
};

extern "C" int __stdcall CreateGeometry(void *);

int GeometryService::f(int, void *geometry)
{
    if (geometry)
        *(int *)((char *)this + 0x98) = CreateGeometry(geometry);
    return 0;
}
