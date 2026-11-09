// from server: 36% by atomic.potato
extern "C" {
    int __stdcall sub_5060B0(void*);
    int __stdcall sub_418890(void*);
    int __stdcall sub_418580(void*);
    int __stdcall sub_764BB0(void*, void*, void*, void*);
    int __stdcall sub_761630(void*);
    int __stdcall sub_98B6AC(const char*, const char*);
}

struct VBadgeService_BoundYieldFuncDesc {
    char pad_000[0x13c];
    char field_13c[0x10];
    char field_14c[0x10];
    int method(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);
};

int VBadgeService_BoundYieldFuncDesc::method(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20)
{
    int result;
    int local_24;
    int local_1c;
    int local_10;
    int local_0c;
    int local_08;
    int local_04;

    local_24 = 1;
    if (a1 == 0) {
        sub_5060B0(&local_04);
    } else {
        if (sub_98B6AC((const char*)0x9e7950, (const char*)a1)) {
            sub_418890(field_13c);
            local_10 = 1;
            sub_764BB0(field_14c, &local_08, &local_0c, &local_04);
            sub_761630(&local_04);
            local_10 = 1;
            sub_418580(&local_04);
            sub_5060B0(&local_04);
        } else {
            sub_98B6AC((const char*)0x9e7948, (const char*)a1);
            sub_5060B0(&local_04);
        }
    }

    result = local_1c;
    local_24 = 0;
    if (result != 0) {
        result = *(int*)result;
        if (result != 0) {
            ((void (__stdcall*)(int, void*, void*))result)(2, &local_04, &local_04);
        }
        local_1c = 0;
    }

    result = local_04;
    local_24 = -1;
    if (result != 0) {
        result = *(int*)result;
        if (result != 0) {
            ((void (__stdcall*)(int, void*, void*))result)(2, &local_04, &local_04);
        }
    }

    return result;
}
