// from server: 68% by Intel
// Global variables
extern "C" {
    unsigned char g_debugFlag;        // 0xE580B3
    int (__cdecl *g_assertCallback)(const char*, const char*, int); // 0xE5809C
    void __cdecl debugOutput(int, const char*); // 0x972290
}

// String literals (addresses from assembly)
extern const char g_filePath[];       // 0xBACD70
extern const char g_msgRoot[];        // 0xBD53A4
extern const char g_msgRootDetail[];  // 0xBD5330
extern const char g_msgSimBody[];     // 0xBD5320
extern const char g_msgSimBodyDetail[]; // 0xBD52B0

struct MegaClusterPoly {
    MegaClusterPoly* field_30; // offset 0x30
    int* field_38;             // offset 0x38
    int setSimBodyValue(float value);
};

int MegaClusterPoly::setSimBodyValue(float value) {
    if (g_debugFlag) {
        if (field_30 != this) {
            if (g_assertCallback) {
                if (g_assertCallback(g_msgRoot, g_filePath, 0xC5)) {
                    // callback handled it
                } else {
                    debugOutput(g_debugFlag, g_msgRootDetail);
                }
            } else {
                debugOutput(g_debugFlag, g_msgRootDetail);
            }
        }
    }

    if (g_debugFlag) {
        if (field_38 == 0) {
            if (g_assertCallback) {
                if (g_assertCallback(g_msgSimBody, g_filePath, 0xC6)) {
                    // callback handled it
                } else {
                    debugOutput(g_debugFlag, g_msgSimBodyDetail);
                }
            } else {
                debugOutput(g_debugFlag, g_msgSimBodyDetail);
            }
        }
    }

    int result = reinterpret_cast<int>(field_38);
    if (result) {
        *reinterpret_cast<float*>(result + 4) = value;
    }
    return result;
}
