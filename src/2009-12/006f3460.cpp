// from server: 49% by atomic.potato
typedef unsigned long DWORD;

extern "C" DWORD __stdcall Function6F2F00(DWORD);

struct SurfaceEnumPropDescriptor
{
    DWORD value;
    DWORD pad04;
    DWORD pad08;
    DWORD pad0c;
    DWORD pad10;
    DWORD pad14;
    DWORD pad18;
    DWORD pad1c;
    DWORD object;
    DWORD Invoke(DWORD);
};

DWORD SurfaceEnumPropDescriptor::Invoke(DWORD a)
{
    DWORD value = Function6F2F00(a);
    DWORD object = this->object;
    DWORD* vtable = *(DWORD**)object;
    DWORD (__thiscall *function)(DWORD, DWORD, DWORD) =
        (DWORD (__thiscall *)(DWORD, DWORD, DWORD))vtable[4];
    return function(object, value, value);
}
