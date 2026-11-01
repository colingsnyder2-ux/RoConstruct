// from server: 100% by king_originala
struct Element {
    int first;
    int second;
};

struct Container {
    char pad[12];
    Element* begin;
    Element* end;
};

struct Helper {
    void prepare(void*, Container*);
};

struct Workspace {
    void process(Container*, Workspace*, unsigned int, unsigned int);
    void method(void*, Container*, unsigned int, unsigned int);
};

void Workspace::method(void* result, Container* container,
                       unsigned int first, unsigned int last) {
    Container* saved = container;
    ((Helper*)&container)->prepare(result, saved);
    if ((unsigned int)(saved->end - saved->begin) > 0)
        process(saved, this, first, last);
}
