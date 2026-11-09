// from server: 74% by atomic.potato
struct GeometryService
{
    int padding[38];
    int field_98;
    void f(int, int);
};

extern "C" int __stdcall Function_004B0710();

void GeometryService::f(int unused1, int value)
{
    if (value != 0)
        field_98 = Function_004B0710();
}
