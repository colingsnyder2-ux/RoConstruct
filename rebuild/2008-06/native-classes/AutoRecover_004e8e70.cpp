// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <intrin.h>

// INFERRED: layouts reconstructed from the disassembly only; no headers were provided.
struct SpCounted {
    virtual void dispose();
    virtual void destroy();
    long use;
    long weak;
};

struct SharedCount {
    SpCounted* pi;
};

struct SlotImpl {
    char pad[0x1c];
    struct SlotData* data;
};

struct SlotData {
    int unk0;
    int unk4;
    int unk8; // non-zero when the slot is still valid
};

struct Slot {
    SlotImpl* impl; // [0]
    int unk4;
    char function[1]; // +8: the boost::function held by the slot
};

struct Connection {
    int unk0;
    void* weakPtr; // +4
    void* weakCnt; // +8
    bool blocked;  // +0xc
};

struct AnyHolder {
    virtual void destroyDeleting(int flags);
};

struct SignalOwner {
    void* impl; // [0]
};

// Callees (INFERRED conventions; see notes)
// INFERRED: 0x6a0920 is called as "push 4 ... add esp,4", i.e. cdecl operator new(4).
extern "C" void* fn_006a0920(unsigned size);
extern "C" void __fastcall fn_0042a800(SharedCount* self, int unusedEdx, int* p);
extern "C" void fn_0047d410(SharedCount* sp, int* p, int* q);
extern "C" void __fastcall fn_004b1aa0(void* self, int unusedEdx, const void* fn);
extern "C" void __fastcall fn_004915b0(Slot* self, int unusedEdx, void* sretSharedPtr);
extern "C" Connection* __fastcall fn_0056a900(void* self, int unusedEdx, Connection* ret, void* slotData, void* any, void* group);

extern "C" Connection* __fastcall fn_004e8e70(SignalOwner* self, int unusedEdx,
                                              Connection* ret, int* value,
                                              Slot* slot, int unusedArg4)
{
    SlotData* sd = slot->impl->data;
    if (sd == 0 || sd->unk8 == 0) {
        ret->weakPtr = 0;
        ret->weakCnt = 0;
        ret->blocked = false;
        return ret;
    }

    int* p = (int*)fn_006a0920(4);
    if (p)
        *p = *value;

    SharedCount sc;
    fn_0042a800(&sc, 0, p);
    SharedCount tmp;
    fn_0047d410(&tmp, p, p);

    struct { void* a; void* b; } anyStore;
    fn_004b1aa0(&anyStore, 0, slot->function);

    struct { void* p; void* c; } dataPtr;
    fn_004915b0(slot, 0, &dataPtr);

    char group[8];
    Connection* r = fn_0056a900(self->impl, 0, ret, dataPtr.p, &anyStore, group);

    AnyHolder* h = (AnyHolder*)anyStore.a;
    if (h)
        h->destroyDeleting(1);

    SpCounted* pi = sc.pi;
    if (pi) {
        if (_InterlockedDecrement(&pi->use) == 0) {
            pi->dispose();
            if (_InterlockedDecrement(&pi->weak) == 0)
                pi->destroy();
        }
    }
    return r;
}
