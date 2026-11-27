// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD

struct Stream;
struct Guid { int v; };
void writeType(Stream* s, int t);
void writeFlag(Stream* s, int f);
void writeGuid(Stream* s, Guid* g);
struct PingItem {
    char pad[0x20];
    Guid id;
    bool write(Stream* s);
};
bool PingItem::write(Stream* s) {
    writeType(s, 5);
    writeFlag(s, 0);
    writeGuid(s, &id);
    return true;
}
