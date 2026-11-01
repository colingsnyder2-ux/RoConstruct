// from server: 44% by atomic.potato
extern "C" void __stdcall Imported(void*);

void __stdcall RefItem(void* value)
{
    Imported(value);
}
