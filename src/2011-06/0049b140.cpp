// from server: 74% by atomic.potato
struct VideoControl
{
    int pad0[67];
    void* field10c;
    int pad1[2];
    void* field118;
    void f();
};

extern void G1_func_587f70(void*);

void VideoControl::f()
{
    *(char*)((char*)this + 4) = 1;
    void** object = (void**)field10c;
    ((void (__fastcall *)(void*))((void**)object)[1])(object);
    G1_func_587f70(field118);
}
