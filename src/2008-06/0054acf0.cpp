// from server: 100% by king_originala
struct Mesh {
    char pad[0x7f4];
    bool value;
    bool get();
};

#pragma optimize("", off)
bool Mesh::get()
{
    return value;
}
#pragma optimize("", on)
