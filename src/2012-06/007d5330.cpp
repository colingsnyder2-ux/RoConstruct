// from server: 44% by atomic.potato
struct RBX_Class;
struct RBX_Property;

extern "C" void __cdecl sub_00982114(void*);
extern "C" void* __cdecl sub_0098211a(unsigned int);
extern "C" void __cdecl sub_00972290(unsigned char, const char*);
extern "C" void* __cdecl sub_00782b30(void*, void*, void*);
extern "C" void __cdecl sub_0040cf10(void*, void*);

extern char g_b44a08;
extern char g_bc0c14;
extern char g_e580b3;
extern void* g_e5809c;
extern char g_b932b8;
extern char g_b43f40;
extern char g_b44978;
extern char g_dc0670;
extern void* g_b229ec;

struct RBX_Property
{
    void* vftable;
    void* field_04;
    void* field_08;
    void* field_0c;
    void* field_10;
    void* field_14;
    void* field_18;
    void* field_1c;
    void* field_20;
    void* field_24;
    void* field_28;

    void construct(void* a, void* b, void* c, void* d, void* e, void* f);
};

void RBX_Property::construct(void* a, void* b, void* c, void* d, void* e, void* f)
{
    void* local0 = 0;
    void* local1 = 0;
    void* local2 = 0;
    void* local3 = 0;
    void* local4 = 0;
    void* local5 = 0;

    local0 = a;
    local1 = b;
    local2 = c;

    void* r = sub_00782b30(&local0, &local1, &local2);
    sub_0040cf10(this, r);

    sub_00982114(0);

    this->vftable = &g_b44a08;

    if (g_e580b3 != 0)
    {
        if (!((char (__stdcall*)(void*))g_b229ec)(&g_dc0670))
        {
            if (g_e5809c != 0)
            {
                if (((char (__cdecl*)(int, const char*, const char*))g_e5809c)(0x1a7, &g_b43f40, &g_b44978))
                    goto skip;
            }
            sub_00972290((unsigned char)g_e580b3, &g_b932b8);
        }
    }
skip:
    void* mem = sub_0098211a(0x18);
    void* obj;
    if (mem != 0)
    {
        *(void**)mem = &g_bc0c14;
        *(void**)((char*)mem + 4) = this;
        *(void**)((char*)mem + 8) = local3;
        *(void**)((char*)mem + 0x10) = local4;
        *(void**)((char*)mem + 0x14) = local5;
        obj = mem;
    }
    else
    {
        obj = 0;
    }

    void* old = this->field_28;
    if (obj != old)
    {
        sub_00982114(old);
    }
    this->field_28 = obj;
}
