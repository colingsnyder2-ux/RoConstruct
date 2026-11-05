// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
// Local names were chosen to reproduce the /Od frame layout (MSVC orders locals by name hash).
// Analog for 0053fe10 (bucket processing): partitions the bucket's chunks
// (00545da0) and merges every group of at least four into a new n
// (0x108 bytes, ctor 00551f30) that replaces them in the scene manager.
#include <algorithm>

class Aggregate;
class Chunk;

class AggRef {
public:
    AggRef();
    ~AggRef();
    bool isNull() const;
    bool notNull() const;
    AggRef& operator=(Aggregate* pointer);
    Aggregate* get() const;
    Aggregate* pointer;
};

class Owner {
public:
    Owner& operator=(const AggRef& n);
    void* pointer;
};

class ChunkData {
public:
    int header[0x20 / 4];
    Owner owner;
};

class Handle {
public:
    Handle(int key);
    ~Handle();
    ChunkData* operator->() const;
    void* value;
};

class AggHandle {
public:
    AggHandle(const AggRef& n);
    ~AggHandle();
    void* value;
};

class Iter {
public:
    Iter();
    bool operator!=(const Iter& other) const;
    void* node;
    void* owner;
};

class ChunkIter : public Iter {
public:
    ChunkIter& operator++();
    int& operator*() const;
    int operator-(const ChunkIter& other) const;
};

class HandleList {
public:
    ChunkIter begin();
    ChunkIter end();
    void push_back(const Handle& obj);
    unsigned size() const;
    void clear();
    int data[0x18 / 4];
};

class Group {
public:
    int header[0x0c / 4];
    HandleList chunks;
};

class GroupIter : public Iter {
public:
    GroupIter& operator++();
    Group& operator*() const;
};

class GroupList {
public:
    GroupIter begin();
    GroupIter end();
};

class Partition {
public:
    Partition(unsigned tmp7);
    ~Partition();
    void insert(ChunkIter item, ChunkIter x);
    GroupList* levelAt(int n);
    int data[0x20 / 4];
};

class Aggregate {
public:
    Aggregate(const Handle& item);
    void build();
    int header[0xf0 / 4];
    HandleList chunks;
};

class SceneManager {
public:
    void removeChunk(const Handle& q);
    void addAggregate(const AggHandle& n);
};

extern unsigned renderQuality;
extern int aggregateCount;

class Bucket {
public:
    void process(SceneManager* scene, double budget);
    int header[0x0c / 4];
    HandleList chunks;
};

void Bucket::process(SceneManager* scene, double budget)
{
    if (chunks.size() * 4 < renderQuality)
        return;
    unsigned tmp7 = std::max<unsigned>(1, chunks.size() / renderQuality);
    Partition c(tmp7);
    c.insert(chunks.begin(), chunks.end());
    chunks.clear();
    GroupList* level1 = c.levelAt(5);
    GroupIter it15 = level1->begin();
    GroupIter end = level1->end();
    for (; it15 != end; ++it15) {
        ChunkIter item = (*it15).chunks.begin();
        ChunkIter x = (*it15).chunks.end();
        if (x - item >= 4) {
            AggRef n;
            for (; item != x; ++item) {
                Handle q(*item);
                if (n.isNull())
                    n = new Aggregate(q);
                n.get()->chunks.push_back(q);
                q->owner = n;
                ++aggregateCount;
                scene->removeChunk(q);
            }
            if (n.notNull()) {
                n.get()->build();
                scene->addAggregate(n);
            }
        }
    }
}
