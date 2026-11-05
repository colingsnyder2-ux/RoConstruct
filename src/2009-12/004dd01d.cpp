// from server: 49% by atomic.potato
extern "C" int __stdcall sub_00B7DA5C(int, int);
extern "C" int __stdcall sub_00B7DA60(int, int);

int __cdecl sub_004DD01D(float* value, int mode)
{
    if (mode)
        return sub_00B7DA5C(1, mode);
    return sub_00B7DA60((int)*value, mode);
}
