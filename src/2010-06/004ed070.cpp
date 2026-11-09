// from server: 32% by atomic.potato
struct Replicator {
    char pad0[0x20];
    int entries[0x80][2];
    char pad1[0x20];
    int count;

    int NewInstanceItem(int a, int b);
};

extern "C" void __stdcall sub_4DD450(int, int, void*);
extern "C" void __stdcall sub_4E1F60(void*, int, int);
extern "C" void __stdcall sub_4EBFA0(void*, void*, void*);
extern "C" void __stdcall sub_4EC090(void*, void*);
extern "C" void __stdcall sub_9EA90C();

int Replicator::NewInstanceItem(int a, int b) {
    int* p = (int*)a;
    if (p[0] == -1 && *(unsigned short*)(p + 1) == 0xffff) {
        char tmp = 0;
        sub_4DD450(1, 8, &tmp);
        return 0;
    }
    int v0 = p[0];
    int v1 = p[1];
    char flag = *(char*)((char*)this + 0x420);
    int local8 = v0;
    int localc = v1;
    char local10 = flag;
    char local1c;
    sub_4EBFA0(this, &local1c, &local8);
    if (local1c != 0) {
        int idx = *(int*)((char*)this + 0x420);
        sub_4EC090(this, (char*)this + idx * 8 + 0x20);
        int idx2 = *(int*)((char*)this + 0x420);
        *(int*)((char*)this + idx2 * 8 + 0x20) = p[0];
        *(int*)((char*)this + idx2 * 8 + 0x24) = p[1];
        char dl = *(char*)((char*)this + 0x420);
        dl |= 0x80;
        char tmp2 = dl;
        sub_4DD450(1, 8, &tmp2);
        sub_4E1F60((void*)b, p[0], p[1]);
        int idx3 = *(int*)((char*)this + 0x420);
        int rem = idx3 % 0x7f;
        *(int*)((char*)this + 0x420) = rem + 1;
        return 0;
    }
    int eax = local8;
    void* g = *(void**)0x9ea90c;
    if (eax != 0) {
        eax = *(int*)eax;
    } else {
        sub_9EA90C();
        eax = 0;
        int esi = localc;
        if (esi != *(int*)((char*)eax + 0x18)) {
            sub_9EA90C();
        }
        char cl = *(char*)(esi + 0x14);
        char tmp3 = cl;
        sub_4DD450(1, 8, &tmp3);
        return 0;
    }
    return 0;
}
