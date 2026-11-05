// from server: 37% by Intel
extern "C" void __cdecl func_00518d80(void*, int, void*);

struct Vector
{
    int* begin;
    int* end;
    int* capacity_end;

    int push_back(int value);
};

int Vector::push_back(int value)
{
    int* first = begin;
    if (!first)
    {
        return 0;
    }
    int* last = end;
    int capacity = (reinterpret_cast<char*>(capacity_end) - reinterpret_cast<char*>(first)) >> 2;
    int size = (reinterpret_cast<char*>(last) - reinterpret_cast<char*>(first)) >> 2;
    if (size < capacity)
    {
        *last = value;
        end = last + 1;
        return 1;
    }
    int* arg_ptr = &value;
    func_00518d80(this, 1, arg_ptr);
    return 1;
}
