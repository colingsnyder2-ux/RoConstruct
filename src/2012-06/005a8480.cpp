// from server: 46% by Intel
struct Image {
    int field_4;
    int field_8;
    int field_C;
    int field_10;

    int __stdcall sub_5A8480(int arg0, int arg4);
};

extern "C" void __stdcall sub_982114(int);

int __stdcall Image::sub_5A8480(int arg0, int arg4) {
    int ecx = arg0;
    int eax = *reinterpret_cast<int*>(ecx);
    int edx = *reinterpret_cast<int*>(eax);
    *reinterpret_cast<int*>(ecx) = edx;
    --field_10;
    if (eax) {
        eax -= 8;
    } else {
        eax = 0;
    }
    sub_982114(eax);
    eax = field_C;
    if (arg4 != eax) {
        return 1;
    }
    if (field_10 != 0) {
        edx = field_8;
        eax = field_4;
        ecx = eax + edx * 4;
        field_C = ecx;
        return 1;
    }
    if (*reinterpret_cast<int*>(eax) != 0) {
        return 1;
    }
    do {
        eax += 4;
        field_C = eax;
    } while (*reinterpret_cast<int*>(eax) == 0);
    return 1;
}
