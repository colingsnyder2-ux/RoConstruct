// from server: 39% by colin
struct Replicator;

struct ChangePropertyItem {
    void* vtable;
};

extern "C" void __cdecl sub_417800();
extern "C" void* __cdecl sub_442C00(unsigned int, int);
extern "C" void* __cdecl sub_4A8540(void*, void*, void*, void*, void*, void*, void*, void*);
extern "C" void* __cdecl sub_4AADB0(void*, void*, void*, void*);
extern "C" void __cdecl sub_4AB0E0(void*, void*, void*);
extern "C" void __cdecl sub_62FC62(void*);
extern "C" void __cdecl sub_728220(void*, void*);

struct Replicator_DeleteInstanceItem {
    void* vtable;
    ChangePropertyItem* begin;
    ChangePropertyItem* end;
    ChangePropertyItem* capacity;
    void DeleteInstanceItem(void* a, void* b, void* c);
};

void Replicator_DeleteInstanceItem::DeleteInstanceItem(void* a, void* b, void* c)
{
    char local_28[0x10];
    sub_728220(local_28, c);

    ChangePropertyItem* first = this->begin;
    int count = 0;
    if (first == 0) {
        count = (int)((char*)this->end - (char*)first) >> 4;
    }

    int n = (int)b;
    if (n != 0) {
        int cur = 0;
        if (first != 0) {
            cur = (int)((char*)this->end - (char*)first) >> 4;
        }
        if ((unsigned int)(0x0FFFFFFF - cur) < (unsigned int)n) {
            sub_417800();
        }
        int cur2 = 0;
        if (first != 0) {
            cur2 = (int)((char*)this->end - (char*)first) >> 4;
        }
        if ((unsigned int)count < (unsigned int)(cur2 + n)) {
            int half = count >> 1;
            if ((unsigned int)(0x0FFFFFFF - half) < (unsigned int)count) {
                count = 0;
            } else {
                count += half;
            }
            int cur3 = 0;
            if (first != 0) {
                cur3 = (int)((char*)this->end - (char*)first) >> 4;
            }
            if ((unsigned int)count < (unsigned int)(cur3 + n)) {
                int cur4 = 0;
                if (first != 0) {
                    cur4 = (int)((char*)this->end - (char*)first) >> 4;
                }
                count = cur4 + n;
            }
            void* mem = sub_442C00(count, 0);
            void* oldBegin = this->begin;
            void* p = sub_4A8540(mem, oldBegin, this->end, this, mem, a, 0, 0);
            void* q = sub_4AADB0(this, p, (void*)n, local_28);
            void* oldEnd = this->end;
            sub_4A8540(oldEnd, q, this, q, a, 0, 0, 0);
            if (this->begin != 0) {
                sub_4AB0E0(this, this->begin, this->end);
                sub_62FC62(this->begin);
            }
            n = (int)((char*)this->end - (char*)this->begin) >> 4;
            n += (int)b;
            this->capacity = (ChangePropertyItem*)((char*)mem + (count << 4));
            this->end = (ChangePropertyItem*)((char*)mem + (n << 4));
            this->begin = (ChangePropertyItem*)mem;
        }
    }
}
