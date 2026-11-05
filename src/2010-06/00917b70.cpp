// from server: 15% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __stdcall sub_7A79A0(unsigned int);
extern "C" void* __stdcall sub_9EA3F0();
extern "C" void* __stdcall sub_9EA380();
extern "C" void* __stdcall sub_9EA37C();

struct GfxAttachement {
    char pad0[0x20];
    char pad20[0x20];
    void sub_41FBE0();
    void sub_4B3280(void*);
};

struct Holder {
    void* ptr;
    void* ptr2;
};

void* __stdcall sub_9186F0(void*, void*, void*, void*);
void __stdcall sub_41B190(void*, void*);
void __stdcall sub_4545B0(void*, void*, void*);
void __stdcall sub_7954F0(void*, void*);
void __stdcall sub_795540(void*);
void __stdcall sub_41B220(void*);
void __stdcall sub_6DA340(void*);
void __stdcall sub_401A30(void*);

void GfxAttachement::sub_41FBE0() {}
void GfxAttachement::sub_4B3280(void*) {}

void* __stdcall sub_9186F0(void* a, void* b, void* c, void* d) { return 0; }
void __stdcall sub_41B190(void* a, void* b) {}
void __stdcall sub_4545B0(void* a, void* b, void* c) {}
void __stdcall sub_7954F0(void* a, void* b) {}
void __stdcall sub_795540(void* a) {}
void __stdcall sub_41B220(void* a) {}
void __stdcall sub_6DA340(void* a) {}
void __stdcall sub_401A30(void* a) {}

void __stdcall sub_917B70(GfxAttachement* self, void* out, void* a, void* b)
{
    void* v = sub_7A79A0(0x48);
    void* obj = 0;
    if (v) {
        obj = sub_9186F0(v, a, b, sub_9EA3F0());
    }
    void* local1 = obj;
    void* local2 = obj;
    sub_41B190(&local2, obj);
    sub_4545B0(&local2, obj, obj);
    self->sub_41FBE0();
    char buf[0x38];
    sub_7954F0(buf, (char*)self + 0x20);
    self->sub_4B3280(&local1);
    sub_795540(buf);
    sub_9EA380();
    Holder h;
    h.ptr = local1;
    h.ptr2 = local2;
    if (h.ptr2) {
        _InterlockedExchangeAdd((volatile long*)((char*)h.ptr2 + 4), 1);
    }
    void* tmp;
    sub_41B220(&tmp);
    void* r = tmp;
    sub_9EA380();
    *(void**)out = *(void**)r;
    void* out2 = (char*)out + 4;
    *(void**)out2 = *((void**)r + 1);
    if (*(void**)out2) {
        _InterlockedExchangeAdd((volatile long*)(*(char**)out2 + 8), 1);
    }
    sub_6DA340(&tmp);
    sub_9EA37C();
    if (local2) {
        sub_401A30(local2);
    }
}
