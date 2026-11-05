// from server: 0% by atomic.potato
extern "C" void* __cdecl sub_58F7B0(unsigned int, int);
extern "C" void __cdecl sub_6A2780();
extern "C" void __cdecl sub_982114(void*);

struct PoolData {
    char pad0[4];
    int* begin;
    int* end;
    int* cap;
    void insert(int* pos, unsigned int count, int* first, int* last);
};

void __cdecl sub_864AD0(PoolData* self, int* dst, unsigned int count, int* src);
void __cdecl sub_864180(int* dst, int* src, PoolData* self, int* a, int* b, int c);
void __cdecl sub_864560(int* a, int* b, PoolData* self, int* c);

void PoolData::insert(int* pos, unsigned int count, int* first, int* last)
{
    int* oldBegin = begin;
    unsigned int oldSize;
    if (oldBegin != 0)
        oldSize = 0;
    else
        oldSize = (unsigned int)((cap - oldBegin) >> 2);

    if (count == 0)
        return;

    unsigned int used = (unsigned int)((end - oldBegin) >> 2);
    if (0x3FFFFFFF - used < count)
        sub_6A2780();

    unsigned int newSize = used + count;
    if (oldSize < newSize)
    {
        unsigned int grown = oldSize + (oldSize >> 1);
        if (0x3FFFFFFF - (oldSize >> 1) < oldSize)
            grown = 0;
        if (grown < newSize)
            grown = newSize;
        int* newBuf = (int*)sub_58F7B0(grown * 4, 0);
        int offset = (int)((pos - begin) >> 2);
        sub_864AD0(this, newBuf + offset, count, first);
        sub_864180(begin, pos, this, newBuf, newBuf + offset, 0);
        sub_864180(pos, end, this, newBuf + offset + count, end, 0);
        int* oldB = begin;
        int* oldE = end;
        if (oldB != 0)
        {
            sub_864560(oldB, oldE, this, 0);
            sub_982114(oldB);
        }
        begin = newBuf;
        end = newBuf + (offset + count + (int)((oldE - oldB) >> 2)) * 4;
        cap = newBuf + grown * 4;
    }
    else
    {
        int* oldEnd = end;
        int tail = (int)((oldEnd - pos) >> 2);
        if ((unsigned int)tail >= count)
        {
            sub_864AD0(this, oldEnd, count, oldEnd - count);
            sub_864180(pos, oldEnd - count, this, pos + count, oldEnd, 0);
            sub_864180(pos, pos + count, this, first, last, 0);
        }
        else
        {
            sub_864AD0(this, oldEnd, tail, pos);
            sub_864180(pos, oldEnd, this, first, first + tail, 0);
            sub_864180(first + tail, last, this, end, end, 0);
        }
        end = end + count;
    }
}
