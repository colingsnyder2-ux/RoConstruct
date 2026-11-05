// from server: 25% by atomic.potato
struct UnifiedImageWidget;

extern "C" void* __cdecl sub_718A38(unsigned int);

struct AllocObj {
    void ctor(void*);
};

struct UnifiedImageWidget {
    void* __cdecl construct(void*);
    void construct2(void*, int);
};

void* UnifiedImageWidget::construct(void* a) {
    void* mem = sub_718A38(0xa8);
    void* obj = 0;
    if (mem) {
        ((AllocObj*)mem)->ctor(a);
        obj = mem;
    }
    ((UnifiedImageWidget*)this)->construct2(obj, 0);
    return this;
}
