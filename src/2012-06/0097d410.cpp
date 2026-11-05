// from server: 29% by Intel
struct zlib_error {
    int* ptr;
    int field_4;
    int field_8;
    int field_C;
    int field_10;

    int __stdcall func(int* a1, int* a2, int* a3, int* a4);
};

int __stdcall zlib_error::func(int* a1, int* a2, int* a3, int* a4) {
    int* v1 = this->ptr;
    *v1 = *a1;
    v1[1] = a2[0] - a1[0];
    v1[3] = *a3;
    v1[4] = a4[0] - a3[0];
    return 0;
}
