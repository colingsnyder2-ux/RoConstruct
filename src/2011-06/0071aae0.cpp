// from server: 41% by atomic.potato




struct Vec3 {
    int x;
    int y;
    int z;
};

struct SelectionPointLasso {
    char pad[0x10];
    void* fn;
    void* ctx;
    void GetSetImpl(void* a, Vec3* v);
};

void SelectionPointLasso::GetSetImpl(void* a, Vec3* v) {
    char* base;
    if (a) {
        base = (char*)a - 0x1c;
    } else {
        base = 0;
    }
    Vec3 tmp;
    tmp.x = v->x;
    tmp.y = v->y;
    tmp.z = v->z;
    void* fn = this->fn;
    void* ctx = this->ctx;
    ((void (__stdcall*)(void*, Vec3*, char*))fn)(ctx, &tmp, base);
}
