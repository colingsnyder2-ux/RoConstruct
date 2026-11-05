// from server: 41% by Intel
struct VBrickColor {
    int f();
};

extern "C" int __stdcall sub_7DB310(int, int, int);

int VBrickColor::f() {
    int v1;
    int v2 = *(int*)((char*)&v1 + 12);
    *(int*)&v1 = 0;
    if (!v2)
        goto LABEL_5;
    int v3 = *(int*)((char*)&v1 + 16);
    int v4 = *(int*)((char*)this + 44);
    int v5 = *(int*)((char*)&v1 + 12);
    v2 += -28;
    int v6 = v4 + v2;
    sub_7DB310(v6, v3, v5);
    int result = v5;
    return result;
LABEL_5:
    int v7 = *(int*)((char*)&v1 + 8);
    *(int*)v7 = 0;
    return 0;
}
