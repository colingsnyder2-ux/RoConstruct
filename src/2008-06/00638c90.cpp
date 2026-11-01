// from server: 100% by king_originala
struct Vector {
    float x, y, z;
    Vector(const Vector& other);
};

__forceinline Vector::Vector(const Vector& other)
    : x(other.x), y(other.y), z(other.z)
{
}

struct Receiver {
    void set(Vector value);
};

struct Value {
    char padding[8];
    Receiver receiver;
};

struct Node {
    char padding[24];
    Value* value;
};

struct Owner {
    char padding[20];
    Node* end;
};

struct Iterator {
    char padding0[16];
    Owner** owner;
    Node* node;
    char padding1[32];
    Vector* vector;
    unsigned char* flag;

    bool equal(const Iterator& other);
    void next();
};

extern "C" void (__cdecl *invalid_parameter_noinfo)();

void* __stdcall process(void* result, Iterator first, Iterator last)
{
    if (!first.equal(last)) {
        void (__cdecl *invalid)() = invalid_parameter_noinfo;
        do {
            if (!*first.flag) {
                if (!first.owner)
                    invalid();

                Owner* owner = first.owner ? *first.owner : 0;
                if (first.node == owner->end)
                    invalid();

                Receiver* receiver = &first.node->value->receiver;
                receiver->set(*first.vector);
                if (!*first.flag)
                    *first.flag = 1;
            }
            first.next();
        } while (!first.equal(last));
    }
    return result;
}
