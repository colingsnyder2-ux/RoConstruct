// from server: 93% by atomic.potato
struct TexturePtr {
    void* p;
    TexturePtr& operator=(const TexturePtr& other);
};

struct Vertex {
    float x;
    float y;
    TexturePtr tex;
};

extern "C" __declspec(dllimport) void* __stdcall Ogre_TexturePtr_assign(void*, const void*);

void copy_vertices(Vertex* first, Vertex* last, const Vertex* src) {
    while (first != last) {
        first->x = src->x;
        first->y = src->y;
        first->tex = src->tex;
        first = (Vertex*)((char*)first + 0x18);
    }
}
