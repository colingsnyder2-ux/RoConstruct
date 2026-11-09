// from server: 100% by atomic.potato
struct S {
    void* field0;
    void* field4;
    char field8;
    S* construct(void* arg);
};

S* S::construct(void* arg)
{
    S* src = (S*)arg;
    this->field0 = src->field0;
    this->field4 = 0;
    if (src->field4 != 0) {
        void (*fn)(void*, void*) = *(void (**)(void*, void*))((char*)src->field4 + 8);
        fn((char*)src + 8, (char*)this + 8);
    }
    this->field4 = src->field4;
    return this;
}
