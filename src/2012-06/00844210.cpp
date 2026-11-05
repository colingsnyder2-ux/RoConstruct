// from server: 81% by atomic.potato
extern "C" void* sub_833810(void*, int, void*);
extern "C" void sub_5727e0(void*);

int sub_844210(void* value)
{
    void* result = sub_833810(value, 1, *(void**)0x00de13e8);
    sub_5727e0(result);
    return 0;
}
