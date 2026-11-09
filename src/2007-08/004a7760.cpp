// from server: 100% by colin
struct JointsService {
    char pad[0xe8];
    int field_e8;
    int field_ec;
    void* destroy(int);
};

extern "C" void __cdecl sub_5402b0();
extern "C" void (__cdecl *free)(void*);

void* JointsService::destroy(int flag)
{
    int* p;
    if (this) {
        p = (int*)((char*)this + 0xec);
    } else {
        p = 0;
    }
    *p = 0x79d214;
    if (this) {
        p = (int*)((char*)this + 0xe8);
    } else {
        p = 0;
    }
    *p = 0x79d208;
    sub_5402b0();
    if (flag & 1) {
        free(this);
    }
    return this;
}
