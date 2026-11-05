// from server: 38% by atomic.potato
struct VCEvent {
    char pad0[0x88];
    char field88[0x10];
    char pad98[0x20];
    double fieldb8;
    void sub_7e5d40(void*);
    void* sub_7e5bf0(void*, void*, void*);
    virtual void* vf4(void*, void*);
    void func();
};

void VCEvent::func()
{
    char buf[0x28];
    sub_7e5d40(buf);
    double d0 = 0.0;
    double d1 = 0.0;
    int a = *(int*)(buf + 0);
    int b = *(int*)(buf + 4);
    *(int*)(buf + 8) = a;
    *(int*)(buf + 12) = b;
    void* p = sub_7e5bf0(this + 0x88, buf + 8, buf + 0x18);
    int c = *(int*)p;
    int d = *(int*)((char*)p + 4);
    *(int*)(buf + 0x24) = c;
    *(int*)(buf + 0x20) = d;
    int e = *(int*)((char*)this + 0x98);
    int f = *(int*)((char*)this + 0x9c);
    *(int*)(buf + 0x1c) = e;
    *(int*)(buf + 0x20) = f;
    void* r = vf4(buf + 0x14, buf + 0x10);
    double result = *(double*)r + d0;
    *(double*)((char*)this + 0xb8) = result;
}
