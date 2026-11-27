// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string.h>
typedef unsigned char uint8;
namespace G3D {
class System {
public:
    static void memset(void* dst, uint8 value, size_t numBytes);
};
class MemoryManager {
public:
    virtual ~MemoryManager();
    virtual void* alloc(size_t s);
    virtual void free(void* ptr);
};
class GImage {
public:
    int m_ref;
    MemoryManager* m_memMan;
    uint8* m_byte;
    int m_channels;
    int m_width;
    int m_height;
    void clear() {
        m_width = 0;
        m_height = 0;
        m_memMan->free(m_byte);
        m_byte = 0;
    }
    void resize(int width, int height, int channels, bool zero);
    void _copy(const GImage& other);
};
void GImage::resize(int width, int height, int channels, bool zero) {
    clear();
    m_width = width;
    m_height = height;
    m_channels = channels;
    size_t sz = width * height * channels;
    if (sz > 0) {
        m_byte = (uint8*)m_memMan->alloc(sz);
        if (zero) {
            System::memset(m_byte, 0, sz);
        }
    }
}
void GImage::_copy(const GImage& other) {
    clear();
    m_width  = other.m_width;
    m_height = other.m_height;
    m_channels = other.m_channels;
    int s  = m_width * m_height * m_channels * sizeof(uint8);
    m_byte  = (uint8*)m_memMan->alloc(s);
    memcpy(m_byte, other.m_byte, s);
}
}