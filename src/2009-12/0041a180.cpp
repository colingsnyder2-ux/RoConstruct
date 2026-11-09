// from server: 62% by atomic.potato
typedef void (*Callback)(void);
typedef void (__cdecl *Invoke)(const char *, Callback, int);

extern "C" void __cdecl sub_401630(const char *, Callback, int);
extern "C" void __cdecl sub_443ee0(void *);

struct CInsertObjectDialog
{
    void f();
};

void CInsertObjectDialog::f()
{
    sub_401630("tUVW", (Callback)0x41a130, 0);
    sub_443ee0((void *)0xb7a20c);
}
