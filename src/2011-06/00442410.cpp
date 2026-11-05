// from server: 100% by atomic.potato
extern "C" long (__stdcall *SendMessageA)(void *, unsigned int, unsigned int, long);

struct CProgressDialog
{
    void SetProgress(char);
};

void CProgressDialog::SetProgress(char value)
{
    SendMessageA(*(void **)((char *)this + 4), 0x465, value != 0, 0);
}
