// from server: 35% by colin
struct FuncDescBase {
    void declareSignature();
};

struct BoundFuncDesc : FuncDescBase {
    void* function;
    void construct(void* arg, void* arg2, void* arg3, void* arg4, void* arg5, void* arg6, void* arg7, void* arg8, void* arg9, void* arg10, void* arg11);
};

void BoundFuncDesc::construct(void* arg, void* arg2, void* arg3, void* arg4, void* arg5, void* arg6, void* arg7, void* arg8, void* arg9, void* arg10, void* arg11)
{
    struct Local {
        void* p0;
        void* p1;
        void* p2;
        void* p3;
        void* p4;
        void* p5;
        void* p6;
        void* p7;
        void* p8;
        void* p9;
    } local;

    local.p0 = arg;
    local.p2 = 0;

    if (arg2) {
        local.p2 = arg2;
        void** vt = *(void***)arg2;
        if (vt) {
            void (*fn)(void*, void*, int) = (void (*)(void*, void*, int))vt[0];
            fn((char*)&local + 16, &local, 2);
        }
    }

    this->declareSignature();
}
