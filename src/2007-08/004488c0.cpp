// from server: 100% by colin
struct CRbxDocTemplate {
    char pad[0x58];
    void* field_58;
    void method();
};

void sub_4525A0();

void CRbxDocTemplate::method()
{
    void* p = field_58;
    void* q = *(void**)((char*)p + 0x24);
    void** vtbl = *(void***)q;
    void* (__stdcall *fn)(int, int) = (void* (__stdcall *)(int, int))vtbl[0x88 / 4];
    void* r = fn(0, 1);
    ((void (__thiscall*)(void*))sub_4525A0)(r);
}
