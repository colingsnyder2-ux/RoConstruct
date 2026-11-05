// from server: 38% by colin
// roc 2007-08 004a2070  unit: RBX::Network::VServer::?$BoundFuncDesc  size: 304 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a2070

extern "C" {
    int __stdcall sub_49FD90(void* a, int b, int c);
    int __stdcall sub_4A0660(void* a, void* b);
    int __stdcall sub_4A1920(void* a, void* b);
    int __stdcall sub_4A1F90(void* a, void* b);
}

extern "C" {
    int __stdcall MSVCP80_8DU(void* a, const char* b);
    int __stdcall MSVCP80_4(void* a, void* b);
    void __stdcall MSVCR80_invalid_parameter_noinfo();
}

struct BoundFuncDesc {
    char pad[0xe0c];
    int field_e0c;
    int method(int a, int b);
};

int BoundFuncDesc::method(int a, int b)
{
    char buf[12];
    int local;
    int* p;
    int* q;
    int r;

    if (MSVCP80_8DU((void*)0x785954, (const char*)a)) {
        buf[0] = 0;
        sub_49FD90(&buf[0], 8, 1);
        return 0;
    }

    sub_4A1920(this, &local);

    if (buf[0] != 0) {
        int v = this->field_e0c;
        int rem = v % 0x7f;
        int nv = rem + 1;
        this->field_e0c = nv;
        int off = nv * 8 - nv;
        sub_4A1F90(this, (char*)this + off * 4 + 0xc);

        if (local == 0)
            MSVCR80_invalid_parameter_noinfo();
        if (buf[0] == *(int*)(local + 4))
            MSVCR80_invalid_parameter_noinfo();

        *(char*)(buf[0] + 0x28) = (char)this->field_e0c;

        int v2 = this->field_e0c;
        int off2 = v2 * 8 - v2;
        MSVCP80_4((char*)this + off2 * 4 + 0xc, (void*)a);

        char al = (char)this->field_e0c;
        al |= 0x80;
        buf[0] = al;
        sub_49FD90(&buf[0], 8, 1);
        sub_4A0660((void*)a, this);
        return 0;
    }

    if (local == 0)
        MSVCR80_invalid_parameter_noinfo();
    if (buf[0] == *(int*)(local + 4))
        MSVCR80_invalid_parameter_noinfo();

    char dl = *(char*)(buf[0] + 0x28);
    buf[0] = dl;
    sub_49FD90(&buf[0], 8, 1);
    return 0;
}
