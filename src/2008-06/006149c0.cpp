// from server: 100% by king_originala
struct Matrix {
    float values[9];
    Matrix(const Matrix&);
};

extern const Matrix& __cdecl identity();

struct Frame {
    float values[12];
    Frame();
};

struct State {
    unsigned char data[1];
    State();
};

struct Storage {
    void* first;
    void* last;
    void* end;

    Storage();
    ~Storage();
};

inline Storage::Storage()
{
    last = 0;
    end = 0;
    first = 0;
}

struct FrameState {
    Frame frame;
    State state;
    FrameState();
};

inline FrameState::FrameState()
    : frame(), state()
{
}

extern int counter;

inline int nextIdentifier(float& value)
{
    int result = counter;
    value = 0.0f;
    ++result;
    counter = result;
    if (result == 0x7fffffff) {
        result = 1;
        counter = result;
    }
    return result;
}

struct S;

struct Object {
    unsigned char data[180];
    Object(S*);
};

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct S {
    int first;
    int second;
    int third;
    bool flag;
    S* owner;
    void* pointer;
    int index;
    Storage storage;
    void* extra;
    Object* object;
    bool enabled;
    int reserved;
    Frame frame;
    Matrix matrix;
    float value;
    int identifier;
    FrameState frameState;

    S();
};

S::S()
    : first(-1),
      second(-1),
      third(0),
      flag(false),
      owner(0),
      pointer(0),
      index(-1),
      storage(),
      extra(0),
      object(0),
      enabled(true),
      reserved(0),
      frame(),
      matrix(identity()),
      identifier(nextIdentifier(value)),
      frameState()
{
    owner = this;
    object = new Object(this);
}
