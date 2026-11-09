// from server: 100% by king_originala
#pragma optimize("", off)

struct Chunk;

struct ChunkArray {
    char storage[24];
    unsigned int size() const;
    void push_back(Chunk* const& value);
    Chunk*& operator[](unsigned int index);
};

struct Bucket {
    char padding[12];
    ChunkArray chunks;
    unsigned int cursor;
};

struct AggregateChunk {
    int insert(Chunk* chunk, Bucket* bucket);
    Bucket* findBucket(Chunk* chunk);
};

int AggregateChunk::insert(Chunk* chunk, Bucket* bucket)
{
    while (1) {
        if (bucket->cursor == bucket->chunks.size()) {
            bucket->chunks.push_back(chunk);
            bucket->cursor = bucket->cursor + 1;
            return 1;
        } else {
            Chunk* oldChunk = bucket->chunks[bucket->cursor];
            Bucket* oldBucket = findBucket(oldChunk);
            if (oldBucket == bucket) {
                bucket->cursor = bucket->cursor + 1;
            } else {
                bucket->chunks[bucket->cursor] = chunk;
                return insert(oldChunk, oldBucket) + 1;
            }
        }
    }
}
