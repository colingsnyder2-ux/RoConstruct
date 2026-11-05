// from server: 46% by Intel
struct Value;

extern "C" void __stdcall sub_0067f480();
extern "C" void __stdcall sub_00767a90();
extern "C" void __cdecl sub_004015a0(int, int);
extern "C" Value& __cdecl sub_004019d0();
extern "C" Value& __cdecl sub_00457100(Value&);
extern "C" int* __cdecl sub_00466420(Value&);
extern "C" void __cdecl sub_00972290(int, int);

struct FactoryProduct {
    void* vftable;
    char pad_4[8];
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    FactoryProduct* run();
};

FactoryProduct* FactoryProduct::run() {
    vftable = (void*)0xBB09D0;

    if (*(int*)0xBC0BA4 == 0) {
        sub_0067f480();
    } else {
        sub_004015a0(0x768120, 0xE37A68);
        sub_00767a90();
    }

    Value& v1 = sub_004019d0();
    int creatorId = *(int*)((char*)&v1 + 4);
    int local_edi = (int)&v1;

    Value& v2 = sub_004019d0();
    int* mapEntry = sub_00466420(v2);

    if (*mapEntry != creatorId) {
        int logger = *(int*)0xE5809C;
        if (logger) {
            if (((int(__cdecl*)(int, int, int))logger)(0xD7, 0xB42FA8, 0xB43284)) {
                goto LABEL_240;
            }
        }
        int flag = *(unsigned char*)0xE580B3;
        sub_00972290(flag, 0xB431E8);
    }

LABEL_240:
    if (*(unsigned char*)0xE580B3) {
        if (*(int*)0xE379C0 == 0x29A) {
            int logger = *(int*)0xE5809C;
            if (logger) {
                if (((int(__cdecl*)(int, int, int))logger)(0xD8, 0xB42FA8, 0xB431D0)) {
                    goto LABEL_28B;
                }
            }
            int flag = *(unsigned char*)0xE580B3;
            sub_00972290(flag, 0xB43160);
        }
    }

LABEL_28B:
    Value& v3 = sub_004019d0();
    Value& v4 = sub_00457100(v3);
    *(int*)&v4 = (int)this;

    *(unsigned char*)0xE580B3 = 0;
    *(int*)0xE379C0 = 0x29A;

    if (*(unsigned char*)0xE580B3) {
        Value& v5 = sub_004019d0();
        int creatorId2 = *(int*)((char*)&v5 + 4);
        Value& v6 = sub_004019d0();
        int* mapEntry2 = sub_00466420(v6);

        if (*mapEntry2 == creatorId2) {
            int logger = *(int*)0xE5809C;
            if (logger) {
                if (((int(__cdecl*)(int, int, int))logger)(0xDD, 0xB42FA8, 0xB4311C)) {
                    goto LABEL_315;
                }
            }
            int flag = *(unsigned char*)0xE580B3;
            sub_00972290(flag, 0xB43080);
        }

LABEL_315:
        if (*(unsigned char*)0xE580B3) {
            if (*(int*)0xE379C0 != 0x29A) {
                int logger = *(int*)0xE5809C;
                if (logger) {
                    if (((int(__cdecl*)(int, int, int))logger)(0xDE, 0xB42FA8, 0xB42F90)) {
                        goto LABEL_360;
                    }
                }
                int flag = *(unsigned char*)0xE580B3;
                sub_00972290(flag, 0xB43010);
            }
        }
    }

LABEL_360:
    return this;
}
