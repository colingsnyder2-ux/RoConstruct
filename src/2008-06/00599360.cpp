// from server: 100% by king_originala
struct DataSource {
    const void* get();
};

extern void __cdecl combine(const void*, const void*, void*);

struct S {
    char reserved0[0x10];
    S* source;
    S* parent;
    char reserved1[0x1C];
    DataSource* dataSource;
    char localData[0x58];
    unsigned int version;
    char result[0x30];

    void update();
};

void S::update()
{
    if (parent) {
        S* s = source;
        s->update();
        if (version != s->version) {
            parent->update();

            const void* data;
            if (dataSource)
                data = dataSource->get();
            else
                data = localData;

            S* p = parent;
            p->update();
            combine(p->result, data, result);

            s = source;
            s->update();
            version = s->version;
        }
    }
}
