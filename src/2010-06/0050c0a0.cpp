// from server: 41% by atomic.potato
struct NetworkOwnerJob
{
    NetworkOwnerJob();
};

NetworkOwnerJob::NetworkOwnerJob()
{
    *(int*)((char*)this + 0x00) = 0;
    *(int*)((char*)this + 0x04) = (int)((char*)this + 0x04);
    *(int*)((char*)this + 0x08) = (int)((char*)this + 0x04);
    *(int*)((char*)this + 0x0c) = 0;
}
