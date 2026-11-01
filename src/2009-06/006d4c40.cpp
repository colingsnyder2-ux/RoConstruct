// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
//

//

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

namespace RBX {
class Body;
struct Object {
    unsigned char data[180];
    Object(Body*);
};

class IndexedTree {
public:
    IndexedTree();
    virtual ~IndexedTree();
    int a; int b; void* s[3];
};
class KernelIndex { public: int index; KernelIndex() : index(-1) {} };
template<class T> class Allocator { };

class Body : public KernelIndex, public IndexedTree, public Allocator<Body> {
public:
    struct P { void* p; P() : p(0) {} } p;
    int second;
    int third;
    bool flag;
    Body* owner;
    void* pointer;
    Object* object;
    void* extra;
    bool enabled;
    Frame frame;
    Matrix matrix;
    float value;
    int identifier;
    FrameState frameState;

    Body();
    virtual ~Body();
};

Body::Body()
    : second(-1),
      third(0),
      flag(false),
      owner(0),
      pointer(0),
      object(0),
      extra(0),
      enabled(true),
      frame(),
      matrix(identity()),
      identifier(nextIdentifier(value)),
      frameState()
{
    owner = this;
    object = new Object(this);
}
}
