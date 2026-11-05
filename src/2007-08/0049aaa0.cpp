// from server: 37% by colin
extern "C" {
    int __stdcall _invalid_parameter_noinfo();
}

struct VClientSignalDesc {
    char pad[0x130];
    void* vecBegin;
    void* vecEnd;
    void* vecCap;

    VClientSignalDesc* addSignal(int a2);
};

extern void* g_8be4d4;
extern void* g_8bdfa0;
extern unsigned char g_8be4d8;
extern unsigned int g_8be4dc;

void __stdcall sub_725520(void*, void*);
int __cdecl sub_4995c0();
void __stdcall sub_40e470(void*, int, void*, void*);
void* __cdecl sub_491790();
int __cdecl sub_52cb30();
void __stdcall sub_554de0(void*, void*, void*);
void __stdcall sub_492360(void*);
void __stdcall sub_402a60(void*, void*);

VClientSignalDesc* VClientSignalDesc::addSignal(int a2)
{
    sub_725520(&g_8be4d4, (void*)0x499830);
    int n = sub_4995c0();
    int idx = n + 1;

    void* begin = this->vecBegin;
    void* end = this->vecEnd;
    unsigned int count;
    if (begin == 0) {
        count = 0;
    } else {
        count = ((char*)end - (char*)begin) >> 3;
    }

    if ((unsigned int)idx > count) {
        void* tmp[2];
        tmp[0] = 0;
        tmp[1] = 0;
        sub_40e470(&this->vecBegin, idx, tmp, tmp);
    } else {
        if (begin == 0 || (unsigned int)n >= count) {
            _invalid_parameter_noinfo();
        }
        void* slot = (char*)this->vecBegin + n * 8;
        if (slot != 0) {
            return this;
        }
    }

    if ((g_8be4dc & 1) == 0) {
        g_8be4dc |= 1;
        sub_725520(&g_8bdfa0, (void*)0x492070);
        void* p = sub_491790();
        int q = sub_52cb30();
        g_8be4d8 = (p == (void*)q) ? 1 : 0;
    }

    if (g_8be4d8 == 0) {
        sub_725520(&g_8bdfa0, (void*)0x492070);
        void* p = sub_491790();
        void* local;
        sub_554de0(this, &local, p);
        if (local != 0) {
            void* slot = (char*)this->vecBegin + n * 8;
            *(void**)slot = local;
            sub_402a60((char*)slot + 4, &local);
            sub_492360(&local);
            return this;
        }
        sub_492360(&local);
    }

    return 0;
}
