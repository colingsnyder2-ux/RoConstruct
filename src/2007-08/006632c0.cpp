// from server: 33% by colin
// roc 2007-08 006632c0  unit: CXTPReportRecordItemVariant  size: 293 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006632c0

struct CXTPReportRecordItemVariant {
    char pad[0x60];
    int field60;
    char pad2[0x18];
    int field7c;
    int sub_654ba0(int);
    int sub_65e450(void*, void*, void*);
    int sub_655910(void*, int, int);
    int sub_662710(void*, void*);

    int sub_6632c0(int a, int b);
};

extern "C" {
    int __stdcall sub_77dcd0(int);
    int __stdcall sub_77dd74(int, int);
    int __stdcall sub_77dcb8(int, const char*);
    int __stdcall sub_77dd98(int);
    int __cdecl sub_7385ec(void*, int);
    int __cdecl sub_738436(void*);
    int __cdecl sub_738424(void);
}

int CXTPReportRecordItemVariant::sub_654ba0(int a) {
    return 0;
}

int CXTPReportRecordItemVariant::sub_65e450(void* a, void* b, void* c) {
    return 0;
}

int CXTPReportRecordItemVariant::sub_655910(void* a, int b, int c) {
    return 0;
}

int CXTPReportRecordItemVariant::sub_662710(void* a, void* b) {
    return 0;
}

int CXTPReportRecordItemVariant::sub_6632c0(int a, int b) {
    char buf[0x40];
    int local_4c;
    int local_44;
    int local_3c;
    int local_34;
    int local_30;
    int local_24;
    int local_20;
    int local_14;
    int local_10;
    int local_c;
    int local_4;
    int result;
    int v;

    if (!sub_77dcd0((int)(this->pad + 0x60))) {
        sub_77dd74(a, (int)(this->pad + 0x60));
        return 0;
    }

    sub_7385ec(&local_4c, (int)&this->field7c);
    local_4 = 0;

    v = this->sub_654ba0(b);
    local_24 = v;
    v = *(int*)(v + 0x24);
    local_4c = v;

    sub_738436(&local_30);

    if (*(short*)&local_4c == 7) {
        local_4 = 2;
        if (v != 0) {
            goto label_3c1;
        }
        if (sub_77dcb8((int)(this->pad + 0x40), "HRESULT = %d: %s") == 0) {
            goto label_3a4;
        }
        local_3c = 0;
        local_34 = 0;
        this->sub_662710(&local_3c, &local_4c);
        v = sub_77dd98((int)(this->pad + 0x40));
        this->sub_65e450((void*)a, &local_3c, (void*)v);
        local_14 = 1;
        local_4 = 0;
        sub_738424();
        goto label_4fe;
    }

label_3a4:
    if (*(short*)&local_4c == 1) {
        *(short*)&local_4c = 3;
        local_44 = 0;
        local_4 = 1;
        goto label_3fe;
    }

label_3c1:
    {
        int edx = v;
        edx = -edx;
        edx = (edx >> 31) & 0xfffffffb;
        edx += 8;
        this->sub_655910(&local_4c, edx, 1);
        local_4 = 1;
    }

label_3fe:
    local_4 = 0;
    sub_738424();

label_4fe:
    return result;

label_508:
    return 0;
}
