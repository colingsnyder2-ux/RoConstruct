// from server: 100% by colin
struct MouseCommand {
    char pad[0x188];
    void* field_188;
};

struct TToolVerb {
    char pad[0xc];
    MouseCommand* mouseCommand;
    bool isEnabled() const;
};

extern "C" int __cdecl sub_00631392(void*);
extern "C" bool (__thiscall *sub_0077e708)(void*, int);
extern char g_8a5768;

bool TToolVerb::isEnabled() const {
    void* p = this->mouseCommand->field_188;
    void* q = *reinterpret_cast<void**>(reinterpret_cast<char*>(p) + 0x318);
    if (q) {
        return sub_0077e708(&g_8a5768, sub_00631392(q));
    }
    return false;
}
