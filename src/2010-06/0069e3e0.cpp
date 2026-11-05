// from server: 59% by atomic.potato
typedef unsigned int DWORD;

struct VTableObject
{
    void (__thiscall *unknown)(VTableObject *, DWORD);
};

struct SurfaceEnumPropDescriptor
{
    int unknown0[8];
    VTableObject *object;
    void *unknown24;
    void *unknown28;
    void *unknown2c;

    void f(DWORD value);
};

extern "C" void sub_5c50d0(void *, DWORD *, DWORD);

void SurfaceEnumPropDescriptor::f(DWORD value)
{
    VTableObject *object = *(VTableObject **)((char *)this + 0x20);
    DWORD result = ((DWORD (__thiscall *)(VTableObject *, DWORD))(*(DWORD **)(object))[3])(object, value);
    sub_5c50d0((char *)this + 0x20, &result, result);
}
