// from server: 33% by colin
extern "C" {
    long __stdcall InterlockedDecrement(long volatile*);
    void* __stdcall GetCurrentThreadId();
}

struct S {
    void* field0;
    void* field4;
    void* field8;
    void* fieldC;
    void* field10;
    void* field14;
    void* field18;
    void* field1C;
    void* field20;
    void* field24;
    void* field28;
    void* field2C;
    void* field30;
    void destroy();
};

void __stdcall sub_4ff810(void*);
void __stdcall sub_457dd0(void*);

void S::destroy()
{
    if (field30 != 0) {
        if (InterlockedDecrement((long*)((char*)field30 + 4)) == 0) {
            sub_457dd0(field30);
            if (field30 != 0) {
                void** vtbl = *(void***)field30;
                void (*fn)(void*, int) = (void (*)(void*, int))vtbl[0];
                fn(field30, 1);
            }
        }
        field30 = 0;
    }
    sub_4ff810(field24);
    field24 = 0;
    field28 = 0;
    field2C = 0;
    sub_4ff810(field18);
    field18 = 0;
    field1C = 0;
    field20 = 0;
    sub_4ff810(fieldC);
    fieldC = 0;
    field10 = 0;
    field14 = 0;
    sub_4ff810(field0);
    field0 = 0;
    field4 = 0;
    field8 = 0;
}
