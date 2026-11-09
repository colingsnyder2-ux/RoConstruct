// from server: 40% by atomic.potato
extern "C" int __cdecl sub_0071fca0(int);

struct SurfaceEnumPropDescriptor
{
    int pad[8];
    int invoke(int);
};

int SurfaceEnumPropDescriptor::invoke(int value)
{
    int result = sub_0071fca0(value);
    int *object = *(int **)((char *)this + 0x20);
    int (__fastcall *function)(int *, int, int) =
        (int (__fastcall *)(int *, int, int))(*(int **)(*object + 0x0c));
    return function(object, result, value);
}
