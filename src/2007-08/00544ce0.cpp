// from server: 52% by colin
// roc 2007-08 00544ce0  unit: RBX::VDebugSettings::?$GlobalSettingsItem  size: 198 bytes

struct String {
    char buf[16];
    unsigned int size;
    unsigned int cap;
    String(const char*);
    ~String();
};

struct GlobalSettingsItem {
    void init();
    void setString(const String&);
    GlobalSettingsItem();
};

extern "C" void __stdcall sub_77E698();
extern "C" void __stdcall sub_77E6AC();

GlobalSettingsItem::GlobalSettingsItem()
{
    init();
    *(void**)((char*)this + 0x00) = (void*)0x7a6d14;
    *(void**)((char*)this + 0x04) = (void*)0x7a6d0c;
    *(void**)((char*)this + 0x10) = (void*)0x7a6d04;
    *(void**)((char*)this + 0x14) = (void*)0x7a6cf4;
    *(void**)((char*)this + 0x2c) = (void*)0x7a6ce4;
    *(void**)((char*)this + 0x44) = (void*)0x7a6cd4;
    *(void**)((char*)this + 0x5c) = (void*)0x7a6cc4;
    *(void**)((char*)this + 0x74) = (void*)0x7a6cb4;
    *(void**)((char*)this + 0x8c) = (void*)0x7a6ca4;
    *(unsigned char*)((char*)this + 0xe8) = 1;
    *(unsigned char*)((char*)this + 0xe9) = 0;
    *(int*)((char*)this + 0xec) = 1;
    sub_77E698();
    String s((const char*)0x79d0dc);
    setString(s);
    s.~String();
    sub_77E6AC();
}
