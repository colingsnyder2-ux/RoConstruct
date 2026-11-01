// from server: 23% by colin
// from server: 32% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall _invalid_parameter_noinfo();

struct VerbBinderNode {
    VerbBinderNode* next;
    VerbBinderNode* prev;
    int refcount;
    void* data;
};

struct VerbBinderList {
    VerbBinderNode* head;
    int size;
};

struct VerbBinder {
    char pad[0x58];
    VerbBinderList list;
    char pad2[0x64 - 0x58 - 8];
    void* field64;
    void doIt(int* dataState);
};

struct RefCounted {
    int refcount;
};

struct SomeObj {
    void* vtable;
    void method1();
};

extern "C" void __stdcall sub_44F4C0();
extern "C" void __stdcall sub_4562A0();
extern "C" void __stdcall sub_40D550();
extern "C" void* __stdcall sub_564990(void*);

void VerbBinder::doIt(int* dataState)
{
    int* p = dataState;
    if (p != 0 && p != (int*)-1) {
        return;
    }
    VerbBinderNode* node;
    sub_44F4C0();
    node = *(VerbBinderNode**)0;
    if (node != 0 && node != (VerbBinderNode*)&list) {
        _invalid_parameter_noinfo();
    }
    VerbBinderNode* cur = node;
    if (cur == 0) {
        _invalid_parameter_noinfo();
    }
    if (cur->data == 0) {
        return;
    }
    sub_4562A0();
    RefCounted* rc = (RefCounted*)cur->data;
    if (rc != 0) {
        _InterlockedExchangeAdd((volatile long*)&rc->refcount, 1);
    }
    sub_40D550();
    if (cur == 0) {
        _invalid_parameter_noinfo();
    }
    void* obj = cur->data;
    if (this != 0 && &field64 != 0) {
        void* r = sub_564990(obj);
        if (r != 0) {
            if (dataState == 0) {
                SomeObj* s = (SomeObj*)cur->data;
                if (s != 0) {
                    s = (SomeObj*)((char*)s + 0x160);
                } else {
                    s = 0;
                }
                void** vt = *(void***)r;
                void (*fn)(void*, SomeObj*) = (void (*)(void*, SomeObj*))vt[4];
                fn(r, s);
            }
        }
    }
}
