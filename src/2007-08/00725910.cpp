// from server: 53% by colin
extern "C" __declspec(dllimport) void __stdcall _invalid_parameter_noinfo();

extern "C" void __fastcall sub_725750(void*);
extern "C" void __fastcall sub_725770(void*);
extern "C" unsigned int __fastcall sub_55e610(void*);
extern "C" void __fastcall sub_413c00(void*);
extern "C" void __cdecl sub_414170(void*);

extern void* g_8c98f0;

struct boost_thread_resource_error {
    void __fastcall destroy();
};

void __fastcall boost_thread_resource_error::destroy()
{
    int* self = (int*)this;
    int count = sub_55e610(self);
    int i = 0;
    if (count > 0) {
        do {
            void* p = g_8c98f0;
            sub_725750(p);
            int* begin = (int*)self[1];
            int* end = (int*)self[2];
            if (begin == 0 || (unsigned)(i) >= (unsigned)((end - begin) >> 2)) {
                _invalid_parameter_noinfo();
            }
            void* q = g_8c98f0;
            int* qb = (int*)((char*)q + 0xc);
            int* qbegin = (int*)*qb;
            int* qend = (int*)((char*)q + 0x10);
            if (qbegin == 0 || (unsigned)(i) >= (unsigned)((*qend - (int)qbegin) >> 2)) {
                _invalid_parameter_noinfo();
            }
            int* slot = (int*)((char*)qbegin + i * 4);
            int* entry = (int*)*slot;
            if (*entry != 0) {
                int a = begin[i];
                int b = entry[1];
                int c = entry[2];
                ((void (__cdecl*)(int, int))c)(b, a);
            }
            int* b2 = (int*)self[1];
            int* e2 = (int*)self[2];
            if (b2 == 0 || (unsigned)(i) >= (unsigned)((e2 - b2) >> 2)) {
                _invalid_parameter_noinfo();
            }
            b2[i] = 0;
            sub_725770(p);
            i++;
        } while (i < sub_55e610(self));
    }
}
