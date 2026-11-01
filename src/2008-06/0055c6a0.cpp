// from server: 100% by king_originala
struct Stream {
    int* offsets;
    int count;
};

extern void (__thiscall *clear_stream)(void*, int, bool);
extern Stream& (__thiscall *seek_stream)(Stream*, long, int);
extern Stream& (__thiscall *read_stream)(Stream*, char*, int);

struct Hasher {
    virtual void update(const char*, int);
    void hash(Stream&);
};

void Hasher::hash(Stream& stream)
{
    char buffer[1024];
    clear_stream(reinterpret_cast<char*>(&stream) + stream.offsets[1], 0, false);
    seek_stream(&stream, 0, 0);
    do {
        read_stream(&stream, buffer, 1024);
        update(buffer, stream.count);
    } while (stream.count > 0);
}
