// from server: 40% by Intel
struct BoundFuncDesc
{
    int construct(void* a1, void* a2, void* a3, void* a4, void* a5, void* a6);
};

extern "C" int __stdcall sub_8C73A0(void* thisptr, void* a1, void* a2, void* a3, void* a4);
extern "C" int __cdecl sub_6C1520();

int BoundFuncDesc::construct(void* a1, void* a2, void* a3, void* a4, void* a5, void* a6)
{
    int v1 = sub_8C73A0(this, a1, a2, a3, a4);
    int v2 = sub_6C1520();

    *(int*)this = 0xBE66F8;
    *(int*)((char*)this + 0x30) = (int)a5;
    *(int*)((char*)this + 0x34) = (int)a6;
    *(int*)((char*)this + 0x1C) = v2;

    return (int)this;
}
