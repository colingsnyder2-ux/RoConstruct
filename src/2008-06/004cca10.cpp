// from server: 100% by king_originala
void __cdecl operator delete(void *) throw();

struct Pool {
    char data[36];
    bool release(void *);
};

struct S {
    char data[12];
    Pool pool;
    int count;

    bool release(void (__cdecl *callback)(void *), unsigned int, void *);
};

bool S::release(void (__cdecl *callback)(void *), unsigned int, void *p)
{
    callback(p);
    try {
        if (!pool.release(p)) {
            operator delete(p);
            --count;
            return false;
        }
        return true;
    }
    catch (...) {
        operator delete(p);
        --count;
        throw;
    }
}
