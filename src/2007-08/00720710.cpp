// from server: 100% by colin
struct CXTWindowMap {
    void* sub_720540(void*);
    void* sub_7389b8(void*);
    void Insert(void*, void*);
};

extern "C" {
    long (__stdcall *GetWindowLongA)(void*, int);
    long (__stdcall *SetWindowLongA)(void*, int, long);
}

void CXTWindowMap::Insert(void* a, void* b)
{
    void* p = sub_720540(a);
    *(void**)((char*)b + 0xc) = p;
    void* q = sub_7389b8(a);
    *(void**)q = b;
    void* r = *(void**)((char*)b + 0xc);
    if (r == 0) {
        long v = GetWindowLongA(a, -4);
        *(long*)((char*)b + 8) = v;
        SetWindowLongA(a, -4, (long)0x720670);
    } else {
        *(void**)((char*)b + 8) = *(void**)((char*)r + 8);
    }
}
