// from server: 31% by colin
struct S_func_006ab9d0 {
    char pad[0x270];
    void* m_p270;
    void f();
};

extern "C" void* __stdcall sub_0062fef6(int);
extern "C" void* __stdcall sub_00632790(void*, void*, void*, int, int, void*);
extern "C" void* __stdcall sub_0063a580(void*);
extern "C" void* __stdcall sub_006a7a50(void*);
extern "C" void* __stdcall sub_006ab2f0(void*);
extern "C" void* __stdcall sub_006d2910(void*, void*, void*);
extern "C" void* __stdcall sub_0077dd98();
extern "C" void* __stdcall sub_0077ddbc();

void S_func_006ab9d0::f()
{
    int esi = (int)this;
    int eax = *(int*)((char*)this + 0xc0);
    int edx = *(int*)((char*)this + 0xc8);
    int ecx = *(int*)((char*)this + 0xcc);
    eax += edx;
    eax -= edx;
    int edi = eax;
    void* ebx = sub_0062fef6(0x74);
    esi >>= 1;
    edi >>= 1;
    if (ebx != 0) {
        void* p = *(void**)((char*)this + 0x270);
        void* vt = *(void**)p;
        void* fn = *(void**)((char*)vt + 0x58);
        void* r = ((void* (__stdcall*)(void*, void*))fn)(p, 0);
        void* ebp = r;
        void* p2 = *(void**)((char*)this + 0x270);
        int edx2 = *(int*)((char*)p2 + 0x9c);
        int eax2;
        if (edx2 == -1) {
            void* p3 = *(void**)((char*)p2 + 0x158);
            if (p3 != 0) {
                eax2 = (int)sub_0063a580(p3);
            } else {
                eax2 = edx2;
            }
        } else {
            eax2 = edx2;
        }
        void* r2 = ((void* (__stdcall*)(void*, int, int, int, int))sub_0077dd98)(ebp, edi, esi, 5, eax2);
        void* p4 = *(void**)((char*)this + 0x270);
        void* r3 = sub_00632790(ebx, (void*)r2, p4, 0, 0, 0);
        esi = (int)r3;
    } else {
        esi = 0;
    }
    sub_0077ddbc();
    void* p5 = *(void**)((char*)this + 0x34);
    sub_006d2910((char*)this + 0x2c, p5, (void*)esi);
    if (*(int*)((char*)this + 0x44) == 2) {
        void* r4 = sub_006a7a50(this);
        sub_006ab2f0((char*)this + 0x1c4);
    }
}
