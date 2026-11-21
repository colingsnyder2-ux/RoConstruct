// native-flags: /Od /Oy- /GF /GS- /EHsc /MD /D_MBCS
// 2008-06 checked vector element access (0054c120): _Pos >= size() calls _invalid_parameter_noinfo through the
// MSVCR90 import pointer. Element is 12 bytes (three floats), the vector's _Myfirst sits at +0xc.
// INFERRED: owner type unknown; analog from server donor 0054c120 (S with 12 byte header then first pointer).
extern "C" void (__cdecl * _invalid_parameter_noinfo)();

struct Element {
    float x, y, z;
};

struct ElementVector {
    char header[12]; // INFERRED: _Myfirst at +0xc per assembly
    Element* _Myfirst;

    unsigned int size() const;
    Element& sub_0054c120(unsigned int _Pos);
};

Element& ElementVector::sub_0054c120(unsigned int _Pos)
{
    if (_Pos >= size())
        _invalid_parameter_noinfo();

    do {
    } while (false);

    return _Myfirst[_Pos];
}
