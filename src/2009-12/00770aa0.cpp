// from server: 35% by atomic.potato
struct VCRenderSettingsItem_EnumPropDescriptor {
    void construct(int a, int b, int c, int d, int e);
};

extern "C" int __stdcall sub_651830(int, int);
extern "C" int __stdcall sub_702820(int);
extern "C" int __stdcall sub_6322e0(int);
extern "C" int __stdcall sub_642fc0();
extern "C" int __stdcall sub_6aa720(int);
extern "C" int __stdcall sub_4f8c90(int, int, int);
extern "C" int __stdcall sub_4f73d0(int, int);

void VCRenderSettingsItem_EnumPropDescriptor::construct(int a, int b, int c, int d, int e)
{
    int v1 = sub_651830(a, b);
    sub_702820(v1);
    *(int*)((char*)this + 0x34) = c;
    *(int*)this = 0x9e8564;
    int v2 = sub_6322e0(d);
    ++*(int*)0xb8ff80;
    int v3 = sub_642fc0();
    sub_6aa720((int)((char*)this + 0x2c));
    int v4 = *(int*)((char*)this + 0x2c);
    int v5 = *(int*)(v4 + 4);
    int v6 = sub_4f8c90((int)((char*)this + 0x18), v4, v5);
    sub_4f73d0((int)((char*)this + 0x18), 1);
    *(int*)(v4 + 4) = v6;
    *(int*)(v6 + 4) = v6;
    int v7 = sub_6322e0(e);
    ++*(int*)0xb8ff80;
    int v8 = sub_642fc0();
    sub_6aa720((int)((char*)this + 0x18));
    int v9 = *(int*)((char*)this + 0x2c);
    int v10 = *(int*)(v9 + 4);
    int v11 = sub_4f8c90((int)((char*)this + 0x18), v9, v10);
    sub_4f73d0((int)((char*)this + 0x18), 1);
    *(int*)(v9 + 4) = v11;
    *(int*)(v11 + 4) = v11;
    if (v3) {
        (*(void(**)(int, int))v3)(v3, 1);
    }
    if (v8) {
        (*(void(**)(int, int))v8)(v8, 1);
    }
}
