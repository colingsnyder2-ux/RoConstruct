// from server: 41% by atomic.potato
extern "C" void* __stdcall sub_006c1360();
extern "C" void* __stdcall sub_007839d0();
extern "C" void* __stdcall sub_0067f2e0(void*, void*);
extern "C" void __stdcall sub_00709480();

struct ButtonBindingWidget_007a03b0
{
    char pad_0000[0x1c];
    void* field_001c;
    void construct();
};

void ButtonBindingWidget_007a03b0::construct()
{
    void* p;
    void* q;
    void* r;
    field_001c = sub_006c1360();
    p = sub_007839d0();
    q = sub_0067f2e0(&r, p);
    sub_00709480();
    if (r)
    {
        void (__stdcall *fn)(void*) = *(void (__stdcall **)(void*))((char*)r + 4);
        fn(&q);
    }
}
