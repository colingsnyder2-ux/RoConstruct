// from server: 20% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall _invalid_parameter_noinfo();

struct Inner {
    void* vptr;
    int field4;
    int field8;
    int fieldC;
    int field10;
};

struct CRobloxTreeCtrlNode {
    char pad[0x14];
    Inner inner14;
    char pad2[0x30 - 0x14 - sizeof(Inner)];
    void* field30;
    int method(int arg);
};

extern "C" void __cdecl sub_444B70(void* out);
extern "C" void* __cdecl sub_442C60(void* a, void* b, int c);
extern "C" int __cdecl sub_41F6F0(void* p);
extern "C" void __cdecl sub_725750(void* p);
extern "C" void __cdecl sub_725770(void* p);
extern "C" void __cdecl sub_44F4C0(void* a, void* b, void* c);
extern "C" void __cdecl sub_492360(void* p);
extern "C" void* __cdecl sub_62FEF6(int size);
extern "C" void __cdecl sub_4A6C60(void* a, void* b, void* c);
extern "C" void* __cdecl sub_423640(void* a, void* b, void* c);

int CRobloxTreeCtrlNode::method(int arg)
{
    void* local24;
    void* local1c;
    void* local20;
    void* local30;
    void* local44;
    void* local28;
    void* local48;
    int local3c;
    int local40;

    sub_444B70(&local24);

    void* ebx = (void*)arg;
    void* eax = *(void**)ebx;
    void* eax2 = *(void**)((char*)eax + 0xc);

    local40 = 0;
    void* res = sub_442C60(local24, eax2, 1);
    if (res == 0) goto fail;

    {
        int r = sub_41F6F0(res);
        if (r < 0) goto fail;
    }

    {
        char* esi = (char*)this->field30;
        esi += 0xb0;
        sub_725750(esi);

        void* ecx = *(void**)ebx;
        local48 = ecx;

        sub_44F4C0(&this->inner14, &local20, &local48);

        void* eax3 = local1c;
        void* ecx2 = *(void**)((char*)&this->inner14 + 4);
        local30 = ecx2;

        if (eax3 != 0 && eax3 != &this->inner14) {
            _invalid_parameter_noinfo();
            eax3 = local1c;
        }

        void* edi = local20;
        if (edi != local30) {
            if (eax3 == 0) {
                _invalid_parameter_noinfo();
                eax3 = local1c;
            }
            if (edi == *(void**)((char*)eax3 + 4)) {
                _invalid_parameter_noinfo();
            }
            edi = *(void**)((char*)edi + 0x10);
            local3c = 0;
            sub_725770(esi);
            local3c = -1;
            sub_492360(&local24);
            return (int)edi;
        }

        local3c = 0;
        sub_725770(esi);

        void* mem = sub_62FEF6(0x50);
        void* esi2 = mem;
        local44 = esi2;
        local3c = 2;
        if (esi2 != 0) {
            void* edx = this->field30;
            void* tmp;
            sub_4A6C60(&tmp, ebx, edx);
            void* r2 = sub_423640(esi2, &tmp, this);
            esi2 = r2;
        } else {
            esi2 = 0;
        }

        void* vptr = *(void**)esi2;
        void* fn = *(void**)((char*)vptr + 0xc);
        local3c = 0;
        ((void (__thiscall*)(void*))fn)(esi2);

        local3c = -1;
        sub_492360(&local24);
        return (int)esi2;
    }

fail:
    {
        void* esi3 = local28;
        local3c = -1;
        if (esi3 != 0) {
            if (_InterlockedExchangeAdd((volatile long*)((char*)esi3 + 4), -1) == 1) {
                void* vptr = *(void**)esi3;
                void* fn = *(void**)((char*)vptr + 4);
                ((void (__thiscall*)(void*))fn)(esi3);
                if (_InterlockedExchangeAdd((volatile long*)((char*)esi3 + 8), -1) == 1) {
                    void* vptr2 = *(void**)esi3;
                    void* fn2 = *(void**)((char*)vptr2 + 8);
                    ((void (__thiscall*)(void*))fn2)(esi3);
                }
            }
        }
    }
    return 0;
}
