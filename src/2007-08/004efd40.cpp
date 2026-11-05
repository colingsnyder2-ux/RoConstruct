// from server: 46% by colin
struct WeakReferenceCountedPointer {
    void* ptr;
    void* link;
    void construct(void** src);
};

void __stdcall sub_4cd890();
void* __cdecl sub_62fef6(unsigned int size);

void WeakReferenceCountedPointer::construct(void** src)
{
    this->ptr = (void*)0x79f53c;
    this->link = 0;
    void* p = *src;
    sub_4cd890();
    if (p) {
        this->link = p;
        void* node = sub_62fef6(8);
        if (node) {
            void* next = *(void**)((char*)this->link + 8);
            *(void**)node = this;
            *(void**)((char*)node + 4) = next;
        } else {
            node = 0;
        }
        *(void**)((char*)this->link + 8) = node;
    }
}
