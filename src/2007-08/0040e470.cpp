// from server: 30% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall _invalid_parameter_noinfo();

struct VPlayerCreator {
    char pad0[4];
    void* begin;
    void* end;
    void insert(void* pos, void* first, void* last);
    void assign(void* pos, unsigned int count, void* val);
    void erase(void* first, void* last);
};

struct RefCounted {
    long refcount;
    long weakrefcount;
    virtual void destroy();
    virtual void deleteThis();
};

void VPlayerCreator::insert(void* pos, void* first, void* last) {
}

void VPlayerCreator::assign(void* pos, unsigned int count, void* val) {
}

void VPlayerCreator::erase(void* first, void* last) {
}

void VPlayerCreator_ctor(VPlayerCreator* self, void* arg1, void* arg2, void* arg3) {
    void* p = self->begin;
    unsigned int count = 0;
    if (p != 0) {
        count = ((char*)self->end - (char*)p) >> 3;
    }
    unsigned int idx = (unsigned int)arg1;
    if (count < idx) {
        unsigned int oldCount = 0;
        if (p != 0) {
            oldCount = ((char*)self->end - (char*)p) >> 3;
        }
        void* e = self->end;
        if (p > e) {
            _invalid_parameter_noinfo();
        }
        self->insert((void*)0, (void*)(idx - oldCount), e);
    } else {
        if (p != 0) {
            unsigned int curCount = ((char*)self->end - (char*)p) >> 3;
            if (idx < curCount) {
                void* e = self->end;
                if (p > e) {
                    _invalid_parameter_noinfo();
                }
                void* b = self->begin;
                if (b > self->end) {
                    _invalid_parameter_noinfo();
                }
                void* newEnd = (char*)b + idx * 8;
                if (newEnd > self->end || newEnd < self->begin) {
                    _invalid_parameter_noinfo();
                }
                self->erase(newEnd, e);
            }
        }
    }
    RefCounted* rc = (RefCounted*)arg3;
    if (rc != 0) {
        if (_InterlockedExchangeAdd(&rc->refcount, -1) == 1) {
            rc->destroy();
            if (_InterlockedExchangeAdd(&rc->weakrefcount, -1) == 1) {
                rc->deleteThis();
            }
        }
    }
}
