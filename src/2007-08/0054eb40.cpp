// from server: 100% by colin
struct stream_buffer {
    char pad[0x18];
    void* field_18;
    void func_54d4c0();
};

extern void* g_77e4dc;
extern void* g_77e4e0;
extern void (__cdecl *g_77e4e4)(void*);

void stream_buffer::func_54d4c0()
{
    this->func_54d4c0();
    this->field_18 = g_77e4dc;
    this->field_18 = g_77e4e0;
    g_77e4e4(&this->field_18);
}
