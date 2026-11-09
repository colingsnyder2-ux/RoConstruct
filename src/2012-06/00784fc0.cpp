// from server: 47% by Intel
struct DialogRoot_W4DialogTone_EnumDesc {
    int getEnumValue(int index, int* outValue, int* outName);
};

extern "C" int __stdcall sub_4015a0(int a1, int a2);
extern "C" int __stdcall sub_771230();
extern "C" int __stdcall sub_76F070(int* a1, int* a2);

int DialogRoot_W4DialogTone_EnumDesc::getEnumValue(int index, int* outValue, int* outName) {
    int result = 0;
    if (index < *(int*)((char*)this + 0x2C)) {
        int* array = *(int**)((char*)this + 0x90);
        *outValue = array[index];
        result = 1;
    }
    sub_4015a0(0x771290, 0xE4861C);
    int v = sub_771230();
    *outName = v;
    int temp[2];
    temp[0] = *outValue;
    temp[1] = v;
    sub_76F070(temp + 1, temp);
    return result;
}
