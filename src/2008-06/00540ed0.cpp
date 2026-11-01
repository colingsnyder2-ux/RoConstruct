// from server: 100% by king_originala
extern "C" void (__cdecl *_invalid_parameter_noinfo)();

struct S {
    void* container;
    void* current;

    bool _Has_container() const;
    bool _Same_container(const S& other) const;
    bool f(const S& other) const;
};

#pragma optimize("", off)

bool S::f(const S& other) const
{
    if (!(_Has_container() && _Same_container(other)))
        _invalid_parameter_noinfo();

    do {
    } while (0);

    return current == other.current;
}
