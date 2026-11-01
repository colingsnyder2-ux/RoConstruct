// from server: 100% by king_originala
#pragma optimize("", off)

extern "C" void (__cdecl * _imp__invalid_parameter_noinfo)();

struct Container {
    unsigned char padding[16];
    unsigned limit;
};

struct Iterator {
    void *proxy;
    unsigned position;

    bool _Has_container() const;
    const Container *_Getmycont() const;
    unsigned get() const;
};

unsigned Iterator::get() const
{
    if (!_Has_container())
        _imp__invalid_parameter_noinfo();
    do {
    } while (0);

    if (!(position < _Getmycont()->limit))
        _imp__invalid_parameter_noinfo();
    do {
    } while (0);

    return position;
}
