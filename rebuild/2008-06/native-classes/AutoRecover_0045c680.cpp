// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stddef.h>

namespace G3D {

class System {
public:
    static void free(void* p);
    static void alignedFree(void* p);
};

class Texture;
template <class T> class ReferenceCountedPointer;

namespace TextureManager {
class TextureArgs;
}

template <class Key, class Value>
class Table {
public:
    // INFERRED: sizes from node layout (entry at +8, next at +0x48); Entry dtor is out of line (0x45b640)
    class Entry {
    public:
        char data[0x40];
        ~Entry();
    };

    class Node {
    public:
        size_t hashCode;
        size_t pad; // INFERRED: fills offset 4 so entry sits at +8
        Entry entry;
        Node* next;

        void destroy() {
            entry.~Entry();
            System::free(this);
        }
    };

private:
    size_t pad0; // INFERRED: member at +0 is untouched here; the disassembly puts _size at +4
    size_t _size;
    Node** bucket;
    size_t numBuckets;

    void freeMemory();
};

template <class Key, class Value>
void Table<Key, Value>::freeMemory() {
    for (int b = 0; b < (int)numBuckets; ++b) {
        Node* node = bucket[b];
        while (node != NULL) {
            Node* n = node->next;
            node->destroy();
            node = n;
        }
    }
    System::alignedFree(bucket);
    bucket = NULL;
    numBuckets = 0;
    _size = 0;
}

template class Table<TextureManager::TextureArgs, ReferenceCountedPointer<Texture> >;

} // namespace G3D
