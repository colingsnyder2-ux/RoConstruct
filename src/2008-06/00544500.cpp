// from server: 100% by king_originala
#pragma optimize("", off)

extern "C" void (__cdecl* _invalid_parameter_noinfo)();

struct T;

struct S
{
    void* container;
    T** position;

    bool __thiscall _Has_container() const;
    bool __thiscall _Same_container(const S&) const;
    int __thiscall f(const S&) const;
};

int S::f(const S& other) const
{
    if (!_Has_container() || !_Same_container(other))
        _invalid_parameter_noinfo();

    do
    {
    } while (0);

    return position - other.position;
}
