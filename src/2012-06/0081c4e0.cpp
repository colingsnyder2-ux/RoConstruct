// from server: 73% by Intel
struct S {
    char pad_0[172];
    int field_68;
    char pad_6C[68];
    int field_AC;

    int f(int arg);
};

extern "C" int __stdcall sub_972290(int, int);
extern "C" int __stdcall sub_E5809C(int, int, int);

int S::f(int arg)
{
    if (*(char*)0xE580B3 != 0) {
        if (*(char*)((char*)this + 0x28) != 0) {
            int (__stdcall *func)(int, int, int) = *(int (__stdcall **)(int, int, int))0xE5809C;
            if (func) {
                if (func(0x290, 0xBC9340, 0xBA3894)) {
                    goto LABEL_CALL;
                }
            }
            sub_972290(0xBC9530, *(unsigned char*)0xE580B3);
        }
    }
LABEL_CALL:
    int vtable = *(int*)(*(int*)((char*)this + 0xAC));
    int (__stdcall *method)(int, int) = *(int (__stdcall **)(int, int))(vtable + 0xC);
    method(*(int*)((char*)this + 0xAC), arg);
    ++field_68;
    return 0;
}
