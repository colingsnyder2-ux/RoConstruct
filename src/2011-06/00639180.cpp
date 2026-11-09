// from server: 94% by atomic.potato
extern "C" void __stdcall func_0063fa00(void*);

struct RBX_BaseScript
{
    char pad0[0xb0];
    void* field_b0;
    void method_00639180(int, int);
};

void RBX_BaseScript::method_00639180(int a, int b)
{
    if (a != 0)
    {
        if (field_b0 != 0)
        {
            void* p = field_b0;
            field_b0 = 0;
            func_0063fa00(p);
        }
    }
    if (b != 0)
    {
        void** vt = *(void***)this;
        void (__thiscall *fn)(void*) = (void (__thiscall *)(void*))vt[0x5c / 4];
        fn(this);
    }
}
