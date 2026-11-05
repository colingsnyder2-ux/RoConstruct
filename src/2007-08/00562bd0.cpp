// from server: 52% by colin
struct AttachCameraCommand {
    char pad[0x0c];
    void* field0c;
    char pad2[0x10];
    void* field20;
    void execute(void* arg);
};

extern "C" void* __stdcall sub_5618E0();
extern "C" void __stdcall sub_59B6C0();
extern "C" void __stdcall sub_59B700();
extern "C" void __stdcall sub_4108B0();
extern "C" void __stdcall sub_77E6D8();

void AttachCameraCommand::execute(void* arg)
{
    void* esi;
    if (field20) {
        esi = sub_5618E0();
    } else {
        esi = 0;
    }

    void* result;
    if (esi) {
        char* p = (char*)esi;
        void** begin = *(void***)(p + 0xf8);
        void** end = *(void***)(p + 0xfc);
        if (begin && ((char*)end - (char*)begin) >> 2) {
            void** it = begin;
            if (it > end) {
                sub_77E6D8();
            }
            if (it < end) {
                result = *it;
            } else {
                sub_77E6D8();
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
    void* obj = (void*)(p0c + 0x228);
    void* fn = vtbl[1];
    void* r = ((void* (__thiscall*)(void*, int))fn)(obj, 1);
    sub_59B6C0();

    p0c = (char*)field0c;
    vtbl = *(void***)(p0c + 0x228);
    obj = (void*)(p0c + 0x228);
    fn = vtbl[1];
    r = ((void* (__thiscall*)(void*, void*))fn)(obj, result);
    sub_59B700();

    void* a = arg;
    sub_4108B0();
    void** vtbl2 = *(void***)a;
    void* fn2 = vtbl2[1];
    *(int*)((char*)a + 4) = -1;
    ((void (__thiscall*)(void*, int))fn2)(a, 1);
}
