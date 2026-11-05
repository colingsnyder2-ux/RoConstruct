// from server: 54% by colin
struct WatchCameraCommand {
    char pad[0x0c];
    void* field0c;
    char pad2[0x10];
    void* field20;
    void execute(void* arg);
};

extern "C" void* __stdcall sub_5618e0(void*);
extern "C" void __stdcall sub_59b6c0(void*);
extern "C" void __stdcall sub_59b700(void*);
extern "C" void __stdcall sub_4108b0(void*);
extern "C" void __stdcall invalid_parameter_noinfo();

void WatchCameraCommand::execute(void* arg)
{
    void* esi;
    if (field20 != 0) {
        esi = sub_5618e0(field20);
    } else {
        esi = 0;
    }

    void* result;
    if (esi != 0) {
        char* p = (char*)esi;
        void** begin = *(void***)(p + 0xf8);
        void** end = *(void***)(p + 0xfc);
        if (begin != 0 && ((char*)end - (char*)begin) >> 2 != 0) {
            void** it = begin;
            if (it > end) {
                invalid_parameter_noinfo();
            }
            if (it < end) {
                result = *it;
            } else {
                invalid_parameter_noinfo();
                result = 0;
            }
        } else {
            result = 0;
        }
    } else {
        result = 0;
    }

    char* p0c = (char*)field0c;
    void** vtbl = *(void***)(p0c + 0x228);
    void* self = p0c + 0x228;
    void* fn = vtbl[1];
    void* r1 = ((void* (__stdcall*)(void*, int))fn)(self, 2);
    sub_59b6c0(r1);

    p0c = (char*)field0c;
    vtbl = *(void***)(p0c + 0x228);
    self = p0c + 0x228;
    fn = vtbl[1];
    void* r2 = ((void* (__stdcall*)(void*, void*))fn)(self, result);
    sub_59b700(r2);

    void* a = arg;
    sub_4108b0(a);
    void** vtbl2 = *(void***)a;
    void* fn2 = vtbl2[1];
    *(int*)((char*)a + 4) = -1;
    ((void (__stdcall*)(void*, int))fn2)(a, 1);
}
