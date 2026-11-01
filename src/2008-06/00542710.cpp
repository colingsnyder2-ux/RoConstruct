// from server: 100% by king_originala
#pragma optimize("", off)

extern "C" void (__cdecl * _invalid_parameter_noinfo)();

struct Container {
    unsigned int reserved[4];
    void** end;
};

struct S {
    void* proxy;
    void** current;

    bool _Has_container() const;
    const Container* _Getmycont() const;
    S& f();
};

S& S::f() {
    if (!_Has_container())
        _invalid_parameter_noinfo();
    do {
    } while (0);

    if (!(current < _Getmycont()->end))
        _invalid_parameter_noinfo();
    do {
    } while (0);

    ++current;
    return *this;
}
