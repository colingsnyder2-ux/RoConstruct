// from server: 63% by atomic.potato
struct CRenderSettingsW4ResolutionPresetEnumDesc {
    char pad0[0x68];
    int* begin;
    int* end;
    int get(int index);
};

extern "C" int* __stdcall sub_453E40(int* p);

int CRenderSettingsW4ResolutionPresetEnumDesc::get(int index) {
    int* p = sub_453E40(&index + 1);
    int v = *p;
    if (v < 0)
        return 0;
    int count = (int)((end - begin) >> 2);
    if ((unsigned int)v >= (unsigned int)count)
        return 0;
    return begin[v];
}
