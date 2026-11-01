// from server: 100% by EspClaude
// from server: 79% by king_originala_sol_native
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD


#include <vector>

extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)

struct Counted {
    void* vtable;
    volatile long use_count;
};

struct Shared {
    void* px;
    Counted* pn;
    Shared(const Shared& o) : px(o.px), pn(o.pn) { if (pn) _InterlockedIncrement(&pn->use_count); }
    ~Shared() throw();
};

struct Payload {
    Shared first;
    Shared second;
    ~Payload() throw();
};

struct Entry {
    void* vtable;
    void* key;
    unsigned long unused[2];
    Payload payload;
    void setSelected(bool) throw();
    void* getKey() const { return key; }
};

struct FilteredListener {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual bool accept(void* key, const Payload& value, void* entryKey, const Payload& entryValue) throw();

    std::vector<Entry*> entries;

    void add(void* key, Payload value) throw();
    void onEvent(void* key, Payload value) throw();
};

void FilteredListener::onEvent(void* key, Payload value) throw()
{
        for (std::vector<Entry*>::iterator it = entries.begin(); it != entries.end(); ++it) {
        if (accept(key, value, (*it)->getKey(), (*it)->payload)) {
            if ((*it)->key != key)
                (*it)->setSelected(false);
            return;
        }
    }
    add(key, value);
}
