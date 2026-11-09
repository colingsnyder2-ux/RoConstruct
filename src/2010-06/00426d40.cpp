// from server: 100% by atomic.potato
extern "C" void* __cdecl operator_new(unsigned int size);

struct Holder {
    float* allocate();
};

float* Holder::allocate() {
    float* result = static_cast<float*>(operator_new(8));
    if (result) {
        *reinterpret_cast<int*>(result) = 0xA046C8;
        result[1] = *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 4);
    } else {
        result = 0;
    }
    return result;
}
