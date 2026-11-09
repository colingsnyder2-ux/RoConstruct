// from server: 48% by Intel
struct EnumDesc {
    int getValue(int, int*, int*);
};

extern "C" int __cdecl sub_4015a0(int, int);
extern "C" int __cdecl sub_771380();
extern "C" void __cdecl sub_76f730(int*, int*);

int EnumDesc::getValue(int index, int* out1, int* out2) {
    int result = 0;
    if (index < *(int*)((char*)this + 0x2C)) {
        int* array = *(int**)((char*)this + 0x90);
        *out1 = array[index];
        result = 1;
    }
    sub_4015a0(0x7713E0, 0xE48628);
    int v = sub_771380();
    *out2 = v;
    sub_76f730(out1, out2);
    return result;
}
