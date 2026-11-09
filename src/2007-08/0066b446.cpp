// from server: 36% by colin
struct MyXTPCommandBars
{
    char pad[0xf8];
    void* field_f8;
    int func1(void* a, void* b);
};

extern "C" void __stdcall sub_006301e4(void* p);

int MyXTPCommandBars::func1(void* a, void* b)
{
    void* v = field_f8;
    (*(void (__thiscall**)(void*))(*(int*)v + 0x6c))(v);
    (*(void (__thiscall**)(void*, void*))(*(int*)a + 0x58))(a, b);
    sub_006301e4(this);
    return 1;
}
