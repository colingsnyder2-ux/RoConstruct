// from server: 62% by atomic.potato
extern "C" int __stdcall sub_6a11c0(int*, int*, int, int, int, int, int);
extern "C" int __stdcall sub_6a12f0(int*, int, int, int, int, int, int);

struct VWiniInetRequest_source
{
    char pad0[0x10];
    int* field_10;
    int* field_14;
    char pad18[0x8];
    int* field_20;
    int* field_24;
    char pad28[0x8];
    int* field_30;
    int* field_34;
    char pad38[0x8];
    char field_40[0xC];
    int field_4c;
    int __cdecl method(int, int, int, int);
};

int VWiniInetRequest_source::method(int a2, int a3, int a4, int a5)
{
    int v6;
    int v7;
    int v8;
    int v9;
    int v10;
    int v11;
    int v12;
    int v13;

    v6 = a2;
    v7 = a3;
    v8 = a4;
    v9 = a5;

    if (*field_20 != 0 && v7 == 1 && v9 == 1)
    {
        v10 = *field_10 - *field_20;
        v11 = (v10 >> 31);
        if (v6 > v11 || (v6 == v11 && (unsigned int)v10 < (unsigned int)v8))
        {
            goto skip;
        }
        v12 = *field_30;
        v13 = (v12 >> 31);
        if (v6 > v13 || (v6 == v13 && (unsigned int)v8 > (unsigned int)v12))
        {
            goto skip;
        }
        *field_30 -= v8;
        *field_20 += v8;
        sub_6a11c0((int*)&v6, (int*)((char*)this + 0x40), field_4c, 0, 0, 1, 1);
    }
skip:
    if (*field_24 != 0)
    {
        ((int (__thiscall*)(void*))0x009ea500)(this);
    }
    if (v7 == 1 && *field_20 != 0)
    {
        v8 -= *field_30;
        v6 -= (v8 >> 31);
    }
    *field_10 = 0;
    *field_20 = 0;
    *field_30 = 0;
    *field_14 = 0;
    *field_24 = 0;
    *field_34 = 0;
    sub_6a12f0((int*)((char*)this + 0x40), v6, v7, v8, v9, field_4c, a5);
    return 0;
}
