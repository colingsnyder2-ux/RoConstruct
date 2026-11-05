// from server: 40% by atomic.potato
struct Cache {
    char pad0[0x94];
    char field94[0x14];
    char padA8[0x4];
    char fieldAC[0x4];
    char padB0[0x8];
    char fieldB8[0x4];

    bool func(int a, int b, int c);
};

extern "C" void __stdcall sub_514060(void*);
extern "C" void* __stdcall sub_512880(void*, void*, void*);
extern "C" void* __stdcall sub_6a1db0(void*);
extern "C" void __stdcall sub_4ecfd0(void*, void*, void*, void*);
extern "C" void __stdcall sub_511fa0(void*);

bool Cache::func(int a, int b, int c)
{
    char local0[0x18];
    void* p;
    void* q;
    int idx;
    int val;
    int* arr;
    int cnt;
    int i;
    void* obj;
    int* e;
    int n;
    char flag;

    sub_514060(&this->fieldB8);
    flag = 0;
    p = &this->fieldB8;
    q = 0;
    sub_512880(&this->field94, &q, &p);
    e = (int*)q;
    idx = *(int*)((char*)this + 0xac);
    val = e[1];
    arr = (int*)*(int*)((char*)this + 0xa8);
    if (val == arr[idx]) {
        goto fail;
    }
    if (val != 0) {
        val -= 0xc;
    } else {
        val = 0;
    }
    cnt = *(int*)(val + 4);
    n = *(int*)(cnt + (*(unsigned char*)&flag) * 4);
    if (n <= 0) {
        goto fail;
    }
    obj = sub_6a1db0((void*)q);
    if (n != *(int*)(*(int*)((char*)obj + 0xe4) + 0x40)) {
        goto fail;
    }
    i = *(int*)(cnt + (*(unsigned char*)&flag) * 8 + 8);
    sub_4ecfd0((void*)q, (void*)*(int*)i, (void*)*(int*)(i + 0xc), 0);
    if (flag) {
        sub_511fa0(p);
    }
    return true;

fail:
    if (flag) {
        sub_511fa0(p);
    }
    return false;
}
