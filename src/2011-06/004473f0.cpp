// from server: 68% by atomic.potato
struct S {
    float x;
    float y;
    float z;
    S& __cdecl f(const S& value);
};

S& S::f(const S& value)
{
    x = value.x;
    y = value.y;
    z = value.z;
    return *this;
}
