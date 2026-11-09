// from server: 100% by atomic.potato
struct X_006d9d70 {
    char pad_0[0xc0];
    void init(void* p);
    X_006d9d70* run();
};

X_006d9d70* X_006d9d70::run() {
    init((void*)0xa468c0);
    *(void**)((char*)this + 0) = (void*)0xa4686c;
    *(void**)((char*)this + 4) = (void*)0xa46864;
    *(void**)((char*)this + 0x18) = (void*)0xa46858;
    *(void**)((char*)this + 0x1c) = (void*)0xa4684c;
    *(void**)((char*)this + 0x94) = (void*)0xa4683c;
    *(void**)((char*)this + 0x98) = (void*)0xa46824;
    *(void**)((char*)this + 0xbc) = 0;
    return this;
}

X_006d9d70* func_006d9d70(X_006d9d70* x) { return x->run(); }
