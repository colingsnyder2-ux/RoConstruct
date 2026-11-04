// from server: 35% by Intel




struct VServerBoundFuncDesc {
    int func();
};

int VServerBoundFuncDesc::func() {
    return 0;
}

extern "C" int __cdecl sub_972290(int, int, int);
extern "C" int __stdcall sub_982114(int);
extern "C" int __stdcall sub_5C9FE8(int, int, int);
extern "C" int __stdcall sub_6DBE50(int, int, int, int);
extern "C" int __stdcall sub_6D67E0(int, int, int, int, int);
extern "C" int __stdcall sub_71FAD0(int);
extern "C" int __stdcall sub_7398E0(int, int);
extern "C" int __stdcall sub_739930(int, int);
extern "C" int __stdcall sub_417E50(int);
extern "C" int __stdcall sub_495F40(int);
extern "C" int __stdcall sub_535EB0(int);
extern "C" int __stdcall sub_5433C0(int, int);

int __stdcall sub_6E8F20(int ecx, int arg_4) {
    int esi = ecx;
    int ebp = 0;
    int edi;
    int ebx;
    int eax;
    int edx;
    int ecx_local;

    if (*(char*)0xE580B3) {
        if (!*(char*)(esi + 0xB29)) {
            eax = *(int*)0xE5809C;
            if (eax) {
                if (sub_972290(0x5E6, (int)"C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\V8DataModel\\DataModel.cpp", (int)"C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\include\\gui/gui.h")) {
                    goto LABEL_8C;
                }
            }
            eax = *(unsigned char*)0xE580B3;
            sub_972290((int)"Rendering 3D Sorted Adorn Items, %u items", eax, 0);
        }
    } else {
        ebp = 0;
    }
LABEL_8C:
    if (*(char*)(esi + 0xB29)) {
        goto LABEL_1F4;
    }
    edi = arg_4;
    (*(int*)(esi + 0xB20))++;
    if (edi == ebp) {
        if (!*(char*)0xE580B3) {
            goto LABEL_1F4;
        }
        eax = *(int*)0xE5809C;
        if (eax) {
            if (sub_972290(0x5F0, (int)"C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\V8DataModel\\DataModel.cpp", (int)"isInitialized")) {
                goto LABEL_1F4;
            }
        }
        ecx_local = *(unsigned char*)0xE580B3;
        sub_972290((int)"L$8d", ecx_local, 0);
        goto LABEL_1F4;
    }

    int local_1C = ebp;
    int local_20 = ebp;
    int local_24 = ebp;

    eax = *(int*)(esi + 0xAC4);
    edx = *(int*)(eax + 0x90);
    ecx_local = eax + 0x90;
    eax = *(int*)(edx + 0x18);
    eax = ((int (__stdcall*)(int, int))eax)(edi, ecx_local);

    ecx_local = (int)&local_1C;
    eax = sub_71FAD0(ecx_local);

    ecx_local = esi;
    eax = sub_417E50(ecx_local);

    ecx_local = *(int*)(eax + 0x1AC);
    if (ecx_local != ebp) {
        eax = sub_535EB0(ecx_local);
        ebx = eax;
        if (ebx != ebp) {
            ((int (__stdcall*)(int, int))0x7398E0)(edi, ebx);
            eax = *(int*)(esi + 0xAC4);
            edx = *(int*)(eax + 0x150);
            ebp = *(int*)ebx;
            ecx_local = eax + 0x150;
            eax = ((int (__stdcall*)(int))*(int*)(edx + 8))(ecx_local);
            edx = *(int*)(ebp + 0x54);
            ecx_local = (int)&local_1C;
            ((int (__stdcall*)(int, int, int))edx)(eax, ecx_local, ebx);
        }
    } else {
        ecx_local = *(int*)(esi + 0xADC);
        ((int (__stdcall*)(int, int))0x739930)(edi, ecx_local);
        eax = *(int*)(esi + 0xAC4);
        ebp = *(int*)(esi + 0xADC);
        ebx = *(int*)ebp;
        ecx_local = eax + 0x150;
        eax = *(int*)ecx_local;
        edx = *(int*)(eax + 8);
        ebx += 0x54;
        eax = ((int (__stdcall*)(int))edx)(ecx_local);
        edx = *(int*)ebx;
        ecx_local = (int)&local_1C;
        ((int (__stdcall*)(int, int, int))edx)(eax, ecx_local, ebp);
    }

    ecx_local = *(int*)(esi + 0xAB4);
    ((int (__stdcall*)(int, int))0x7398E0)(edi, ecx_local);
    eax = *(int*)(esi + 0xAC4);
    ebx = *(int*)(esi + 0xAB4);
    ebp = *(int*)ebx;
    ecx_local = eax + 0x150;
    eax = *(int*)ecx_local;
    edx = *(int*)(eax + 8);
    ebp += 0x54;
    eax = ((int (__stdcall*)(int))edx)(ecx_local);
    edx = *(int*)ebp;
    ecx_local = (int)&local_1C;
    ((int (__stdcall*)(int, int, int))edx)(eax, ecx_local, ebx);

    eax = *(int*)edi;
    edx = *(int*)(eax + 0x18);
    ecx_local = (int)&local_24;
    ((int (__stdcall*)(int, int))edx)(ecx_local, edi);

    eax = local_20;
    ecx_local = local_1C;
    edx = eax - ecx_local;
    edx >>= 2;
    sub_6DBE50((int)"T$,R", edx, eax, ecx_local);

    if (*(char*)0xE31AA9) {
        ecx_local = local_20 - local_1C;
        ecx_local >>= 2;
        sub_5C9FE8(ecx_local, (int)"L$(Q", *(unsigned char*)0xE31AA9);
    }

    ecx_local = local_1C;
    eax = (int)"D$(PQ";
    edx = local_24;
    sub_6D67E0(edi, eax, edx, ecx_local, (int)&local_20);

    if (!*(char*)(esi + 0xB00)) {
        ecx_local = *(int*)(esi + 0xAC4);
        eax = sub_495F40(ecx_local);
        ecx_local = eax + 4;
        eax = *(int*)ecx_local;
        edx = *(int*)(eax + 0x18);
        ((int (__stdcall*)(int, int))edx)(edi, ecx_local);
    }

    if (*(char*)0xE32123) {
        ecx_local = esi;
        eax = sub_417E50(ecx_local);
        ecx_local = eax;
        ((int (__stdcall*)(int, int))0x5433C0)(edi, ecx_local);
    }

    if (*(char*)0xE580B3) {
        if (!*(char*)(esi + 0xB29)) {
            eax = *(int*)0xE5809C;
            if (eax) {
                if (sub_972290(0x618, (int)"C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\V8DataModel\\DataModel.cpp", (int)"C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\include\\gui/gui.h")) {
                    goto LABEL_1E3;
                }
            }
            eax = *(unsigned char*)0xE580B3;
            sub_972290((int)"L$8_^]d", eax, 0);
        }
    }
LABEL_1E3:
    eax = local_1C;
    if (eax) {
        sub_982114(eax);
    }

LABEL_1F4:
    return 0;
}
