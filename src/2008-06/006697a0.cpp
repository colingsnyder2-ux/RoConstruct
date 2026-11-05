// from server: 100% by king_originala
struct Primitive;

struct Geometry {
    Primitive* getFirst();
    Primitive* getNext(Primitive*);
};

struct Primitive {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int isA();
    virtual void v4();
    virtual int getType();

    char pad04[8];
    Geometry* first;
    Geometry* second;
    char pad14[8];
    bool marked;
    char pad1D[7];
    bool enabled;
};

struct Collection {
    void insert(void* result, Primitive** value);
};

struct TreeStage {
    char pad00[16];
    int depth;
    bool changed;
    char pad15[67];
    Collection collection;

    void reset(Primitive*, Geometry*);
    void visit(Primitive*, Geometry*, int);
};

void TreeStage::visit(Primitive* node, Geometry* previous, int level)
{
    const int* maximum = depth < level ? &level : &depth;
    depth = *maximum;
    reset(node, previous);

    Geometry* geometry =
        previous == node->first ? node->second : node->first;

    Primitive* current = geometry->getFirst();
    while (current) {
        if (!current->isA() && current->getType() >= 5) {
            if (current->enabled) {
                Geometry* other = current->first;
                if (geometry == other)
                    other = current->second;
                if (other && other != previous)
                    visit(current, geometry, level + 1);
            }
        } else {
            Primitive* value = current;
            if (!current->marked) {
                int result[3];
                collection.insert(result, &value);
                changed = true;
                current->marked = true;
            }
        }
        current = geometry->getNext(current);
    }
}
