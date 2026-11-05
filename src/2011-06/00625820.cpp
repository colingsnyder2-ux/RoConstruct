// from server: 37% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __cdecl malloc(unsigned int);

struct VInstance {
    void addChild(void*);
};

struct Child {
    char pad0[8];
    void* vfptr8;
    char padC[4];
    void* vfptr10;
    void* owner;
    char pad18[4];
    int a18;
    int a1c;
    int a20;
    int a24;
};

struct RefCounted {
    short refcount;
    short pad2;
};

void VInstance_addChild(VInstance* self, void* child);

void VInstance::addChild(void* child) {
    Child* c = (Child*)child;
    c->owner = this;
    VInstance_addChild(this, child);
}

void* __fastcall makeChild(VInstance* self, void* unused, void* arg) {
    Child* c = (Child*)malloc(0x2c);
    if (c) {
        *(short*)c = 0;
        *(short*)((char*)c + 2) = 1;
    }
    c = (Child*)((char*)c + 4);
    if (c) {
        c->vfptr8 = (void*)0xa8c688;
        *(int*)((char*)c + 0xc) = 0;
        *(void**)c = (void*)0xa94a4c;
        c->vfptr8 = (void*)0xa94a44;
        c->owner = self;
        int* src = (int*)arg;
        c->a18 = src[0];
        c->a1c = src[1];
        c->a20 = src[2];
        c->a24 = src[3];
        *(void**)c = (void*)0xa94b0c;
        c->vfptr8 = (void*)0xa94b04;
    }
    VInstance_addChild(self, c);
    *(void**)arg = c;
    if (c) {
        RefCounted* rc = (RefCounted*)((char*)c + 5);
        if (rc) {
            rc = (RefCounted*)((char*)rc - 5);
        } else {
            rc = 0;
        }
        rc = (RefCounted*)((char*)rc - 2);
        _InterlockedExchangeAdd((volatile long*)rc, 1);
    }
    return arg;
}
