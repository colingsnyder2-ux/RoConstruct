// from server: 31% by colin
struct CRobloxApp {
    char pad[0x58];
    void* field58;
    int method_44c760();
    int method_44cbb0();
    int method_44d150(int);
    int method_44d1b0(int, int, int, int);
    int method_44a2c0();
    int method_449bf0(int);
    int method_44bea0(int, int);
    int method_44b740(int, int, int);
    int method_44c1b0();
    int method_44c360();
    int method_44d150();
    int method_6a133a(void*);
    int method_6a1346(void*);
    int method_6a1340(int);

    int method_44da49();
};

extern "C" int __cdecl sub_4495a0();
extern "C" int __cdecl sub_42bc90();
extern "C" int __cdecl sub_5c3f00();
extern "C" int __cdecl sub_4448f0();
extern "C" int __cdecl sub_5c3ca0();
extern "C" int __cdecl sub_41b8a0();
extern "C" int __cdecl sub_41bb70();
extern "C" int __cdecl sub_49ecf0(void*);
extern "C" int __cdecl sub_412d50();
extern "C" int __cdecl sub_41bc40();
extern "C" int __cdecl sub_6a0920(int);
extern "C" int __cdecl sub_449650();
extern "C" int __cdecl sub_449910(int);
extern "C" int __cdecl sub_449fb0(int, int, int);
extern "C" int __cdecl sub_68ff20(void*, void*);
extern "C" int __cdecl sub_68fef0(void*, void*);
extern "C" int __cdecl sub_44c1b0();
extern "C" int __cdecl sub_44c360();
extern "C" int __cdecl sub_44d150(int);
extern "C" int __cdecl sub_44b740(int, int, int);
extern "C" int __cdecl sub_44bea0(int, int);
extern "C" int __cdecl sub_44d1b0(int, int, int, int);
extern "C" int __cdecl sub_44a2c0();
extern "C" int __cdecl sub_449bf0(int);
extern "C" int __cdecl sub_44c760();
extern "C" int __cdecl sub_44cbb0();
extern "C" int __cdecl sub_6a133a(void*);
extern "C" int __cdecl sub_6a1346(void*);
extern "C" int __cdecl sub_6a1340(int);

extern int g_96dd00;
extern int g_96d358;
extern int g_96dbb4;
extern int g_96dd18;
extern int g_96dd1c;
extern int g_97f340;
extern int g_802464;

