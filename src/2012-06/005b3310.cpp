// from server: 19% by 41k
// roc-repair: genuine WinNT.h definitions (no SDK shipped)
typedef unsigned long DWORD;
struct RBX_Network_ErrorCompPhysicsSender2 {
    DWORD field_4;
    DWORD field_8;
    DWORD field_C;

    void someMethod(DWORD a1, DWORD a2, DWORD a3);
};

extern "C" void __stdcall someFunction(DWORD, DWORD, DWORD);

void RBX_Network_ErrorCompPhysicsSender2::someMethod(DWORD a1, DWORD a2, DWORD a3) {
    if (this->field_4 == a1 && this->field_8 == a2) {
        this->field_4 = a1;
        return;
    }

    DWORD* ptr1 = (DWORD*)this->field_4;
    DWORD* ptr2 = (DWORD*)a1;

    if (*ptr1 == *ptr2) {
        this->field_4 = *ptr2;
        return;
    }

    if (this->field_C != 0) {
        if (this->field_4 != a3 && this->field_8 != a3) {
            someFunction(0, 1, a3);
        }
    } else {
        if (this->field_4 != a2 && this->field_8 != a2) {
            someFunction(0, 1, a2);
        }
    }

    this->field_4 = *ptr2;
}
