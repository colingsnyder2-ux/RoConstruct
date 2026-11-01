// from server: 100% by king_originala
struct Matrix {
    float values[9];
};

struct Vector {
    float x, y, z;
};

struct State {
    Matrix matrix;
    Vector position;
    Vector linearVelocity;
    Vector angularVelocity;

    State& operator=(const State& value);
};

inline State& State::operator=(const State& value)
{
    matrix = value.matrix;
    position.x = value.position.x;
    position.y = value.position.y;
    position.z = value.position.z;
    linearVelocity.x = value.linearVelocity.x;
    linearVelocity.y = value.linearVelocity.y;
    linearVelocity.z = value.linearVelocity.z;
    angularVelocity.x = value.angularVelocity.x;
    angularVelocity.y = value.angularVelocity.y;
    angularVelocity.z = value.angularVelocity.z;
    return *this;
}

struct DirtyFlag {
    char padding[8];
    unsigned char dirty;
};

extern int sequence;

struct Link {
    char padding0[0x14];
    int locked;
    char padding1[0x14];
    DirtyFlag* flag;
    char padding2[0x60];
    int stamp;
    State state;

    void setState(const State& value);
};

void Link::setState(const State& value)
{
    if (locked == 0) {
        state = value;
        if (flag)
            flag->dirty = 1;
        if (++sequence == 0x7fffffff)
            sequence = 1;
        stamp = sequence;
    }
}
