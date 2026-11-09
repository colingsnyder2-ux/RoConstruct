// from server: 35% by Intel
struct VInsertService_FactoryProduct {
    int vfptr;
    char pad[28];
    int field_1C;

    int __stdcall func_007FA740(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18);
};

extern "C" int __stdcall sub_7092A0();
extern "C" int __stdcall sub_6C1280();
extern "C" int __stdcall sub_67F2E0(int, int, int);
extern "C" int __stdcall sub_709480(int, int);

int __stdcall VInsertService_FactoryProduct::func_007FA740(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18)
{
    int v17 = 0;
    int v18 = sub_7092A0();
    this->field_1C = v18;
    int v19 = sub_6C1280();
    int v20;
    sub_67F2E0(v19, (int)&v20, (int)&v17);
    sub_709480(v20, this->field_1C);
    if (v17) {
        int (__stdcall *v21)(int) = *(int (__stdcall **)(int))(v17 + 4);
        v21((int)&a1);
    }
    return 0;
}
