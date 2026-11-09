// from server: 57% by Intel
struct EnumDesc {
    int method(int, int*, int*);
};

extern "C" int __stdcall sub_4015a0(int, int);
extern "C" int __cdecl sub_556fc0();
extern "C" void __cdecl sub_556900(int*, int*);

int EnumDesc::method(int value, int* out1, int* out2) {
    int result = 0;
    if (value < *(int*)((char*)this + 0x2C)) {
        int* array = *(int**)((char*)this + 0x90);
        result = array[value];
        *out1 = result;
    }
    sub_4015a0(0x557020, 0xE22EF4);
    int v = sub_556fc0();
    *out2 = v;
    sub_556900(out1, out2);
    return result != 0;
}
