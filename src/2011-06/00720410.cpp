// from server: 37% by atomic.potato
extern "C" int sub_71FB40(int);

struct SurfaceEnumPropDescriptor
{
    int **field20;
    int f(int value);
};

int SurfaceEnumPropDescriptor::f(int value)
{
    int converted = sub_71FB40(value);
    int *object = *field20;
    int (__fastcall *callback)(int *, int, int) =
        (int (__fastcall *)(int *, int, int))object[3];
    return callback(object, converted, value);
}
