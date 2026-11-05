// from server: 68% by atomic.potato
struct S
{
    float x;
    float y;
    float z;
};

extern "C" S* __cdecl sub_4ed950(S*);

S* __cdecl sub_4ee590(S* unused, S* value)
{
    S* result = sub_4ed950(value);
    value->x = result->x;
    value->y = result->y;
    value->z = result->z;
    return value;
}
