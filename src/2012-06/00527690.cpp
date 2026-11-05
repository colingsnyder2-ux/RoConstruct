// from server: 88% by atomic.potato
struct RBX_VShirt_FactoryProduct_Creator {
    void* vftable;
    void construct();
};

extern "C" void __stdcall sub_972290(unsigned int a, const char* b);
extern "C" void* __stdcall sub_4019d0(void* a);
extern "C" void __stdcall sub_4a11d0(void* a);
extern "C" void* __stdcall sub_51f8e0(void* a);

extern unsigned char byte_E580B3;
extern int dword_E1E0B8;
extern int dword_E5809C;

void RBX_VShirt_FactoryProduct_Creator::construct()
{
    this->vftable = (void*)0xB6FA58;
    if (byte_E580B3 != 0)
    {
        if (dword_E1E0B8 != 0x29A)
        {
            int fn = dword_E5809C;
            if (fn != 0)
            {
                if (((char (__cdecl*)(const char*, const char*, int))fn)((const char*)0xB42F90, (const char*)0xB42FA8, 0xE2) != 0)
                    goto skip;
            }
            sub_972290((unsigned int)byte_E580B3, (const char*)0xB43368);
        }
    }
skip:
    void* p = sub_51f8e0(this);
    void* q = sub_4019d0(&p);
    sub_4a11d0(q);
}
