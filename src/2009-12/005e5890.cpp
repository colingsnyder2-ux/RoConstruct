// from server: 33% by atomic.potato
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);

void* __cdecl operator_new(unsigned int);
void __cdecl operator_delete(void*);

struct S {
    void* vtable;
    char pad0[8];
    void* fieldC;
    char pad10[0x74];
    int field84;
    void construct(int depth, int a, int b);
};

void __stdcall sub_4e1e00();
void* __stdcall sub_7f3860(unsigned int size);
void __stdcall sub_4e3040(void* p, int a, void* b);
void __stdcall sub_4e4990(void* p, void* q);
void __stdcall sub_5c1a10(void* p, void* q, void* r);
void __stdcall sub_5c48d0(void* p, int a, float* b, int* c, int* d);
void __stdcall sub_44b020(void* p);

void S::construct(int depth, int a, int b)
{
    sub_4e1e00();
    this->vtable = (void*)0x9c1874;
    this->field84 = depth;
    void* mem = sub_7f3860(0x24);
    if (mem) {
        sub_4e3040(mem, 5, this);
    } else {
        mem = 0;
    }
    void* local = 0;
    if (mem) {
        local = mem;
        InterlockedIncrement((long*)((char*)mem + 4));
    }
    sub_4e4990(&this->fieldC, &local);
    void* p;
    if (local) {
        p = (char*)local + 0xc;
    } else {
        p = 0;
    }
    sub_5c1a10((char*)this + 0x18, p, (void*)a);
    float f = 0.0f;
    int one = 1;
    sub_5c48d0((char*)this + 0x18, b, &f, &one, &one);
    if (local) {
        if (InterlockedDecrement((long*)((char*)local + 4)) == 0) {
            sub_44b020(local);
            (*(void(**)(void*, int))local)(local, 1);
        }
    }
}
