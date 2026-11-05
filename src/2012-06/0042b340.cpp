// from server: 75% by Intel
extern "C" {
    extern unsigned char g_flag_00E580B3;
    extern int (__cdecl *g_callback_00E5809C)(int, const char*, const char*);
    extern const char* g_string_00B46D90;
    extern const char* g_string_00B46E04;
    extern const char* g_string_00B46E18;
    void __cdecl sub_00972290(const char*, unsigned char);
}

struct InnerStruct {
    int field_8;
};

struct CRobloxTreeCtrl {
    InnerStruct* field_84;
    void Method(int* outValue);
};

void CRobloxTreeCtrl::Method(int* outValue) {
    if (!g_flag_00E580B3) {
        goto LABEL_88;
    }
    if (this->field_84 != 0) {
        goto LABEL_88;
    }
    if (g_callback_00E5809C) {
        int result = g_callback_00E5809C(0x3D, g_string_00B46E18, g_string_00B46E04);
        if (result) {
            goto LABEL_88;
        }
    }
    unsigned char flag = g_flag_00E580B3;
    sub_00972290(g_string_00B46D90, flag);
LABEL_88:
    InnerStruct* ptr = this->field_84;
    int value = ptr->field_8;
    *outValue = value;
}
