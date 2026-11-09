// from server: 42% by atomic.potato
struct RbxCluster {
    void construct(void*);
};

extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __cdecl operator_delete(void*);
extern "C" void __cdecl sub_48A090(void*, void*);

void RbxCluster::construct(void* arg) {
    char* p = (char*)operator_new(0x1c);
    if (p) {
        *(void**)(p + 8) = (void*)0xb5ba80;
        *(int*)(p + 0xc) = 0;
        *(void**)p = (void*)0xb6ede4;
        *(void**)(p + 8) = (void*)0xb6eddc;
        *(void**)(p + 0x10) = this;
        *(int*)(p + 0x14) = *(int*)arg;
        *(int*)(p + 0x18) = *(int*)((char*)arg + 4);
        *(void**)p = (void*)0xb6ee54;
        *(void**)(p + 8) = (void*)0xb6ee4c;
    }
    sub_48A090(this, p);
    *(void**)arg = p;
    if (p) {
        operator_delete(p + 5);
    }
}
