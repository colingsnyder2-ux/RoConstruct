// from server: 24% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct FilteredSelection {
    char pad[0xc0];
    void* field_c0;
    void method();
};

extern "C" void* __cdecl sub_630D36(void*, void*, void*, void*, void*);
extern "C" void __cdecl sub_55F400(void*, void*, void*, void*, void*, void*, void*);
extern "C" void* __cdecl sub_573890(void*);
extern "C" void* __cdecl sub_5B6CB0(void*, int);
extern "C" int __cdecl sub_5B9120(void*);
extern "C" void __cdecl sub_5B9270(void*, int);
extern "C" void __cdecl _invalid_parameter_noinfo();

void FilteredSelection::method()
{
    void* p = sub_630D36(0, (void*)0x881f4c, (void*)0x884a28, 0, this);
    if (p) {
        void* edi = sub_573890(p);
        int esi = 0;
        do {
            void* a = sub_5B6CB0(edi, esi);
            if (sub_5B9120(a) == 1) {
                void* b = sub_5B6CB0(edi, esi);
                sub_5B9270(b, 2);
            }
            esi++;
        } while (esi < 6);
    }
    if (this->field_c0) {
        void* esi = this->field_c0;
        void* ebx = *(void**)((char*)esi + 8);
        if (*(unsigned int*)((char*)esi + 4) > (unsigned int)ebx) {
            _invalid_parameter_noinfo();
        }
        void* edi = this->field_c0;
        void* ebp = *(void**)((char*)edi + 4);
        if ((unsigned int)ebp > *(unsigned int*)((char*)edi + 8)) {
            _invalid_parameter_noinfo();
        }
        sub_55F400(edi, 0, esi, ebx, ebp, (void*)0x560260, 0);
    }
    if (this->field_c0) {
        void* esi = this->field_c0;
        if (_InterlockedExchangeAdd((volatile long*)((char*)esi + 4), -1) == 1) {
            void* edx = *(void**)esi;
            void* eax = *(void**)((char*)edx + 4);
            ((void (__thiscall*)(void*))eax)(esi);
            if (_InterlockedExchangeAdd((volatile long*)((char*)esi + 8), -1) == 1) {
                void* eax2 = *(void**)esi;
                void* edx2 = *(void**)((char*)eax2 + 8);
                ((void (__thiscall*)(void*))edx2)(esi);
            }
        }
    }
}
