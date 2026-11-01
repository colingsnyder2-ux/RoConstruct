// from server: 100% by EspClaude
//

//

//

struct Geometry {
    const void* getBounds();
};
struct Connection;

struct Array {
    Geometry** data;
    int count;
    void reset(int, int);
};

struct Receiver {
    void collect(const void*, Geometry*, Array*);
};

struct Iterator {
    void* owner;
    void* node;
};

struct Filter {
    void* owner;
    unsigned char reserved[0x14];
    void* endNode;

    Iterator* find(Iterator*, Geometry**);
};

extern "C" {
    extern void (__cdecl* _invalid_parameter_noinfo)();
}
void* __cdecl findConnection(Geometry*, Geometry*, int);
struct Call { void (*fn)(Connection*); Connection* c; };
struct Owner { void run(Call); };
void __cdecl processConnection(Connection*);
Connection* __cdecl makeConnection(Geometry*, Geometry*);

struct S {
    Owner* owner;
    unsigned char reserved0[0x2d];
    unsigned char active;
    unsigned char reserved1[0x4a];
    int version;
    Array candidates;
    unsigned char reserved2[0x28];
    Receiver* receiver;

    void prepare(Connection*);
    void process(Connection*);
    void f(Geometry*, Filter*);
};

void S::f(Geometry* geometry, Filter* filter)
{
    ++version;
    candidates.reset(0, 0);
    receiver->collect(geometry->getBounds(), geometry, &candidates);

    for (int i = 0; i < candidates.count; ++i) {
        Geometry* candidate = candidates.data[i];
        Geometry* key = candidate;

        if (filter) {
            Iterator end;
            end.node = filter->endNode;
            end.owner = filter->owner;
            Iterator result;
            Iterator* found = filter->find(&result, &key);

            if (!found->owner || found->owner != end.owner)
                _invalid_parameter_noinfo();

            if (found->node != end.node)
                continue;
        }

        if (!findConnection(geometry, candidate, 0)) {
            Connection* connection = makeConnection(geometry, candidate);
            if (connection) {
                prepare(connection);
                active = 1;
                Call call = { processConnection, connection };
                if (owner)
                    owner->run(call);
                active = 0;
            }
        }
    }
}
