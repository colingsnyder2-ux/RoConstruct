// from server: 65% by Intel

struct WeakThreadRef {
    WeakThreadRef* next;
};

extern "C" int __stdcall string_compare(const char*, const char*);

int __stdcall find_weak_thread_ref(WeakThreadRef* head, const char* key)
{
    WeakThreadRef* current = head;
    if (!current)
        return 0;

    int (__stdcall *compare)(const char*, const char*) = string_compare;

    do {
        char* node_key = reinterpret_cast<char*>(current) - 0x60;
        if (compare(node_key, key))
            break;
        current = current->next;
    } while (current);

    return reinterpret_cast<int>(current);
}
