// from server: 62% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct ChatLineResult
{
    void* first;
    void* second;
};

struct ChatLine
{
    void get(ChatLineResult*);
};

void ChatLine::get(ChatLineResult* result)
{
    result->first = *(void**)((char*)this + 0x80);
    void* value = *(void**)((char*)this + 0x84);
    result->second = value;
    if (value != 0)
        _InterlockedExchangeAdd((volatile long*)((char*)value + 4), 1);
}
