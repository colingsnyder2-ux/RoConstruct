// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob1 /GS- /MT
// Analog for 00548fe0: unless shared state is disabled (009738a1), draws a
// chunk's non-empty index list (size 00442cd0) through the device (005029c0).
template<class T>
class Array {
public:
    int size() const;
    T* data;
    int num;
    int numAllocated;
};

class Chunk {
public:
    char header[0x0c];
    Array<int> indices;
    void* buffer;
};

class Device {
public:
    void drawIndices(void* buffer, Array<int>* indices);
};

extern bool sharedDisabled;

void drawChunk(Chunk* chunk, Device* device)
{
    do {} while (0);
    if (sharedDisabled)
        return;
    if (chunk == 0)
        return;
    int count = chunk->indices.size();
    if (count > 0)
        device->drawIndices(chunk->buffer, &chunk->indices);
}
