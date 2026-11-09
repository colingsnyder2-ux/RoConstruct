// from server: 100% by king_originala
struct AggregateChunk {
    char padding[0x61];
    bool value;
    bool getValue();
};

#pragma optimize("", off)
bool AggregateChunk::getValue() {
    return value;
}
#pragma optimize("", on)
