// from server: 30% by atomic.potato
extern "C" __declspec(dllimport) int __stdcall RegOpenKeyExA(void*, const char*, unsigned long, unsigned long, void**);
extern "C" __declspec(dllimport) int __stdcall RegCloseKey(void*);

struct MyString {
    char pad0[4];
    char buf[16];
    unsigned int len;
    unsigned int cap;
};

extern unsigned int npos_val;

int __fastcall sub_7eb340(MyString* s, int, const char* name);

struct RegKey {
    void* hkey;
};

extern RegKey* g_key;

bool __fastcall sub_7eb420(MyString* s, int, const char* sub) {
    void* hkey = 0;
    unsigned int pos = s->len;
    if (pos == npos_val)
        return false;
    const char* data = (s->cap >= 0x10) ? *(const char**)s->buf : s->buf;
    int r = sub_7eb340(s, 0, sub);
    if (r == 0)
        return false;
    if (s->cap >= 0x10)
        data = *(const char**)s->buf;
    void* result = 0;
    if (RegOpenKeyExA(g_key->hkey, data + pos + 1, 0, 0x20019, &result) != 0)
        return false;
    RegCloseKey(result);
    return true;
}
