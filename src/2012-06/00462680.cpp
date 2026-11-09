// from server: 99% by Intel
extern "C" void __cdecl sub_44D230(int, int);

struct RBXImage {
    int field_0;
    void func(int a1, int a2);
};

void RBXImage::func(int a1, int a2) {
    int v3 = a1;
    int v4 = a2;

    if (v3) {
        if (!*reinterpret_cast<char*>(v3 + 0x80)) {
            sub_44D230(field_0, 0xB57764);
        }
        if (!*reinterpret_cast<char*>(v3 + 0x81)) {
            if (!*reinterpret_cast<char*>(v4 + 4)) {
                return;
            }
        }
    } else {
        if (!*reinterpret_cast<char*>(v4 + 4)) {
            return;
        }
    }

    sub_44D230(field_0, 0xB57754);

    if (v3) {
        if (!*reinterpret_cast<char*>(v3 + 0x82)) {
            if (!*reinterpret_cast<char*>(v4 + 5)) {
                return;
            }
        }
    } else {
        if (!*reinterpret_cast<char*>(v4 + 5)) {
            return;
        }
    }

    sub_44D230(field_0, 0xB57744);
}
