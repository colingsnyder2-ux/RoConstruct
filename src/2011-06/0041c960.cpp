// from server: 33% by atomic.potato
extern "C" int __stdcall sub_0041c6f0(const void*, const void*);

struct CVideoStream {
    char pad0[0xe8];
    int field_e8;
    int field_ec;
    int check(void* p);
};

int CVideoStream::check(void* p)
{
    if (p == 0)
        return (int)0x80004003;
    if (sub_0041c6f0((const char*)0xa5edfc, p) == 0)
        return (int)0x80070057;
    if (*(int*)((char*)p + 0x20) == 0)
        return (int)0x80070057;
    char* q = (char*)p + 0x10;
    if (q == 0)
        return (int)0x80070057;
    if (sub_0041c6f0((const char*)0xa5ee7c, q) == 0)
        return (int)0x80070057;
    int* r = *(int**)((char*)p + 0x44);
    if (r == 0)
        return (int)0x80070057;
    int a = r[0x34 / 4];
    if (a < 0x14)
        return (int)0x80070057;
    int b = r[0x38 / 4];
    if (b < 0)
        b = -b;
    if (b < 0x14)
        return (int)0x80070057;
    if (a != field_ec)
        return (int)0x80070057;
    if (b != field_e8)
        return (int)0x80070057;
    return 0;
}
