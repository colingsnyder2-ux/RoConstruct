// from server: 100% by king_originala
extern "C" void (__cdecl *_invalid_parameter_noinfo)();

struct S {
    unsigned char padding[172];
    void **first;
    void **volatile last;

    void *get(const int &index);
};

void *S::get(const int &index)
{
    int i = index;
    if (i < 0)
        return 0;

    if (static_cast<unsigned int>(i) >=
        static_cast<unsigned int>(last - first))
        return 0;

    if (static_cast<unsigned int>(i) >=
        static_cast<unsigned int>(last - first))
        _invalid_parameter_noinfo();

    return first[i];
}
