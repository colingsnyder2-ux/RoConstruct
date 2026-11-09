// from server: 31% by colin
extern "C" int __stdcall sgetn_impl(void*, char*, int);

struct StreamBuf {
    char pad[0x3c];
    char flags;
};

struct Allocator {
    int compare(int*, int*);
    int func(int* a, int* b, int c, int d, int e, int f);
};

int Allocator::func(int* a, int* b, int c, int d, int e, int f)
{
    int* p = a;
    int* q = b;
    int state = c;
    int val1 = d;
    int val2 = e;
    int val3 = f;
    int result;

    if (state == 6) {
        if (*p == *q)
            return val1 - val3;
    }
    if (val1 == val2)
        return val1 - val3;

    if (state == 5) {
        int* obj = *(int**)p;
        int n1 = *(int*)((char*)obj + 0x18);
        int n2 = *(int*)((char*)obj + 0x14);
        StreamBuf* sb = (StreamBuf*)val3;
        int r = sgetn_impl(sb, (char*)n2, n1);
        int diff;
        if (r != 0)
            diff = r;
        else {
            char fl = sb->flags;
            diff = (fl != 0) ? -1 : 0;
        }
        if (diff == -1) {
            *(int*)((char*)obj + 0x24) |= 4;
        } else {
            int base = *(int*)((char*)obj + 0x14);
            *(int*)((char*)obj + 0x1c) = base;
            *(int*)((char*)obj + 0x20) = base + diff;
            int* obj2 = *(int**)p;
            int neq = (diff != *(int*)((char*)obj2 + 0x18));
            state = neq + 5;
        }
    }

    if (val1 == val3)
        return val1 - val3;
    return -1;
}
