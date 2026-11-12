// from server: 100% by EspClaude
// roc 2007-08 00470220  size: 243 bytes
// glg3dcpp/Texture.cpp : newGLTextureID() with G3D debugAssertM.
// Target (objdump of clients/2007-08/Roblox.exe):
//   call [0x77eba0] (glGetError) ; glGenTextures(1,&id) via [0x77eb3c]
//   cmp byte [0x8bd07d],0 (static ignoreAlways) ; cmp eax,0x502 (GL_INVALID_OPERATION)
//   call 0x502880 (_releaseInputGrab_) ; cmp [0x8980fc],0 (_debugHook != NULL)
//   std::string ctor [0x77e698] / dtor [0x77e6ac] for the message temporary
//   _debugHook(expr, msg, file, 0x4d8, ignoreAlways, 1) ; push -1; call [0x77e938] ; call 0x5028f0
#include <string>

extern "C" __declspec(dllimport) unsigned int __stdcall glGetError(void);
extern "C" __declspec(dllimport) void __stdcall glGenTextures(int n, unsigned int* textures);
extern "C" __declspec(dllimport) __declspec(noreturn) void __cdecl exit(int);

namespace G3D {
namespace _internal {
typedef bool (*AssertionHook)(const char* expression, const std::string& message,
                              const char* filename, int lineNumber,
                              bool& ignoreAlways, bool useGuiPrompt);
extern AssertionHook _debugHook;
void _releaseInputGrab_();
void _restoreInputGrab_();
}
}

#define GL_INVALID_OPERATION 0x0502

#define debugAssertM(exp, message) do { \
    static bool __debugAssertIgnoreAlways__ = false; \
    if (!__debugAssertIgnoreAlways__ && !(exp)) { \
        G3D::_internal::_releaseInputGrab_(); \
        if ((G3D::_internal::_debugHook != NULL) && \
            G3D::_internal::_debugHook((char*)(#exp), message, __FILE__, __LINE__, __debugAssertIgnoreAlways__, true)) { \
            exit(-1); \
        } \
        G3D::_internal::_restoreInputGrab_(); \
    } \
} while (0)

unsigned int newGLTextureID()
{
    glGetError();
    unsigned int id;
    glGenTextures(1, &id);
#line 1238 ".\\glg3dcpp\\Texture.cpp"
    debugAssertM(glGetError() != GL_INVALID_OPERATION,
                 "GL_INVALID_OPERATION: Probably caused by invoking "
                 "glGenTextures between glBegin and glEnd.");
    return id;
}
