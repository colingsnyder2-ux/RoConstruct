// from server: 38% by Intel
struct Vector8
{
    void *data;
    int size;
    int capacity;

    void insert(const void *element, int index, int arg3, int arg4);
};

extern "C" void *__stdcall allocate_memory(int size, int arg3, int arg4);
extern "C" void __stdcall debug_free(void *ptr, int size, int alignment, const char *file);
extern "C" void __stdcall free_header(void *header);

void Vector8::insert(const void *element, int index, int arg3, int arg4)
{
    if (size == capacity) {
        int new_capacity = capacity;
        if (new_capacity == 0) {
            new_capacity = 16;
        } else {
            new_capacity += new_capacity;
        }
        capacity = new_capacity;

        void *new_data = allocate_memory(new_capacity, arg3, arg4);
        void *old_data = data;

        if (size > 0) {
            const int *src = static_cast<const int *>(old_data);
            int *dst = static_cast<int *>(new_data);
            for (int i = 0; i < size; ++i) {
                dst[i * 2] = src[i * 2];
                dst[i * 2 + 1] = src[i * 2 + 1];
            }
        }

        if (old_data) {
            int *header = static_cast<int *>(old_data) - 1;
            int block_size = *header;
            debug_free(old_data, block_size, 8, "SQRP\\$$VW");
            free_header(header);
        }

        data = new_data;
    }

    int *buffer = static_cast<int *>(data);
    for (int i = size; i > index; --i) {
        buffer[i * 2] = buffer[(i - 1) * 2];
        buffer[i * 2 + 1] = buffer[(i - 1) * 2 + 1];
    }

    const int *elem = static_cast<const int *>(element);
    buffer[index * 2] = elem[0];
    buffer[index * 2 + 1] = elem[1];

    ++size;
}
