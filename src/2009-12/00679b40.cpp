// from server: 43% by atomic.potato
struct VModelInstance {
    char pad0[0x98];
    unsigned char flag98;
    char pad1[0x9c - 0x99];
    int field9c;
    int fielda0;
    int fielda4;
    char pad2[0xc];
    int fieldb4;
    int fieldb8;
    int fieldbc;
    VModelInstance *FilteredSelection();
};

extern "C" void __stdcall sub_637e60();
extern "C" void *__stdcall sub_7f3860(int);
extern "C" void __stdcall sub_636ac0(void *);
extern "C" void __stdcall sub_98b6f4(void *, const char *);
extern "C" void __stdcall sub_98b6e4(void *);

VModelInstance *VModelInstance::FilteredSelection()
{
    sub_637e60();
    this->flag98 = 1;
    *(int *)((char *)this + 0x00) = 0x9cfd44;
    *(int *)((char *)this + 0x04) = 0x9cfd38;
    *(int *)((char *)this + 0x18) = 0x9cfd2c;
    *(int *)((char *)this + 0x1c) = 0x9cfd24;
    *(int *)((char *)this + 0x94) = 0x9cfd1c;
    this->field9c = 0;
    this->fielda0 = 0;
    void *p = sub_7f3860(4);
    if (p != 0) {
        *(void **)p = (char *)this + 0xa4;
    } else {
        p = 0;
    }
    *(void **)((char *)this + 0xa4) = p;
    *(int *)((char *)this + 0xb0) = 0;
    *(int *)((char *)this + 0xb4) = 0;
    *(int *)((char *)this + 0xb8) = 0;
    char buf[0x18];
    sub_98b6f4(buf, "FilteredSelection");
    sub_636ac0((char *)this + 0xa4);
    sub_98b6e4(buf);
    return this;
}
