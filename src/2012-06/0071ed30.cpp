// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD

namespace RBX {
    extern bool assertsEnabled;
    extern bool assertsFatal;
    extern bool (*assertHook)(const char* expr, const char* file, int line);
    void assertionFailed(bool fatal, const char* message);
}

#define RBXASSERT(expr) \
    if (RBX::assertsEnabled && !(expr)) { \
        if (!RBX::assertHook || !RBX::assertHook(#expr, "C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\include\\V8World/World.h", 154)) \
            RBX::assertionFailed(RBX::assertsFatal, #expr " file: C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\include\\V8World/World.h line: 154"); \
    }

struct World {
    char pad[0x28];
    bool inStepCode;
    char pad2[7];
    int value30;
    void reset30();
};

void World::reset30()
{
    RBXASSERT(!inStepCode);
    value30 = 0;
}