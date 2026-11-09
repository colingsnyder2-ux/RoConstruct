// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>

// cursor name is a std::string at +0x20; operator=(const char*) is imported from MSVCP80.
struct GameTool {
    char pad[0x20];
    std::string cursor;
    void* hit(int a, float* v);
    bool test(void* r, float* v);
    void f(int a);
};

void GameTool::f(int a)
{
    if (*(unsigned short*)(a + 0xc) == 0)
        return;
    if (*(unsigned short*)(a + 0xe) == 0)
        return;

    float v[3];
    v[0] = 0.0f;
    v[1] = 0.0f;
    v[2] = 0.0f;

    void* r = hit(a, v);
    if (r == 0) {
        cursor = "ArrowFarCursor";
        return;
    }

    if (!test(r, v)) {
        cursor = "ArrowCursor";
        return;
    }

    cursor = "DragCursor";
}
