// from server: 36% by atomic.potato
extern "C" int __cdecl sub_8240f0(void* value);

struct SurfaceEnumPropDescriptor
{
    int Invoke(int value);
    void* field_2c;
};

int SurfaceEnumPropDescriptor::Invoke(int value)
{
    int converted = sub_8240f0((void*)value);
    void** object = (void**)field_2c;
    int (__cdecl *function)(void*, int) =
        (int (__cdecl *)(void*, int))(*(void***)object)[3];
    return function(object, converted);
}
