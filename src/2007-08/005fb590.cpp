// from server: 31% by colin
struct FlatTool {
    char pad[0x310];
    void* field310;
    void func(void*);
};

extern "C" void* __cdecl sub_62FEF6(unsigned int);
extern "C" void __cdecl sub_62FC62(void*);
extern "C" void __cdecl sub_564810(void*, void*);
extern "C" void __cdecl sub_561B10(void*, int);
extern "C" void __cdecl sub_58C810(void*);
extern "C" void __cdecl sub_40F800(void*);
extern "C" void __cdecl sub_410BB0(void*);
extern "C" void __cdecl sub_77E69C(void*, void*);

void FlatTool::func(void* arg)
{
    void* p = *(void**)((char*)this + 0x310);
    if (p) {
        void* q = 0;
        void* r = sub_62FEF6(0x2c);
        if (r) {
            *(void**)((char*)r + 4) = (void*)0x786db0;
            *(void**)((char*)r + 0x28) = (void*)0x786d0c;
            void* ecx = *(void**)((char*)r + 4);
            *(void**)r = (void*)0x786d9c;
            void* edx = *(void**)((char*)ecx + 4);
            *(void**)((char*)edx + (int)r + 4) = (void*)0x786d94;
            void* g = *(void**)0x8c225c;
            *(void**)((char*)r + 8) = 0;
            *(void**)((char*)r + 0xc) = 0;
            *(void**)((char*)r + 0x10) = 0;
            *(void**)((char*)r + 0x14) = g;
            *(void**)((char*)r + 0x18) = 0;
            *(void**)((char*)r + 0x20) = 0;
            *(void**)((char*)r + 0x24) = 0;
            void* ecx2 = *(void**)((char*)r + 4);
            *(void**)r = (void*)0x786dac;
            void* edx2 = *(void**)((char*)ecx2 + 4);
            *(void**)((char*)edx2 + (int)r + 4) = (void*)0x786da4;
            q = r;
        }
        void* ebp = *(void**)((char*)this + 0x1c);
        if (q != ebp) {
            if (ebp) {
                sub_40F800((char*)ebp + 8);
                sub_62FC62(ebp);
            }
        }
        *(void**)((char*)this + 0x1c) = q;
        void* eax = *(void**)((char*)this + 0x20);
        sub_564810(q, eax);
        void* ecx3 = *(void**)((char*)this + 0x28);
        void* eax2 = *(void**)this;
        void* edx3 = *(void**)((char*)eax2 + 0x3c);
        sub_564810(this, ecx3);
        void* eax3 = *(void**)((char*)this + 0x18);
        sub_561B10(eax3, 8);
        sub_58C810(eax3);
        void* r2 = sub_62FEF6(0x2c);
        if (r2) {
            *(void**)((char*)r2 + 4) = (void*)0x786db0;
            *(void**)((char*)r2 + 0x28) = (void*)0x786d0c;
            void* ecx4 = *(void**)((char*)r2 + 4);
            *(void**)r2 = (void*)0x786d9c;
            void* edx4 = *(void**)((char*)ecx4 + 4);
            *(void**)((char*)edx4 + (int)r2 + 4) = (void*)0x786d94;
            void* g2 = *(void**)0x8c225c;
            *(void**)((char*)r2 + 8) = 0;
            *(void**)((char*)r2 + 0xc) = 0;
            *(void**)((char*)r2 + 0x10) = 0;
            *(void**)((char*)r2 + 0x14) = g2;
            *(void**)((char*)r2 + 0x18) = 0;
            *(void**)((char*)r2 + 0x20) = 0;
            *(void**)((char*)r2 + 0x24) = 0;
            void* ecx5 = *(void**)((char*)r2 + 4);
            *(void**)r2 = (void*)0x786dc4;
            void* edx5 = *(void**)((char*)ecx5 + 4);
            *(void**)((char*)edx5 + (int)r2 + 4) = (void*)0x786dbc;
            q = r2;
        }
        void* eax4 = *(void**)((char*)this + 0x20);
        sub_564810(q, eax4);
        void* eax5 = *(void**)((char*)this + 0x1c);
        sub_564810(q, eax5);
        sub_77E69C((char*)this + 0x30, 0);
        void* ecx6 = *(void**)((char*)this + 0x18);
        void* ecx7 = *(void**)((char*)ecx6 + 0x310);
        sub_410BB0(ecx7);
        void* edx6 = *(void**)((char*)this + 0x18);
        void* ecx8 = *(void**)((char*)edx6 + 0x310);
        void* eax6 = *(void**)ecx8;
        void* edx7 = *(void**)((char*)eax6 + 4);
        sub_564810(ecx8, (void*)1);
    }
}
