// from server: 100% by colin
struct ChunkData {
    char padding[0x1d5];
    bool flag;
};

struct PartChunk {
    char padding[0xb0];
    ChunkData* data;
    bool getFlag() const;
};

bool PartChunk::getFlag() const
{
    return data->flag;
}
