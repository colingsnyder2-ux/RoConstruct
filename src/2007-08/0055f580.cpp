// from server: 55% by colin
struct ClearBackpack {
    char pad[0xf4];
    int field_f4;
    int field_f8;
    int field_fc;
    int find(int);
};

extern "C" void __stdcall _invalid_parameter_noinfo();

int ClearBackpack::find(int arg)
{
    int* begin = &field_f4;
    int* end = &field_fc;
    int* cur = &field_f8;

    if (*begin > *end)
        _invalid_parameter_noinfo();

    int* it = (int*)field_f8;
    if (it > (int*)field_fc)
        _invalid_parameter_noinfo();

    while (it != (int*)field_fc) {
        if (*(int*)(*(int*)it + 0x14c) != arg)
            break;
        it++;
    }

    int* last = (int*)field_fc;
    if ((int*)field_f8 > last)
        _invalid_parameter_noinfo();

    if (it != last) {
        if (it >= (int*)field_fc)
            _invalid_parameter_noinfo();
        return *(int*)it;
    }
    return 0;
}
