// from server: 24% by colin
// roc 2007-08 004e52d0  unit: WedgeBuilder  size: 533 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004e52d0

extern "C" {
    float* __cdecl sub_501570();
    void __cdecl sub_5b9990(void*, void*);
    int __cdecl sub_4f5360(void*, void*, void*, int);
    void __cdecl sub_4eee30(int, int, int, int);
    void __cdecl sub_4f54e0(int);
    void __cdecl sub_62ff26(void*);
}

extern double g_795b48;

struct WedgeBuilder {
    char pad[8];
    float f8;
    float fc;
    char pad2[0x14];
    float f20;
    float f24;
    float f28;
    float f2c;
    float f30;
    void build(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13);
};

void WedgeBuilder::build(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13)
{
    float v20, v24, v28, v2c, v30, v34, v38, v3c, v40, v44, v48, v4c, v50, v54, v58, v5c, v60, v64, v68, v6c, v70, v74, v78;
    int i, j, k;
    float f1, f2, f3, f4;
    int n1, n2, n3;
    int* arr;
    float* arrf;
    float v10;

    v20 = 0.0f;
    v24 = 0.0f;
    v28 = 0.0f;
    v2c = 0.0f;
    v30 = 0.0f;
    v34 = 0.0f;
    v38 = 0.0f;
    v3c = 0.0f;
    v40 = 0.0f;
    v44 = 0.0f;
    v48 = 0.0f;
    v4c = 0.0f;
    v50 = 0.0f;
    v54 = 0.0f;
    v58 = 0.0f;
    v5c = 0.0f;
    v60 = 0.0f;
    v64 = 0.0f;
    v68 = 0.0f;
    v6c = 0.0f;
    v70 = 0.0f;
    v74 = 0.0f;
    v78 = 0.0f;
    v10 = 0.0f;

    n1 = a1;
    n2 = a2;
    n3 = a3;
    arr = (int*)a4;
    arrf = (float*)a5;

    for (i = 0; i < n1; i++) {
        for (j = 0; j < n2; j++) {
            v20 = arrf[0];
            v24 = arrf[1];
            v28 = 1.0f;

            f1 = v20;
            f2 = v24;
            f3 = v28;

            if (f3 > f1) {
                v4c = f3 - f1;
                v20 = v20 - f3;
            } else {
                v4c = f3 + f1;
                v20 = v20 + f3;
            }

            f4 = v2c;
            if (f4 > f2) {
                v50 = f4 - f2;
            } else {
                v50 = f4 + f2;
            }

            float* pf2 = sub_501570();
            if (this->f2c == pf2[0] && this->f30 == pf2[1]) {
                v20 = this->f24;
                v24 = this->f28;
            }

            v70 = v20 * (float)g_795b48;
            v74 = v24 * v2c;

            sub_5b9990(&v70, &v78);
            sub_5b9990(&v4c, &v54);

            int r = sub_4f5360(&v78, &v54, &v70, 1);
            *arr = r;
            arr++;

            v2c = v68 + v4c;
            v30 = v5c + v30;
            v28 = v28;
            v34 = v34;
            v38 = v38;
            v3c = v3c;
            v40 = v40;
            v44 = v44;
            v48 = v48;
            v58 = v58;
            v60 = v60;
            v64 = v64;
            v6c = v6c;
        }

        v28 = v28 + v44;
        arrf += n3;
        v30 = v30 + v10;
        v34 = v34 + v58;
        v38 = v38 + v10;
        v3c = v3c + v10;
        v40 = v40 + v10;
        v48 = v48 + v10;
        v4c = v4c + v10;
        v50 = v50 + v10;
        v54 = v54 + v10;
        v58 = v58 + v10;
        v5c = v5c + v10;
        v60 = v60 + v10;
        v64 = v64 + v10;
        v68 = v68 + v10;
        v6c = v6c + v10;
        v70 = v70 + v10;
        v74 = v74 + v10;
        v78 = v78 + v10;
    }

    if (n2 > 0) {
        int* p1 = arr + n3 + 2;
        int* p2 = arr;
        for (i = 0; i < n2; i++) {
            if (n3 > 0) {
                for (j = 0; j < n3; j++) {
                    sub_4eee30(p2[0], p2[1], p1[-1], p1[0]);
                    p1++;
                    p2++;
                }
            }
            p1 += n3 + 1;
            p2 += n3 + 1;
        }
    }

    for (k = 0; k < n1; k++) {
        sub_4f54e0(arr[k]);
    }

    sub_62ff26(arr);
}
