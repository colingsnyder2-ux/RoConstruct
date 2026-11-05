// from server: 100% by atomic.potato
struct S
{
    float first;
    float second;
    S& __cdecl f(S*);
};

extern "C" S* __cdecl GetSlot(S*);

S& S::f(S* value)
{
    S* result = GetSlot(value);
    first = result->first;
    second = result->second;
    return *this;
}
