// from server: 45% by atomic.potato
extern "C" void* __stdcall basic_string_ctor(void*, const char*);

struct PartTool {
    PartTool* f(const char*);
};

extern bool g_00e5147c;
extern char g_00ba3b54[];
extern char g_00ba3b60[];

PartTool* PartTool::f(const char* unused)
{
    char* text = g_00ba3b54;
    if (g_00e5147c)
        text = g_00ba3b60;
    basic_string_ctor(this, text);
    return this;
}
