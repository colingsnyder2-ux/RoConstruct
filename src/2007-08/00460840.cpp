// from server: 59% by colin
struct CScriptDoc
{
    char pad[0xbc];
    void* field_bc;
};

extern "C" void __stdcall sub_42A4E0(void*);
extern "C" void* __cdecl sub_630D36(void*, void*, void*, void*, void*);
extern "C" void __stdcall sub_4605F0(void*, void*);

void* CScriptDoc_460840(CScriptDoc* self, void** out)
{
    if (self != 0)
    {
        out[0] = 0;
        out[1] = 0;
        return 0;
    }
    if (self->field_bc != 0)
    {
        sub_42A4E0(self->field_bc);
    }
    void* p = sub_630D36(self, (void*)0x881F4C, (void*)0x8865A0, 0, 0);
    if (p == 0)
    {
        out[0] = 0;
        out[1] = 0;
        return 0;
    }
    sub_4605F0(p, out);
    return out;
}
