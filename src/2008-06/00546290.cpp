// from server: 100% by colin
extern "C" void (__cdecl * _invalid_parameter_noinfo)();

struct Element {
    float v[10];
};

struct S {
    char padding[12];
    Element* first;

    unsigned int size() const;
    Element& at(unsigned int index);
};

#pragma optimize("", off)
Element& S::at(unsigned int index)
{
    if (index >= size())
        _invalid_parameter_noinfo();

    do {
    } while (false);

    return first[index];
}
