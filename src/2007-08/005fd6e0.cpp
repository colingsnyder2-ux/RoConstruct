// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>

// cursor name is a std::string at +0x20; operator=(const char*) is imported from MSVCP80.
struct GrabTool {
    char pad[0x20];
    std::string cursor;
    void setCursorFromName(const char*);
};

extern char g_8C6EE4;
extern "C" void* __stdcall sub_5E3F80(const char*, const char*);

void GrabTool::setCursorFromName(const char* name) {
    void* p = sub_5E3F80(name, &g_8C6EE4);
    if (p == 0) {
        cursor = "ArrowFarCursor";
    } else if (*(char*)((char*)p + 0x1a0) != 0) {
        cursor = "ArrowCursor";
    } else {
        cursor = "DragCursor";
    }
}
