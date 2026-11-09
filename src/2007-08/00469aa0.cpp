// from server: 30% by colin
struct LDraw2RobloxColorMap {
    char pad[0x48];
    void* map;
    void addColorMapEntry(const char* name, unsigned int color);
};

extern "C" {
    void* __stdcall sub_469080(void* out, const char* str);
    void* __stdcall sub_469520(void* out, ...);
    void* __stdcall sub_469840(void* self, void* key);
    void* __stdcall sub_445f10(void* self, void* key);
    void __stdcall sub_630a1e();
}

void LDraw2RobloxColorMap::addColorMapEntry(const char* name, unsigned int color)
{
    char buf[0x30];
    void* it1;
    void* it2;
    void* it3;
    void* it4;
    unsigned int c1;
    unsigned int c2;
    unsigned int c3;
    unsigned int c4;
    void* result;

    sub_469080(buf, name);

    it1 = 0;
    it2 = 0;
    it3 = 0;
    it4 = 0;

    sub_469520(&it1, &it2, &it3, &it4, color, 0, 0, 0);

    result = sub_469840(this, buf);
    if (result) {
        void** vtbl = *(void***)result;
        void (*fn)(void*, int) = (void (*)(void*, int))vtbl[0];
        fn(result, 1);
    }

    void* entry = sub_445f10((char*)this + 0x48, buf);
    *(unsigned int*)entry = color;
}
