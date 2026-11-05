// from server: 42% by colin
struct ContentId {
    void* impl;
};

struct SoundId {
    void* impl;
    void setContent(const ContentId& id);
    void setContentStr(const char* id);
    void setContentStd(const void* id);
    void setContentEmpty();
};

struct ContentIdHolder {
    char pad[0xbc];
    ContentId* content;
};

struct SoundIdImpl : SoundId {
    void setContent(const ContentId& id);
};

extern "C" void* __stdcall sub_77DD98(void*);
extern "C" void __stdcall sub_77DDBC(void*);
extern "C" void __stdcall sub_77E6AC(void*);
extern "C" void __stdcall sub_438690(void*, void*);
extern "C" void __stdcall sub_43D780(void*);
extern "C" void __stdcall sub_440440(void*, void*);

void SoundId::setContent(const ContentId& id) {
    ContentIdHolder* self = (ContentIdHolder*)this;
    int kind = *(int*)((char*)self->content + 0x34);
    if (kind == 0) {
        void** vt = *(void***)this;
        void (*fn)(void*) = (void (*)(void*))vt[0xf8 / 4];
        fn(this);
    } else if (kind == 1) {
        char buf[0x30];
        sub_43D780(buf);
        sub_440440(this, buf);
        sub_77E6AC(buf);
    } else {
        char buf[0x30];
        void* p = sub_77DD98(buf);
        char tmp[8];
        sub_438690(tmp, p);
        sub_440440(this, tmp);
        sub_77E6AC(tmp);
    }
    sub_77DDBC((char*)this + 0x58);
}
