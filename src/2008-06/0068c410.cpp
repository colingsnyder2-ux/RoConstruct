// from server: 100% by king_originala
struct Matrix {
    float m[16];
};

extern const Matrix* identity;

struct Renderer;

struct RendererTable {
    void* reserved0[26];
    void (__thiscall *setWorld)(Renderer*, const Matrix*);
    void (__thiscall *setView)(Renderer*, const Matrix*);
    void* reserved1[40];
    void (__thiscall *convertProjection)(Renderer*, const Matrix*, Matrix*, bool);
};

struct Renderer {
    RendererTable* table;
};

struct Options {
    char reserved[0x25];
    bool view;
    bool world;
};

struct SceneManager {
    char reserved0[0x34];
    Renderer* renderer;
    char reserved1[0x41d8 - 0x38];
    bool worldChanged;
    bool viewChanged;

    void update(const Options* options);
};

void SceneManager::update(const Options* options)
{
    Matrix converted;
    if (options->world) {
        renderer->table->setWorld(renderer, identity);
        worldChanged = true;
    }
    if (options->view) {
        renderer->table->convertProjection(renderer, identity, &converted, false);
        renderer->table->setView(renderer, &converted);
        viewChanged = true;
    }
}
