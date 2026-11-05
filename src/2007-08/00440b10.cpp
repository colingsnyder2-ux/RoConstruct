// from server: 36% by colin
struct CSelectionPropGrid;

struct CSelectionPropGrid {
    void sub_440B10();
};

extern "C" void __stdcall sub_5592D0(void*, void*);
extern "C" void __stdcall sub_5595A0(void*);
extern "C" void __stdcall sub_410BB0(void*);
extern "C" void __stdcall sub_40F800(void*);
extern "C" void __stdcall sub_62FC62(void*);
extern "C" void __stdcall sub_77E69C(void*, void*);

void CSelectionPropGrid::sub_440B10()
{
    char* base = (char*)this;
    int* p1 = *(int**)(base + 0x11c);
    if (*(int*)((char*)p1 + 0x188) != 0)
    {
        int* p2 = *(int**)((char*)p1 + 0x188);
        int local60 = 0;
        int local5c = 0;
        int local58 = 0;
        sub_5592D0(&local60, p2);
        int local18 = 0;
        int local1c = 0;
        int* p3 = *(int**)(base + 0x120);
        int* p4 = *(int**)((char*)p3 + 4);
        void* p5 = (char*)p4 + 4;
        sub_77E69C(&local1c, p5);
        int* p6 = *(int**)(base + 0x11c);
        int* p7 = *(int**)((char*)p6 + 0x188);
        sub_410BB0((char*)p7 + 0x160);
        int* p8 = *(int**)(base + 0x11c);
        int* p9 = *(int**)((char*)p8 + 0x188);
        int* p10 = (int*)((char*)p9 + 0x160);
        int* p11 = *(int**)p10;
        void (*p12)(int) = *(void(**)(int))((char*)p11 + 4);
        p12(1);
        sub_5595A0(&local60);
        if (local18 != 0)
        {
            sub_40F800((char*)local18 + 8);
            sub_62FC62((void*)local18);
        }
        if (local1c != 0)
        {
            sub_40F800((char*)local1c + 8);
            sub_62FC62((void*)local1c);
        }
    }
}
