// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct S {
    float x, y, z, w;
};

S __cdecl copy(const S* source)
{
    S result;
    result.x = source->x;
    result.y = source->y;
    result.z = source->z;
    result.w = source->w;
    return result;
}