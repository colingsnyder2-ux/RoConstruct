// from server: 100% by king_originala
#pragma optimize("", off)

extern "C" void (__cdecl *_invalid_parameter_noinfo)();

struct Element {
    char data[40];
};

struct Container {
    char padding[16];
    Element* end;
};

struct S {
    void* container;
    Element* current;

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
