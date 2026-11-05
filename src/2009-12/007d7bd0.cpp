// from server: 86% by atomic.potato
struct HumanoidStage {
    void* vtable0;
    void* vtable1;
    char pad[4];
    float field_c;
    void* init(void* a, void* b);
};

extern float g_float_9b2690;
extern void* g_vtbl_9ef688;
extern void* g_vtbl_9ef680;
extern void base_init(void* self, void* a, void* b);

void* HumanoidStage::init(void* a, void* b)
{
    base_init(this, a, b);
    field_c = g_float_9b2690;
    vtable0 = &g_vtbl_9ef688;
    vtable1 = &g_vtbl_9ef680;

    return this;
}
