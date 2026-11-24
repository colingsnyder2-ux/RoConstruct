// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>
#include <stdlib.h>

// INFERRED: no class headers were available, so the minimal G3D types needed
// for this member are reconstructed here, with offsets taken from the disassembly.
namespace G3D {

class Texture;

namespace _internal {
    void _releaseInputGrab_();
    void _restoreInputGrab_();
}

// INFERRED: assertion handler function pointer at 0x0094278c
typedef bool (__cdecl *AssertHook)(const char* expr, const std::string& msg,
                                   const char* file, int line,
                                   bool& ignoreAlways, bool useGui);
extern AssertHook g_0094278c;

class System {
public:
    static void free(void* p);
};

template <class T>
class ReferenceCountedPointer {
    T* m_p;
};

class TextureManager {
public:
    class TextureArgs {
    public:
        virtual unsigned int hashCode() const;
        std::string filename;   // +4
        int a;                  // +0x20
        int b;                  // +0x24
        int c;                  // +0x28
        int d;                  // +0x2c
        double e;               // +0x30
    };
};

template <class Key, class Value>
class Table {
public:
    struct Entry {
        Key key;
        Value value;
        ~Entry();   // out of line (0x45b640)
    };

    struct Node {
        unsigned int hashCode;
        Entry entry;
        Node* next;
    };

    unsigned int m_unk0;
    unsigned int _size;
    Node** bucket;
    unsigned int numBuckets;

    void remove(const Key& key);
};

#define G3D_ASSERTM_LOCAL(flag, cond, exprText, msgText, line, exitFlag) \
    if (!(flag) && !(cond)) { \
        _internal::_releaseInputGrab_(); \
        bool doExit = false; \
        if (g_0094278c != 0) { \
            std::string m(msgText); \
            doExit = g_0094278c(exprText, m, \
                "d:\\Roblox\\Releases\\2008.06.17\\Client\\Rendering\\g3d\\include\\G3D/Table.h", \
                line, flag, true); \
        } \
        if (doExit) { exit(-1); } \
        _internal::_restoreInputGrab_(); \
    }

template <class Key, class Value>
void Table<Key, Value>::remove(const Key& key)
{
    unsigned int code = key.hashCode();
    unsigned int b = code % numBuckets;

    Node* n = bucket[b];
    Node* previous = 0;

    static bool ignoreFlag1 = false;
    G3D_ASSERTM_LOCAL(ignoreFlag1, n != 0, "n != NULL",
                      "Tried to remove a key that was not in the table.", 0x215, 0);

    do {
        if (code == n->hashCode &&
            n->entry.key.a == key.a &&
            n->entry.key.b == key.b &&
            n->entry.key.c == key.c &&
            n->entry.key.filename == key.filename &&
            n->entry.key.d == key.d &&
            n->entry.key.e == key.e) {

            Node* next = n->next;
            if (previous == 0) {
                bucket[b] = next;
            } else {
                previous->next = next;
            }
            n->entry.~Entry();
            System::free(n);
            --_size;
            return;
        }
        previous = n;
        n = n->next;
    } while (n != 0);

    static bool ignoreFlag2 = false;
    G3D_ASSERTM_LOCAL(ignoreFlag2, false, "false",
                      "Tried to remove a key that was not in the table.", 0x22d, 0);
}

template void Table<TextureManager::TextureArgs,
                    ReferenceCountedPointer<Texture> >::remove(const TextureManager::TextureArgs&);

} // namespace G3D
