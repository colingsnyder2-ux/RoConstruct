// from server: 100% by king_originala
struct Geometry;
struct Edge;

struct Geometry {
    Edge* getFirstB();
    Edge* getNextB(Edge* edge);
};

struct Edge {
    char pad[12];
    Geometry* g0;
    Geometry* g1;
};

struct GeometryArray {
    Geometry** data;
    int count;
    int capacity;

    void resize(int size, bool preserve);
    void appendSlow(Geometry* const& value);
};

struct Controller {
    void apply(Geometry* first, Geometry* second);
};

struct Contact {
    char pad0[8];
    Controller* controller;
    char pad1[0x80 - 12];
    GeometryArray pending;

    bool intersects(Geometry* first, Geometry* second);
    void process(Geometry* geometry);
};

void Contact::process(Geometry* geometry)
{
    GeometryArray& list = pending;
    list.resize(0, true);

    Edge* edge = geometry->getFirstB();
    while (edge) {
        Geometry* other = edge->g0;
        if (geometry == other)
            other = edge->g1;

        edge = geometry->getNextB(edge);

        if (!intersects(geometry, other)) {
            Geometry* value;
            if (list.count < list.capacity) {
                Geometry** slot = list.data + list.count;
                if (slot)
                    *slot = other;
                ++list.count;
            } else if (
                reinterpret_cast<unsigned int>(&value) >=
                    reinterpret_cast<unsigned int>(list.data) &&
                reinterpret_cast<unsigned int>(&value) <
                    reinterpret_cast<unsigned int>(list.data + list.count)) {
                Geometry* copy = other;
                list.appendSlow(copy);
            } else {
                list.resize(list.count + 1, false);
                list.data[list.count - 1] = other;
            }
        }
    }

    for (int i = 0; i < pending.count; ++i)
        controller->apply(geometry, list.data[i]);
}
