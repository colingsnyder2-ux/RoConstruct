// from server: 0% by atomic.potato
struct S_func_006e50e0 {
    char pad0[4];
    void f(void* a1);
};

extern "C" int __stdcall sub_00801fe0(void*);
extern "C" int __stdcall sub_008020f0(void*, void*, void*, void*);
extern "C" int __stdcall sub_00802140(void*, void*, void*, int);
extern "C" int __stdcall sub_00802210(void*, void*);
extern "C" int __stdcall sub_a40400(const char*, int);

extern int dword_ac02ec;
extern int dword_ac0304;

void S_func_006e50e0::f(void* a1)
{
    char* self = (char*)this;
    int* p = *(int**)self;
    if ((*(unsigned char*)((char*)p + 0x24) & 2) == 0)
        return;

    char* base = (char*)p + 0x14;
    char flag = 1;
    char* flagp = &flag;

    while (flag) {
        char* edi = base + 8;
        int eax = *(int*)(base + 0xc);
        if (*(int*)edi != eax) {
            void* esi = *(void**)self;
            sub_008020f0(esi, &flagp, edi, (void*)eax);
            int r = sub_00802210(esi, (void*)dword_ac0304);
            sub_00802140(esi, &flagp, edi, 1);
            sub_00801fe0((void*)r);
            flag = (r != dword_ac02ec);
        }
        p = *(int**)self;
        int ecx = *(int*)((char*)p + 0x14);
        int edi2 = *(int*)((char*)p + 0x1c) - ecx;
        int esi2 = 0;
        while (esi2 < edi2) {
            int n = edi2 - esi2;
            int r = sub_a40400((const char*)(ecx + esi2), n);
            esi2 += r;
        }
    }
}