int CRobloxApp::method_44da49()
{
    int result;
    int local_8c;
    int local_78;
    int local_84;
    int local_80;
    char local_5e;
    char local_5d;
    int local_4c;
    int local_50;
    int local_30;
    int local_24;
    int local_5c;
    int local_14;
    int local_20;
    int local_4;
    int local_c;
    int local_74;
    int local_70;
    int local_6c;
    int local_68;
    int local_64;
    int local_60;
    int local_58;
    int local_54;
    int local_48;
    int local_44;
    int local_40;
    int local_3c;
    int local_38;
    int local_34;
    int local_2c;
    int local_28;
    int local_1c;
    int local_18;
    int local_10;
    int local_8;
    int local_0;
    int esi;
    int eax;
    int ecx;
    int edx;

    sub_4495a0();
    sub_44c1b0();
    sub_6a1346(&local_8c);
    local_4 = 8;
    if (local_78 == 6) {
        sub_44d150(0);
        if (g_96dd00 != 0) {
            eax = ((int (*)())g_96dd00)();
            if (eax < 0) goto label_44daaa;
        }
        sub_44b740(0x97f340, 1, 0);
    label_44daaa:
        local_4 = 2;
        sub_44c360();
        local_4 = 0;
        sub_42bc90();
        return 0;
    }
    if (local_78 == 5) {
        sub_44d150(1);
        sub_44bea0(1, 0);
        goto label_44daaa;
    }
    sub_5c3f00();
    sub_4448f0();
    if ((g_96dd1c & 1) == 0) {
        g_96dd1c |= 1;
        local_4 = 9;
        sub_5c3ca0();
        local_4 = 8;
    }
    sub_41b8a0();
    sub_41bb70();
    eax = ((int (*)(void*))g_802464)((char*)this + 0xf0);
    sub_49ecf0((void*)eax);
    sub_6a1340(0);
    sub_44c760();
    sub_44cbb0();
    eax = sub_412d50();
    ecx = g_96d358;
    if (ecx == 0) {
        ecx = *(int*)(eax + 0x130);
        g_96d358 = ecx;
    }
    if (ecx == 5) {
        local_5d = 1;
    }
    sub_41bc40();
    if (local_84 != 0 || local_80 != 0) {
        goto label_44dd5a;
    }
    if (local_5e != 0) {
        eax = sub_6a0920(0x24);
        local_20 = eax;
        local_4 = 0xb;
        if (eax != 0) {
            eax = sub_449650();
        } else {
            eax = 0;
        }
        field58 = (void*)eax;
        local_4 = 8;
        sub_6a133a(&local_8c);
        esi = eax;
        local_4 = 2;
        sub_44c360();
        local_4 = 0;
        sub_42bc90();
        return esi;
    }
    eax = sub_6a0920(0x30);
    local_20 = eax;
    local_4 = 0xc;
    if (eax != 0) {
        eax = sub_449910(local_5d);
    } else {
        eax = 0;
    }
    local_4 = 8;
    field58 = (void*)eax;
    if (sub_449bf0(0) == 0) {
        goto label_44daaa;
    }
    if (sub_449fb0(0x97f340, 4, 1) < 0) {
        goto label_44daaa;
    }
    if (local_78 != 0) {
        goto label_44dcfb;
    }
    ecx = local_4c - local_50;
    eax = (int)((unsigned long long)(long long)ecx * 0x92492493ULL >> 32);
    edx = eax + ecx;
    edx >>= 4;
    eax = edx;
    eax >>= 31;
    eax += edx;
    if (eax != 0) {
        sub_6a133a(&local_8c);
        sub_68ff20(&local_5c, &local_30);
        esi = eax;
        sub_68fef0(&local_5c, &local_24);
        ecx = *(int*)(esi + 4);
        edx = *(int*)esi;
        eax = *(int*)(eax + 4);
        sub_44d1b0(*(int*)eax, eax, edx, ecx);
        goto label_44dbd3;
    }
    if (local_5d == 0) {
        sub_44a2c0();
    }
    local_4 = 2;
    sub_44c360();
    local_4 = 0;
    sub_42bc90();
    return 1;
label_44dcfb:
    if (local_78 != 1) {
        goto label_44dbce;
    }
    sub_6a133a(&local_8c);
    if (eax == 0) {
        goto label_44dd53;
    }
    sub_68ff20(&local_5c, &local_30);
    esi = eax;
    sub_68fef0(&local_5c, &local_24);
    ecx = *(int*)(esi + 4);
    edx = *(int*)esi;
    eax = *(int*)(eax + 4);
    if (sub_44d1b0(*(int*)eax, eax, edx, ecx) != 0) {
        esi = 1;
        goto label_44dbd5;
    }
label_44dd53:
    esi = 0;
    goto label_44dbd5;
label_44dd5a:
    eax = sub_6a0920(0x30);
    local_20 = eax;
    local_4 = 0xa;
    if (eax != 0) {
        eax = sub_449910(local_5d);
    } else {
        eax = 0;
    }
    field58 = (void*)eax;
    if (sub_449fb0(0x97f340, 4, 1) >= 0) {
        goto label_44dcd4;
    }
    goto label_44dab4;
label_44dbd3:
    esi = eax;
label_44dbd5:
    local_4 = 2;
    sub_44c360();
    local_4 = 0;
    sub_42bc90();
    return esi;
label_44dbce:
    sub_6a133a(&local_8c);
    esi = eax;
    goto label_44dbd5;
label_44dcd4:
    local_4 = 2;
    sub_44c360();
    local_4 = 0;
    sub_42bc90();
    return 1;
label_44dab4:
    local_4 = 2;
    sub_44c360();
    local_4 = 0;
    sub_42bc90();
    return 0;
}
