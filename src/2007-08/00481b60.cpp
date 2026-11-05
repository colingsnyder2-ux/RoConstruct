// from server: 37% by colin
// roc 2007-08 00481b60  unit: G3D::Win32Window  size: 660 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00481b60

struct Win32Window {
    int field0;
    int field4;
    int field8;
    int fieldC;
    int field10;
    int field14;
    int loadDDS(const void* path);
};

extern "C" {
    int __stdcall sub_50c190(int* self, int a, int b);
    int __stdcall sub_50c020(int* self, int* out, int n);
    int __stdcall sub_50bfe0(int* self, int a, int* out);
    int __stdcall sub_50bee0(int* self);
    int __stdcall sub_5017c0(char* out, const char* fmt, const char* arg);
    int __stdcall sub_630b9e(const char* msg, const char* file);
    int __stdcall sub_62ff32(int n);
    int __stdcall sub_630d4c(void* dst, void* src, int n);
    int __stdcall sub_77e61c(const char* a, const char* b);
    int __stdcall sub_77e6ac(void* a);
}

extern int dword_8b5188;
extern int dword_8bdb24;
extern int dword_8bdb4c;
extern int dword_8bdb64;
extern int dword_8bdb9c;
extern int dword_8bdba8;

int Win32Window::loadDDS(const void* path)
{
    int local_24[0x40];
    int local_8;
    int local_4;
    int local_90;
    int local_8c;
    int local_88;
    int local_7c;
    int local_58;
    int local_5c;
    int local_64;
    int local_68;
    int local_48;
    int local_44;
    int local_3c;
    int local_38;
    int local_34;
    int local_30;
    char buf[0x100];
    int result;

    this->field0 = 0;
    this->field4 = dword_8bdb24;
    this->field8 = 0;
    this->fieldC = 0;
    this->field10 = 0;

    sub_50c190(local_24, 1, (int)path);
    sub_50c020(local_24, &local_8, 4);

    if (sub_77e61c((const char*)&local_8, "DDS ")) {
        const char* p = (const char*)path;
        sub_5017c0(buf, "Loading \"%s\" failed. Not a DDS file.", p);
        sub_630b9e(buf, "Cannot getCArray for a huge file");
    }

    sub_50bfe0(local_24, 0x7c, &local_90);

    {
        int v = local_90 & 0x200;
        v = -v;
        v = v >> 31;
        v = v & 5;
        v = v + 1;
        this->field14 = v;
    }

    if (local_48 & 4) {
        if (local_44 == 0x31545844) {
            this->field4 = dword_8bdb64;
        } else if (local_44 == 0x33545844) {
            this->field4 = dword_8bdb4c;
        } else if (local_44 == 0x35545844) {
            this->field4 = dword_8bdba8;
        } else {
            const char* p = (const char*)path;
            sub_5017c0(buf, "Loading \"%s\" failed. Unsupported DDS FourCC format.", p);
            sub_630b9e(buf, "Cannot getCArray for a huge file");
        }
    } else if (local_48 & 0x40) {
        if (local_3c == 8 && local_38 == 8 && local_34 == 8 && local_30 == 0) {
            this->field4 = dword_8bdb9c;
        } else {
            const char* p = (const char*)path;
            sub_5017c0(buf, "Loading \"%s\" failed. Unsupported RGBA DDS format.", p);
            sub_630b9e(buf, "Cannot getCArray for a huge file");
        }
    } else {
        const char* p = (const char*)path;
        sub_5017c0(buf, "Loading \"%s\" failed. Unknown DDS format.", p);
        sub_630b9e(buf, "Cannot getCArray for a huge file");
    }

    {
        int sz = local_58;
        if (sz > 0) {
            sub_630b9e("SUVW", "Cannot getCArray for a huge file");
        }
        result = sz;
    }

    {
        int a = local_5c;
        int b = local_68;
        int c = local_64;
        int n = a - (result + b);
        int p = sub_62ff32(n);
        this->field0 = p;
        sub_630d4c((void*)p, (void*)(c + 0x80), local_5c - local_68 - local_58);
    }

    if (local_90 & 0x20000) {
        this->field10 = local_7c;
    } else {
        this->field10 = 1;
    }

    this->field8 = local_88;
    this->fieldC = local_8c;

    sub_77e6ac(&local_8);
    sub_50bee0(local_24);

    return 0;
}
