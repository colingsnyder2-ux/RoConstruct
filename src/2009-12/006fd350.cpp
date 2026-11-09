// from server: 25% by atomic.potato
struct SpawnerService {
    char pad0[0x1c];
    void* field_1c;
    void construct(void* a, void* b, void* c, void* d, void* e, void* f);
};

extern "C" void* __cdecl sub_651050(void*, void*);
extern "C" void __cdecl sub_409630(void*, void*);
extern "C" void* __cdecl sub_7f385a(void*);
extern "C" void* __cdecl sub_7f3860(unsigned int);

void SpawnerService::construct(void* a, void* b, void* c, void* d, void* e, void* f)
{
    void* v = sub_651050(a, b);
    sub_409630(this, v);
    sub_7f385a(0);
    void* p = sub_7f3860(0x20);
    *(int*)this = 0x99ff9c;
    if (p != 0) {
        *(int*)p = 0x9dd27c;
        *((void**)p + 1) = this;
        *((void**)p + 2) = c;
        *((void**)p + 3) = d;
        *((void**)p + 4) = 0;
        *((void**)p + 5) = 0;
        *((void**)p + 6) = 0;
    } else {
        p = 0;
    }
    void* old = this->field_1c;
    if (p != old) {
        sub_7f385a(old);
    }
    this->field_1c = p;
}
