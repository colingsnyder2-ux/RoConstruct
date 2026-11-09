// from server: 100% by why2
struct TextureArgs;

struct Table {
    void insert(TextureArgs* args);
};

extern Table g_table;

void insert(TextureArgs* args) {
    g_table.insert(args);
}
