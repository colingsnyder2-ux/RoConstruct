// from server: 76% by colin
struct RBX_ClearBackpack {
    int field_0x0;
    int field_0x4;
    int field_0x8;
    int field_0xc;
    bool method();
};

extern "C" void* __cdecl sub_495820(int);
extern "C" void* __cdecl sub_4887E0(void*);

bool RBX_ClearBackpack::method()
{
    void* p = sub_495820(field_0xc);
    if (!p)
        return false;
    void* q = sub_4887E0(p);
    if (!q)
        return false;
    int* r = *(int**)((char*)q + 0xc0);
    if (r) {
        int start = r[1];
        if (start) {
            int end = r[2];
            int count = (end - start) >> 3;
            return count != 0;
        }
    }
    return false;
}
