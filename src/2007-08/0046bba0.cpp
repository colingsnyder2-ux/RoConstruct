// from server: 27% by colin
struct LDrawCommand {
    void* vtable;
    void* field4;
    void construct(const char* name);
};

extern "C" {
    void* __stdcall sub_62FEF6(unsigned int size);
    void __stdcall sub_77E698(void* dst, const char* src);
    void __stdcall sub_77E6AC(void* p);
    void __stdcall sub_408740(void* dst, void* src);
    void __stdcall sub_5491A0(void* p);
    void __stdcall sub_469DA0(void* p);
}

extern void* g_8BCF44;
extern char g_796310[];
extern char g_796314[];

void LDrawCommand::construct(const char* name)
{
    this->vtable = g_796310;
    sub_77E698(&this->field4, name);

    if (g_8BCF44 == 0)
    {
        void* obj = sub_62FEF6(0x54);
        if (obj != 0)
        {
            char buf[28];
            sub_77E698(buf, g_796314);
            sub_408740(buf, buf);
            sub_5491A0(buf);
            sub_469DA0(obj);
        }
        void* old = g_8BCF44;
        if (obj != old)
        {
            if (old != 0)
            {
                void** vt = *(void***)old;
                void (*dtor)(void*, int) = (void (*)(void*, int))vt[0];
                dtor(old, 1);
            }
        }
        g_8BCF44 = obj;
    }
}
