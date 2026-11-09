// from server: 37% by atomic.potato
extern "C" void* __stdcall make_desc_005b66b0(const char*, int);
extern "C" void __stdcall func_006e7050(void*);

struct S {
    char pad0[0x20];
    void* field20;
    void ctor(int);
};

void S::ctor(int a) {
    func_006e7050(&a);
    *(void**)((char*)this + 0x00) = (void*)0xa4ab94;
    *(void**)((char*)this + 0x04) = (void*)0xa4ab88;
    *(void**)((char*)this + 0x18) = (void*)0xa4ab7c;
    *(void**)((char*)this + 0x1c) = (void*)0xa4ab70;
    *(void**)((char*)this + 0x94) = (void*)0xa4ab60;
    *(void**)((char*)this + 0x98) = (void*)0xa4ab48;
    field20 = make_desc_005b66b0((const char*)0, 0);
    ++*(int*)0xc1852c;
}
