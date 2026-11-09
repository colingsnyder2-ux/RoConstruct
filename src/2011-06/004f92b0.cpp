// from server: 33% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __cdecl operator_delete(void*);

struct RefCounted {
    void* vptr;
    long refcount;
};

struct JobBase {
    void* vptr;
    long refcount;
};

struct SendDataJob;

struct JobHolder {
    void* vptr;
    long refcount;
};

struct SendDataJob {
    void* vptr;
    long refcount;
    char pad[0x30];
};

struct SendDataJobBig {
    void* vptr;
    long refcount;
    char pad[0x7c];
};

struct Replicator {
    char pad0[0x10d8];
    void* jobPtr;
    void* jobPtr2;
};

extern "C" void* __cdecl sub_80a05e(unsigned int size);
extern "C" void __cdecl sub_4f84b0(void* a, void* b);
extern "C" void __cdecl sub_4f8430(void* a, void* b);
extern "C" void __cdecl sub_4e82a0(void* a, void* b);
extern "C" void* __cdecl sub_51b780(void* self, void* a, void* b);
extern "C" void* __cdecl sub_51b100(void* self, void* a, void* b);

void __stdcall Replicator_SendDataJob(Replicator* self, int type, void* arg)
{
    if (type == 0) {
        SendDataJobBig* job = (SendDataJobBig*)sub_80a05e(0x84);
        if (job) {
            sub_51b100(job, self, arg);
        } else {
            job = 0;
        }
        sub_4f8430((char*)self + 0x10d8, job);
    } else if (type == 1) {
        SendDataJob* job = (SendDataJob*)sub_80a05e(0x38);
        if (job) {
            sub_51b780(job, self, arg);
        } else {
            job = 0;
        }
        sub_4f84b0((char*)self + 0x10d8, job);
    }

    void* p = *(void**)((char*)self + 0x10d8);
    void* q = *(void**)((char*)self + 0x10dc);
    void* local[2];
    local[0] = p;
    local[1] = q;
    if (q) {
        _InterlockedExchangeAdd((volatile long*)((char*)q + 4), 1);
    }
    sub_4e82a0(local, 0);
}
