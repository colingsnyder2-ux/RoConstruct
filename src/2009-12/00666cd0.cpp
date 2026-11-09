// from server: 66% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __cdecl boost_get_tss_data(const void*);
extern "C" void __cdecl boost_set_tss_data(const void*, void*, void*, bool);

extern "C" void* __cdecl sub_7f3860(unsigned int);

struct sp_counted_base {
    long use_count_;
    long weak_count_;
};

struct shared_ptr_holder {
    void* px;
    sp_counted_base* pn;
};

struct VThreadLogManager {
    void* key;
    void* cleanup;
    void set_tss_data(void* p);
};

void VThreadLogManager::set_tss_data(void* p)
{
    void* mem = sub_7f3860(4);
    void* newval;
    if (mem) {
        *(void**)mem = p;
        newval = mem;
    } else {
        newval = 0;
    }

    void* old = boost_get_tss_data(key);
    if (old != newval) {
        shared_ptr_holder sp;
        sp.px = *(void**)this;
        sp.pn = *(sp_counted_base**)((char*)this + 4);
        if (sp.pn) {
            _InterlockedExchangeAdd(&sp.pn->use_count_, 1);
        }
        boost_set_tss_data(key, &sp, newval, true);
    }
}
