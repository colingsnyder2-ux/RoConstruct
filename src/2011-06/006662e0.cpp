// from server: 39% by atomic.potato
struct VCRenderSettingsItem
{
    void sub_666120(float);
    void sub_664830(float);
};

extern float g_a9bfe8;
extern float g_a9bfe4;

extern "C" void* __stdcall sub_80b2ea(void*, int, const char*, const char*, int);

void VCRenderSettingsItem::sub_666120(float) {}
void VCRenderSettingsItem::sub_664830(float) {}

void __stdcall func(VCRenderSettingsItem* self, float* p)
{
    self->sub_666120(p[1] * g_a9bfe8);
    self->sub_664830(p[0] * g_a9bfe4);
    void* inst = *(void**)((char*)self + 0x140);
    if (inst)
    {
        void* r = sub_80b2ea(inst, 0, (const char*)0xc071f8, (const char*)0xc38f48, 0);
        if (r)
        {
            void** vt = *(void***)r;
            ((void (__thiscall*)(void*))vt[1])(r);
        }
    }
}
