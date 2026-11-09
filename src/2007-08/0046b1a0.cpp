// from server: 52% by Intel
struct LuaObjectWriter {
    void* vftable;
    char padding[0x70];
    struct String {
        void* vftable;
        char data[0x10];
    } str;
};

extern "C" void __stdcall __security_cookie_init();
extern "C" void __cdecl std_string_dtor(void*);

LuaObjectWriter* LuaObjectWriter_ctor(LuaObjectWriter* this_) {
    void* cookie = *(void**)0x8B5188;
    void* seh_frame = (char*)&cookie - 0xC;
    *(void**)seh_frame = *(void**)0;
    *(void**)0 = seh_frame;
    *(int*)((char*)seh_frame + 4) = (int)cookie ^ (int)seh_frame;

    this_->vftable = (void*)0x7961B4;
    std_string_dtor(&this_->str);
    *(int*)((char*)seh_frame + 0x14) = 0;
    this_->vftable = (void*)0x7961A8;

    *(void**)0 = *(void**)seh_frame;
    return this_;
}
