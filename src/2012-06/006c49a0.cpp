// from server: 40% by Intel
struct TypeInfo {
    int gap0[4];
    int vtable_ptr;
};

struct VTable {
    int gap0[4];
    int func10;
};

struct String {
    int gap0;
    int length;
    int capacity;
    char* data;
};

struct ContentId {
    int gap0;
    String str;
};

struct TypedPropertyDescriptor {
    int gap0;
    int value;

    int func_006C49A0();
};

extern "C" int __stdcall CompareTypeInfo(int a, int b);
extern "C" int __stdcall func_00523480(int* a, int* b);
extern "C" int __stdcall func_00743fe0(int a, int b);
extern "C" void __stdcall func_00B2263C(int* a);
extern "C" int __stdcall func_0052DF50(int a, int* b);
extern "C" int __stdcall func_006C1440();
extern "C" void __stdcall func_006C2B20(int a);
extern "C" int __stdcall func_00972D70(int a, int b, int* c);
extern "C" void __stdcall func_00983144(int a, int* b);

int TypedPropertyDescriptor::func_006C49A0()
{
    int v_ebx = *(int*)0x00B229EC;
    int v_esi = (int)this;
    int v_ecx = v_esi + 4;
    int v_esp_4 = v_ecx;
    if (v_ecx) {
        int v_eax = *(int*)v_ecx;
        if (v_eax) {
            int v_ecx_1 = *(int*)v_eax;
            if (v_ecx_1 == 0x00D63DDC) {
                if (v_eax) {
                    v_eax = *(int*)v_eax;
                } else {
                    v_eax = 0x00D60AC8;
                }
                int result = CompareTypeInfo(v_eax, 0x00D63DDC);
                if (!result) {
                    goto LABEL_006C4A02;
                }
            }
        } else {
            int v_eax_1 = 0x00D60AC8;
            int result = CompareTypeInfo(v_eax_1, 0x00D63DDC);
            if (!result) {
                goto LABEL_006C4A02;
            }
        }
        int v_eax_2 = v_ecx + 4;
        if (v_eax_2) {
            goto LABEL_006C4A6F;
        }
    }
LABEL_006C4A02:
    int v_eax_3 = *(int*)v_esi;
    int v_eax_4 = *(int*)(v_eax_3 + 0x10);
    if (v_eax_4 != 0x00D60B50) {
        int result = CompareTypeInfo(v_eax_4, 0x00D60B50);
        if (!result) {
            goto LABEL_006C4A81;
        }
    }
    int v_esp_14 = 0;
    func_00523480(&v_esp_4, &v_esp_14);
    int v_esp_14_1 = v_esp_14;
    func_00743fe0(v_esp_14_1, v_esp_14);
    char v_bl = (char)v_esp_14_1;
    func_00B2263C(&v_esp_14);
    if (!v_bl) {
        goto LABEL_006C4A81;
    }
    int v_esp_C = 0;
    func_0052DF50(v_esp_4, &v_esp_C);
    int v_eax_5 = func_006C1440();
    *(int*)v_esi = v_eax_5;
    func_006C2B20(v_esp_4);
LABEL_006C4A6F:
    return 0;
LABEL_006C4A81:
    int v_eax_6 = func_006C1440();
    int v_eax_7 = *(int*)(v_eax_6 + 0x14);
    int v_eax_8 = v_eax_7 + 4;
    int v_edx = 0x10;
    int v_ecx_2;
    if (*(int*)(v_eax_8 + 0x18) < v_edx) {
        v_ecx_2 = v_eax_8 + 4;
    } else {
        v_ecx_2 = *(int*)(v_eax_8 + 4);
    }
    int v_eax_9 = *(int*)v_esi;
    int v_eax_10 = *(int*)(v_eax_9 + 0x14);
    int v_eax_11 = v_eax_10 + 4;
    int v_eax_12;
    if (*(int*)(v_eax_11 + 0x18) < v_edx) {
        v_eax_12 = v_eax_11 + 4;
    } else {
        v_eax_12 = *(int*)(v_eax_11 + 4);
    }
    int v_esp_38 = 0;
    func_00972D70(v_ecx_2, v_eax_12, &v_esp_38);
    func_00983144(0x00CD806C, &v_esp_38);
    return 0;
}
