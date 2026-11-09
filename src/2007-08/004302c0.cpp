// from server: 43% by colin
struct CMainFrame {
    char pad[0xd8];
    void* field_d8;
    void OnCreate();
};

extern "C" void __stdcall sub_6750a0(void*, void*);
extern "C" void __stdcall sub_675df0(void*, void*);
extern "C" void __stdcall sub_6733d0(void*, void*);
extern "C" void __stdcall sub_676fb0(void*, int, int);
extern "C" void __stdcall sub_676c30(void*, int, int);
extern "C" void __stdcall sub_6768f0(void*, int, int, int);
extern "C" void __stdcall sub_676a70(void*, int, int);
extern "C" void __stdcall sub_6752d0(void*);
extern "C" void __stdcall sub_6757f0(void*);
extern "C" void __stdcall sub_673310(void*);

void CMainFrame::OnCreate()
{
    if (field_d8 == 0)
    {
        char buf1[0xc4];
        char buf2[0xc4];
        char buf3[8];

        sub_6750a0(buf3, field_d8);
        sub_675df0(buf2, buf3);
        sub_6733d0(buf1, buf2);

        void* p = *(void**)(buf1 + 0xb0);
        sub_676fb0(p, 0, 0x81);
        sub_676c30(p, -1, 0x23d1);
        sub_6768f0(p, -1, 0x23d6, 0x81);
        sub_676a70(p, -1, 0x23ca);

        sub_6752d0(buf3);
        sub_6757f0(buf2);
        sub_673310(buf3);
    }
}
