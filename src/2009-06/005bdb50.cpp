// from server: 28% by why2
struct RBX_AggregateChunk {
    char pad[0x59];
    unsigned char field_59;
    unsigned char get_59();
};

unsigned char RBX_AggregateChunk::get_59() {
    return field_59;
}
