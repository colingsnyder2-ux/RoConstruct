// from server: 92% by colin
struct MyXTPCommandBars {
    char pad[0xf4];
    int field_f4;
    char pad2[0xfc - 0xf8];
    int field_fc;
    int func(int);
};

extern "C" int __stdcall sub_66DE80(int, int, int);
extern "C" int __stdcall sub_62FF4A(int);

int MyXTPCommandBars::func(int arg) {
    sub_66DE80((int)&field_f4, 0x78a7b4, 0);
    int v = arg;
    if (v != 0) {
        v = field_fc;
    }
    int r = sub_62FF4A(v);
    return r != 0;
}
