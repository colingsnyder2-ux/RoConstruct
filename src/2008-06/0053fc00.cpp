// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
// Analog for 0053fc00 (AggregatingSceneManager update): re-files pending chunks
// (+0x28), clears the pending/dirty lists, then processes buckets (+0x8) until
// the time budget is spent (System::time 005083d0, bucket work 0053fe10).
template<class T>
class Ref {
public:
    ~Ref();
    T* operator->() const;
    bool notNull() const;
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
    Weak(const Owned<T>& owner);
    ~Weak();
    Owned<T> lock() const;
    T* pointer;
};

class Levels;
class Bounds;

class Chunk {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual Ref<Bounds> bounds();
    virtual Ref<Levels> levels();
    char header[0x1c];
    Weak<Part> part;
};

class Manager;

class Bucket {
public:
    void process(Manager* manager, double budget);
};

class BucketRef {
public:
    Bucket* get() const;
};

class Entry {
public:
    Ref<Chunk> lock() const;
    char header[0x0c];
    BucketRef bucket;
};

class Iter {
public:
    Iter();
    bool operator!=(const Iter& other) const;
    Iter& operator++();
    Iter& next();
    Entry& operator*() const;
    void* node;
    void* owner;
};

class EntryList {
public:
    Iter begin();
    Iter end();
    void clear();
    char data[0x20];
};

class System {
public:
    static double time();
};

extern unsigned renderQuality;

class Manager {
public:
    void update(double budget);
    void schedule(Weak<Part> part);
    void remove(const Ref<Chunk>& chunk);
    void add(const Ref<Chunk>& chunk);
    void* vtable;
    void* owner;
    EntryList buckets;
    EntryList pending;
    EntryList dirty;
};

void Manager::update(double budget)
{
    double deadline = System::time() + 1000.0 * budget;
    for (Iter it = pending.begin(), end = pending.end(); it != end; ) {
        Ref<Chunk> chunk = (*it).lock();
        if (chunk.notNull()) {
            chunk->levels();
            chunk->bounds();
            Owned<Part> part = chunk->part.lock();
            if (part.isNull()) {
                schedule(part);
            } else {
                remove(chunk);
                add(chunk);
            }
        }
        it.next();
    }
    pending.clear();
    dirty.clear();
    if (renderQuality > 1) {
        Iter it = buckets.begin();
        Iter end = buckets.end();
        while (System::time() < deadline && it != end) {
            (*it).bucket.get()->process(this, budget);
            ++it;
        }
    }
}
