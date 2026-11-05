// from server: 11% by colin
struct CXTPImageManagerIcon {
    int sub_648620();
    int sub_649660(int);
    int sub_64B280(int);
    int sub_648630(int*, int*, int*);
    int sub_6487D0(int, double);
    int sub_6498C0(int*, int*);
    int func();
};

extern "C" int __stdcall sub_4605A0(int*);
extern "C" int __stdcall sub_63062E(int);
extern "C" int __stdcall sub_67F860(int);
extern "C" int __stdcall sub_680770(int*, int, int);
extern "C" int __stdcall sub_680880(int*);
extern "C" int __stdcall sub_7383E2(int*);
extern "C" int __stdcall sub_7383D0(int*, int);
extern "C" int __stdcall sub_738436(int*);
extern "C" int __stdcall sub_62FC6E();

extern "C" int __stdcall GetObjectA(int, int, int*);
extern "C" int __stdcall GetIconInfo(int, int*);
extern "C" int __stdcall CreateIconIndirect(int*);
extern "C" int __stdcall DeleteObject(int);
extern "C" int __stdcall GetPixel(int, int, int);
extern "C" int __stdcall SetPixel(int, int, int, int);
extern "C" int __stdcall CreateCompatibleDC(int);

extern double g_7c6cb0;

int CXTPImageManagerIcon::func() {
    int result;
    int local_4c;
    int local_60;
    int local_74;
    int local_8c[4];
    int local_38;
    int local_28;
    int local_1c;
    int local_14;
    int local_18;
    int v;

    if (sub_648620() != 0) {
        sub_7383E2(&local_38);
        sub_7383D0(&local_38, 0);
        sub_64B280((int)this);
        sub_738436(&local_28);
        sub_648630(&local_18, &local_14, &local_1c);
        if (sub_6498C0(&local_38, &local_28) == 0) {
            sub_62FC6E();
        }
        return 0;
    }

    sub_4605A0(&local_4c);
    if (CreateCompatibleDC(local_4c) == 0) {
        return 0;
    }

    if (sub_67F860(0) == 0) {
        sub_680770(&local_60, 0, sub_63062E(local_4c));
        sub_680770(&local_74, 0, sub_63062E(local_4c));
        GetObjectA(local_4c, 0x18, local_8c);
        for (int i = 0; i < local_8c[1]; i++) {
            for (int j = 0; j < local_8c[2]; j++) {
                int pixel = GetPixel(local_60, j, i);
                if (GetPixel(local_74, j, i) == 0) {
                    SetPixel(local_60, j, i, sub_6487D0(pixel, g_7c6cb0));
                }
            }
        }
        sub_680880(&local_74);
        sub_680880(&local_60);
    }

    sub_649660(CreateIconIndirect(&local_4c));
    DeleteObject(local_4c);
    DeleteObject(local_4c);
    return 0;
}
