// from server: 62% by tester
struct EnumDescriptor {
    void addLegacyName(const char* name);
};

struct EnumDesc {
    void dummy();
    void addLegacyName(const char* name);
};

extern "C" void __stdcall func_0076fc70(const char* name);
extern "C" void __stdcall func_0076a190(void* desc, const char* name);

void EnumDesc::addLegacyName(const char* name)
{
    char buf[4];
    func_0076fc70(name + 4);
    *(int*)buf = *(int*)name;
    func_0076a190(this, buf);
}
