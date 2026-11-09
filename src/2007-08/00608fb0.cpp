// from server: 58% by colin
struct Assembly {
    char pad[0x64];
    void* field64;
};

struct SimJobStage {
    char pad[0x64];
    void* field64;
    int func(Assembly* a, Assembly* b);
};

extern float g_795c00;

extern "C" {
    int __stdcall sub_5b4c90(void*);
    int __stdcall sub_5bc810(void*, int, float);
    int __stdcall sub_530100(void*);
    int __stdcall sub_5ab6b0(int, int, int);
    int __stdcall sub_6095f0(void*, void*, int, int);
    int __stdcall sub_6282a0(void*, void*, int, int);
    int __stdcall sub_6281b0(void*, void*, int, int);
    int __stdcall sub_60ad10(void*, void*, int, int);
}

int SimJobStage::func(Assembly* a, Assembly* b)
{
    int v1 = sub_5b4c90(a);
    int v2 = sub_5b4c90(b);
    if (sub_5bc810((void*)v1, v2, g_795c00))
        return 0;

    void* p1 = a->field64;
    sub_530100(p1);
    void* p2 = b->field64;
    sub_530100(p2);

    char* base = (char*)p2 + 0x84;
    int i = 0;
    do {
        int q = i / 3;
        int r = i - q * 3;
        float f0 = *(float*)((char*)p1 + r * 4 + 0x84);
        float f1 = *(float*)((char*)p1 + r * 4 + 0x90);
        float f2 = *(float*)((char*)p1 + r * 4 + 0x9c);
        float scale = (float)(1 - q * 2);
        float v0 = -f0 * scale;
        float v1 = -f1 * scale;
        float v2 = -f2 * scale;
        int tmp = sub_5ab6b0(*(int*)&v0, *(int*)&v1, *(int*)&v2);
        int res = sub_6095f0(a, (void*)tmp, i, (int)base);
        if (res != 0) break;
        res = sub_6282a0(a, (void*)tmp, i, (int)base);
        if (res != 0) break;
        res = sub_6281b0(a, (void*)tmp, i, (int)base);
        if (res != 0) break;
        res = sub_60ad10(a, (void*)tmp, i, (int)base);
        if (res != 0) break;
        i++;
    } while (i < 6);

    return 0;
}
