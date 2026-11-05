// from server: 100% by colin
struct CXTPResourceManager {
    void sub_71f8d0(unsigned short);
    void sub_71fbb0();
};

extern "C" void* __cdecl sub_71f260();
extern "C" unsigned short __cdecl sub_71faa0(void*);

void CXTPResourceManager::sub_71fbb0() {
    void* p = sub_71f260();
    unsigned short v = sub_71faa0(p);
    sub_71f8d0(v);
}
