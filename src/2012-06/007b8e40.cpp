// from server: 98% by Intel
extern unsigned char g_debugFlag;
extern bool (__cdecl *g_assertCallback)(const char*, const char*, int);
extern const char g_fileName[];
extern const char g_functionName[];
extern const char g_logString[];
extern void __cdecl g_logFunction(const char*, int);

struct Geometry {
    static int __stdcall CheckAssertion(int);
};

int __stdcall Geometry::CheckAssertion(int unused) {
    if (!g_debugFlag) {
        return 0;
    }
    if (g_assertCallback) {
        if (g_assertCallback(g_fileName, g_functionName, 56)) {
            return 0;
        }
    }
    g_logFunction(g_logString, g_debugFlag);
    return 0;
}
