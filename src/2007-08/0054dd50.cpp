// from server: 29% by colin
struct StreamBuf {
    char pad0[0x14];
    char* p14;
    char* p18;
    char* p1c;
    char* p20;
    char pad24[0x24 - 0x20];
    unsigned int flags24;
};

struct OutIter {
    char pad0[8];
    char* p8;
    char* pc;
};

struct S {
    StreamBuf* sb;
    int f(OutIter* first, OutIter* last, int n);
};

extern "C" int __stdcall memmove_s(void*, unsigned int, const void*, unsigned int);
extern "C" int __stdcall sputn(StreamBuf*, const char*, int);
extern "C" int __stdcall sub_5cc990(StreamBuf*, void*, void*, void*);
extern "C" int __stdcall sub_5cca30(StreamBuf*, void*);
extern "C" int __stdcall sub_5cc9c0(StreamBuf*, void*, void*, int);
extern "C" int __stdcall sub_5cc8e0(int);
extern void* G_7ba5a4;

int S::f(OutIter* first, OutIter* last, int n)
{
    StreamBuf* sb = this->sb;
    if (!(sb->flags24 & 2)) {
        sb->flags24 |= 2;
        sb->p1c = sb->p14;
        sb->p20 = sb->p14 + (int)sb->p18;
    }

    char* cur = (char*)n;
    char* end = (char*)n + (int)first;
    char* base = (char*)sb + 0x14;

    if (cur == end)
        return (int)cur - (int)end;

    OutIter* it = first;
    while (1) {
        if (it->p8 == it->pc) {
            int avail = (int)(sb->p1c - sb->p14);
            int written = sputn(sb, sb->p14, avail);
            if (written < avail && written > 0) {
                memmove_s(sb->p14, avail - written, sb->p14 + written, avail - written);
            }
            sb->p1c = sb->p14 + (avail - written);
            sb->p20 = sb->p14 + (int)sb->p18;
            if (written == 0) {
                cur = (char*)n;
                break;
            }
            it = first;
        }
        sub_5cc990(sb, it->p8, it->pc, &cur);
        int r = sub_5cca30(sb, G_7ba5a4);
        sub_5cc9c0(sb, it->p8, &cur, 0);
        sub_5cc8e0(r);
        if (cur == end)
            break;
        it = first;
    }
    return (int)cur - (int)end;
}
