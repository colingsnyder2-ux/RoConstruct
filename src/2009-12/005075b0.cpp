// from server: 71% by atomic.potato
struct S
{
    float x;
    float y;
    float z;
};

extern "C" S* __cdecl sub_00507430(S*);

S* __cdecl sub_005075B0(S* result)
{
    S* source = sub_00507430(result);
    result->x = source->x;
    result->y = source->y;
    result->z = source->z;
    return result;
}
