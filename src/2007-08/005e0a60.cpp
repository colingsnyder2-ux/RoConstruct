// from server: 45% by colin
struct RBX_Vector3 {
    float x;
    float y;
    float z;
};

struct RBX_VMotorFeature_FactoryProduct {
    char pad0[8];
    int field8;
    char padC[0x14];
    int field20;
    RBX_Vector3* getValue(RBX_Vector3* result);
};

extern "C" void __stdcall sub_5ba530(int*, int*);
extern "C" void __stdcall sub_5e1770(int*, int*, int, int);
extern "C" void __stdcall sub_4ff810(int);

extern int dword_8BD138;
extern float dword_8BD12C;
extern float dword_8BD130;
extern float dword_8BD134;

RBX_Vector3* RBX_VMotorFeature_FactoryProduct::getValue(RBX_Vector3* result)
{
    int local8 = 0;
    int localC = 0;
    int local10 = 0;
    int local14 = 0;

    sub_5ba530(&this->field8, &local8);

    if (localC <= 0) {
        if ((dword_8BD138 & 1) == 0) {
            dword_8BD138 |= 1;
            dword_8BD12C = 0.0f;
            dword_8BD130 = 0.0f;
            dword_8BD134 = 0.0f;
        }
        result->x = dword_8BD12C;
        result->y = dword_8BD130;
        result->z = dword_8BD134;
        sub_4ff810(local8);
        return result;
    }

    sub_5e1770(&local14, &local8, this->field20, local14);
    result->x = *(float*)&local14;
    result->y = *(float*)&local14;
    result->z = *(float*)&local14;
    sub_4ff810(local8);
    return result;
}
