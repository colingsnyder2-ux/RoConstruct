// from server: 34% by Intel
struct VGuiObject {
    int field_8;
    int field_C;
    char field_10[8];
    int field_18;

    int sub_7F4020();
};

int __stdcall sub_428540(int);
int __stdcall sub_7F34F0(int);
int __stdcall sub_8D6F00(int, int, int, int, int);
int __stdcall sub_973130(int, int);

int VGuiObject::sub_7F4020() {
    int v4;
    int v5;
    int v6;

    if (field_8)
        v4 = field_8 + 28;
    else
        v4 = 0;

    int v7 = sub_8D6F00(v4, field_C, (int)&v5, (int)&v6, 0x7EB260);
    int v8 = sub_7F34F0(v7);
    sub_973130(field_18, v8);

    if (v5) {
        int v9 = v5 + 5;
        sub_428540(v9);
    }

    return 0;
}
