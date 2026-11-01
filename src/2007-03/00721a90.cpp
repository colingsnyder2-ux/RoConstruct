// from server: 100% by tester
struct CXTWindowMap {
    void* Find(int);
    void Remove(int);
};

void CXTWindowMap::Remove(int key) {
    void* p;
    while ((p = Find(key)) != 0) {
        void** vtbl = *(void***)p;
        ((void (__thiscall*)(void*, int))vtbl[7])(p, 0);
    }
}
