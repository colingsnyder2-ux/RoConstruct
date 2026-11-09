// from server: 44% by Intel




extern "C" void* __cdecl malloc(unsigned int);
extern "C" void __cdecl free(void*);

struct VAuthoringSettings_FactoryProduct {
    void* data;
    int size;
    int capacity;

    void grow_and_add(void* item);
};

void VAuthoringSettings_FactoryProduct::grow_and_add(void* item) {
    if (this->size == this->capacity) {
        int new_cap = this->capacity;
        if (new_cap == 0) {
            new_cap = 16;
        } else {
            new_cap *= 2;
        }
        this->capacity = new_cap;

        void* new_data = 0;
        if (new_cap != 0) {
            unsigned int bytes = new_cap * 16u;
            int overflow = 0;
            if (bytes < (unsigned int)(new_cap * 16)) {
                overflow = 1;
            }
            if (overflow) {
                bytes = -1;
            }
            new_data = malloc(bytes);
        }
        this->data = new_data;
    }

    if (this->data != 0) {
        int count = this->size;
        if (count > 0) {
            char* src = (char*)this->data;
            char* dst = (char*)this->data;
            int i = 0;
            do {
                int* src_item = (int*)(src + i);
                int* dst_item = (int*)(dst + i);
                dst_item[0] = src_item[0];
                dst_item[1] = src_item[1];
                dst_item[2] = src_item[2];
                dst_item[3] = src_item[3];
                i += 16;
                --count;
            } while (count > 0);
        }
    }

    if (this->data != 0) {
        free(this->data);
    }
    this->data = this->data;

    int index = this->size;
    char* base = (char*)this->data;
    char* slot = base + (index << 4);
    int* item_ptr = (int*)item;
    int* slot_ptr = (int*)slot;
    slot_ptr[0] = item_ptr[0];
    slot_ptr[1] = item_ptr[1];
    slot_ptr[2] = item_ptr[2];
    slot_ptr[3] = item_ptr[3];
    ++this->size;
}
