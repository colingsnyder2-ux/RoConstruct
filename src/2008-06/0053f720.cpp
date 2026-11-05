// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
// Analog for 0053f720 (AggregatingSceneManager): adds a chunk to the list at
// +0xc unless it is orphaned, has no levels, is not a quad level (type 5), is
// not visible (0053f920) or is already listed (find 00545d40).
template<class T>
class Ref {
public:
    ~Ref();
    T* operator->() const;
    bool isNull() const;
    T* pointer;
};

class Part;

template<class T>
class Owned {
public:
    ~Owned();
    bool isNull() const;
    T* pointer;
};

template<class T>
class Weak {
public:
    Owned<T> lock() const;
    T* pointer;
};

class CFrame;

class LevelData {
public:
    char header[0x18];
    int type;
};

class Levels {
public:
    Ref<LevelData> handleFor(float distance);
};

class Chunk {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual Ref<Levels> levels();
    virtual const CFrame& frame();
    char header[0x1c];
    Weak<Part> part;
};

class Iter {
public:
    Iter();
    bool operator!=(const Iter& other) const;
    void* node;
    void* owner;
};

class ChunkList {
public:
    Iter begin();
    Iter end();
    void push_back(const Ref<Chunk>& chunk);
};

Iter find(Iter first, Iter last, const Ref<Chunk>& value);
bool isVisible(const CFrame& frame);

class Manager {
public:
    void add(const Ref<Chunk>& chunk);
    char header[0x0c];
    ChunkList chunks;
};

void Manager::add(const Ref<Chunk>& chunk)
{
    if (chunk->part.lock().isNull())
        return;
    if (chunk->levels().isNull())
        return;
    if (chunk->levels()->handleFor(1.0f)->type != 5)
        return;
    if (!isVisible(chunk->frame()))
        return;
    if (find(chunks.begin(), chunks.end(), chunk) != chunks.end())
        return;
    chunks.push_back(chunk);
}
