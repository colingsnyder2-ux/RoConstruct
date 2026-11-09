// from server: 44% by atomic.potato
typedef unsigned long DWORD;

struct SurfaceEnumPropDescriptor;

extern "C" DWORD sub_823db0(DWORD value);

struct SurfaceEnumPropDescriptor
{
    DWORD pad[11];
    void* object;
    DWORD f();
};

DWORD SurfaceEnumPropDescriptor::f()
{
    DWORD value = sub_823db0(*((DWORD*)((char*)this + 0x2c)));
    DWORD* table = *(DWORD**)((char*)this + 0x2c);
    DWORD (__fastcall *func)(void*, DWORD) =
        (DWORD (__fastcall *)(void*, DWORD))(*(DWORD**)((char*)table)[0] + 0x0c);
    return func(table, value);
}
