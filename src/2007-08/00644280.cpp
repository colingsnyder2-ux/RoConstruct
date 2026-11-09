// from server: 45% by colin
struct CXTPCommandBar {
    void* field0;
    char pad[0x1c];
    void* field20;
    char pad2[0xac];
    int fieldcc;
    char pad3[0x10];
    int fielddc;
    char pad4[0x1c];
    int fieldfc;
    char pad5[0x2c];
    int field12c;
    char pad6[0x30];
    int field160;
    char pad7[0x8];
    int fieldc8;
    char pad8[0x2c];
    int fieldf8;
    void* field58;
    int field5c;

    int method_644280(int, int, int);
    int method_644250();
    int method_643980();
};

struct CXTPCommandBar2 {
    char pad[0x80];
    int field80;
};

extern "C" int __stdcall sub_6a37b0(void*);
extern "C" int __stdcall sub_6a3940(void*, void*);
extern "C" int __stdcall sub_6a38f0(void*, void*);
extern "C" int __stdcall sub_633900(void*);
extern "C" int __stdcall sub_63ab20(void*, int, int);
extern "C" int __stdcall sub_67a9a0(void*, int, int);

int CXTPCommandBar::method_644280(int a1, int a2, int a3)
{
    int result;
    int ebx;
    int ebp;
    int edi;
    int local10;
    int local14;

    edi = this->method_643980();
    ebp = sub_633900((void*)edi);
    local14 = ebp;

    if (this->fielddc == 0) {
        if (sub_6a37b0(this->field20) == 0) {
            ebx = 0;
        } else {
            ebx = 1;
        }
    } else {
        ebx = 1;
    }

    if (this->field20 == 0) {
        goto end;
    }

    if (sub_6a3940((void*)ebp, this) != 0) {
        goto end;
    }

    ebp = 5;

    if (ebx == 0) {
        if (this->fieldfc != ebp) {
            goto end;
        }
    }

    if (this->method_644250() != 0) {
        goto end;
    }

    if (edi != 0) {
        if (((CXTPCommandBar*)edi)->field5c != 0) {
            goto skip1;
        }
    }

    if (edi != 0) {
        if (((CXTPCommandBar*)edi)->field58 != 0) {
            result = sub_63ab20(((CXTPCommandBar*)edi)->field58, a1, a2);
            return result;
        }
    }
    goto end;

skip1:
    if (this->fieldcc != -1) {
        if (this->field160 == 0) {
            goto end;
        }
    }

    if (this->fieldfc == ebp) {
        if (this->fieldcc == -1) {
            if (this->field12c == 0) {
                result = 0;
            } else {
                result = 1;
            }
        } else {
            result = 1;
        }
    } else {
        result = 1;
    }

    if (this->fielddc != 0) {
        if (result != 0) {
            local10 = this->fieldc8;
        } else {
            local10 = -1;
        }
    } else {
        local10 = -1;
    }

    edi = sub_67a9a0((void*)this->fieldf8, a1, a2);

    if (edi != 0) {
        int temp = ((CXTPCommandBar2*)edi)->field80;
        sub_6a38f0((void*)local14, this->field20);
        local10 = temp;
        int* vtable = *(int**)edi;
        int (*func)(void*, int, int) = (int (*)(void*, int, int))vtable[0xfc/4];
        func((void*)edi, a1, a2);
    }

    int* vtable2 = *(int**)this;
    int (*func2)(void*, int, int) = (int (*)(void*, int, int))vtable2[0x148/4];
    func2(this, local10, 0);

end:
    return 0;
}
