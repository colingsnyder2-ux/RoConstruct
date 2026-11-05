// from server: 37% by Intel
struct BallCellContact {
    int f();
};

extern "C" int __cdecl sub_9334f0(int, int);

int BallCellContact::f() {
    int v10;
    int v14;
    int v8;
    int v6;
    int v4;
    int v0;

    v14 = v10;
    v6 = v4;
    if (!v6)
        goto LABEL_10;
    v0 = 1 << v8;
    if (v0 & *(unsigned char*)(v6 + 6))
        goto LABEL_10;
    v4 = *(int*)(v14 + 16);
    v10 = *(int*)(v4 + v8 * 4 + 188);
    int v12 = sub_9334f0(v10, v8);
    v4 = v12;
    if (!v4)
        goto LABEL_10;
    if (v6 != v14)
        goto LABEL_14;
    if (!v14)
        goto LABEL_10;
    if (v0 & *(unsigned char*)(v14 + 6))
        goto LABEL_10;
    v8 = *(int*)(v10 + 16);
    v12 = *(int*)(v8 + v6 * 4 + 188);
    v4 = sub_9334f0(v12, v6);
    if (!v4)
        goto LABEL_10;
LABEL_14:
    return v4;
LABEL_10:
    return 0;
}
