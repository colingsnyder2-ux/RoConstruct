// from server: 34% by atomic.potato
extern "C" void* __cdecl malloc(unsigned int);
extern "C" void __cdecl free(void*);
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
extern "C" void* __cdecl memset(void*, int, unsigned int);

extern "C" int __cdecl sub_520D30(void*, void*, int, int);
extern "C" void __cdecl sub_520F70(void*, int, void*, int);
extern "C" void __cdecl sub_5210D0(void*, void*, int, int);
extern "C" void __cdecl sub_5216A0(void*, void*, int, void*);
extern "C" void __cdecl sub_521B20(void*, void*, int, void*, int, void*);
extern "C" void __cdecl sub_522820(void*, void*, int, void*, void*, void*, void*, void*);

struct CSHA1
{
    void __cdecl Transform(
        unsigned int* state,
        unsigned char* buffer,
        unsigned int* workspace,
        unsigned int* temp,
        unsigned int* block,
        unsigned int* out,
        unsigned int* scratch,
        unsigned int count);
};

void CSHA1::Transform(
    unsigned int* state,
    unsigned char* buffer,
    unsigned int* workspace,
    unsigned int* temp,
    unsigned int* block,
    unsigned int* out,
    unsigned int* scratch,
    unsigned int count)
{
    unsigned int* a = (unsigned int*)malloc(count * 4);
    sub_522820(state, buffer, count, workspace, temp, block, out, scratch);
    unsigned int* b = (unsigned int*)malloc(count * 4);
    sub_522820(state, buffer, count, workspace, temp, block, out, scratch);
    unsigned int* c = (unsigned int*)malloc(count * 8);
    unsigned int* d = (unsigned int*)malloc(count * 4);
    if (sub_520D30(workspace, a, count, count))
    {
        memcpy(d, workspace, count * 4);
        memset(d + count, 0, 0);
        sub_5210D0(d, a, count, count);
        sub_5216A0(d, a, count, out);
        sub_521B20(d, d, count * 2, out, count, a);
        memcpy(d, out, count * 4);
        memset(d + count, 0, 0);
        sub_5210D0(d, a, count, count);
    }
    else
    {
        sub_5210D0(a, workspace, count, count);
        sub_5216A0(a, d, count, out);
        sub_521B20(a, a, count * 2, out, count, d);
    }
    sub_5216A0(a, scratch, count, out);
    sub_520F70(out, count * 2, a, count);
    free(a);
    free(b);
    free(c);
    free(d);
}
