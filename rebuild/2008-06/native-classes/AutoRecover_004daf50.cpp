// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the singleton layout and the class types below are guesses from the disassembly (offsets only).
#include <stddef.h>

namespace boost {
    void call_once(void (*f)(), long& flag);
}

namespace RBX {
    class GuidRegistryMutex {
    public:
        void lock();
        void unlock();
    };
}

namespace G3D {
    class System {
    public:
        static void* alignedMalloc(unsigned int bytes, unsigned int alignment);
        static void memset(void* dst, unsigned char value, unsigned int n);
    };
}

extern "C" void fn_004d9750();
extern "C" int __fastcall fn_004d8dc0(void* self, int unusedEdx);
extern "C" void __fastcall fn_004d83e0(void* self, int unusedEdx, void* node);
extern "C" void __fastcall fn_004d8470(void* self, int unusedEdx, void* node);

// INFERRED: globals at 0x972724 (instance pointer) and 0x97273c (call_once flag)
extern char* g_registryInstance;
extern long  g_registryOnceFlag;

namespace {
    struct TreeNode {
        TreeNode* left;
        TreeNode* parent;
        TreeNode* right;
    };

    struct MutexLock {
        RBX::GuidRegistryMutex* m;
        explicit MutexLock(RBX::GuidRegistryMutex* mm) : m(mm) { m->lock(); }
        ~MutexLock() { m->unlock(); }
    };

    inline void clearTree(char* map, void (__fastcall *erase)(void*, int, void*))
    {
        TreeNode* head = *(TreeNode**)(map + 0x18);
        erase(map, 0, head->parent);
        head = *(TreeNode**)(map + 0x18);
        head->parent = head;
        head = *(TreeNode**)(map + 0x18);
        *(int*)(map + 0x1c) = 0;
        head->left = head;
        head = *(TreeNode**)(map + 0x18);
        head->right = head;
    }
}

extern "C" void fn_004daf50()
{
    boost::call_once(fn_004d9750, g_registryOnceFlag);
    char* self = g_registryInstance;

    MutexLock guard((RBX::GuidRegistryMutex*)(self + 0x10));

    fn_004d8dc0(self, 0);
    *(int*)(self + 0xc) = 0x14;
    *(int*)(self + 4) = 0;
    void* buf = G3D::System::alignedMalloc(0x50, 0x10);
    *(void**)(self + 8) = buf;
    G3D::System::memset(buf, 0, *(int*)(self + 0xc) * 4);

    clearTree(self + 0x1c, fn_004d83e0);
    clearTree(self + 0x3c, fn_004d8470);
}
