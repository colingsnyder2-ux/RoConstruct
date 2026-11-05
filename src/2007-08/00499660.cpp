// from server: 100% by colin
struct VServiceProviderListener {
    void onServiceProvider(int a1);
};

extern "C" void __stdcall sub_541C30();

void VServiceProviderListener::onServiceProvider(int a1)
{
    sub_541C30();
    int* p = *(int**)((char*)this + 0xf8);
    int v = *(int*)((char*)this + 0x134);
    int w = *(int*)((char*)this + 0x130);
    (*(void(__thiscall**)(int*, int, int, int, int))(*(int*)p + 0x64))(p, w, v, 1, 0);
    int* q = *(int**)((char*)this + 0xf8);
    (*(void(__thiscall**)(int*, int, int))(*(int*)q + 0x28))(q, a1, 0);
}
