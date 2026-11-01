// from server: 100% by king_originala
typedef void (__cdecl *Callback)(void *, void *, int);

struct CallbackTable {
    Callback callback;
};

struct S {
    unsigned long unused[2];
    CallbackTable *table;
    unsigned long reserved;
    unsigned char data[24];
    unsigned long references;
};

extern void __cdecl release(void *);

unsigned long __stdcall function(S *p)
{
    unsigned long result = --p->references;
    if (result == 0) {
        if (p->table) {
            Callback callback = p->table->callback;
            void *data = p->data;
            if (callback)
                callback(data, data, 1);
            p->table = 0;
        }
        release(p);
        result = 0;
    }
    return result;
}
