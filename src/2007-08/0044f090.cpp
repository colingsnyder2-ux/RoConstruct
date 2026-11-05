// from server: 24% by colin
struct CameraTiltUpCommand {
    void doIt(int* dataState);
};

extern "C" int __stdcall pubsink(void*);

void CameraTiltUpCommand::doIt(int* dataState)
{
    int* p = (int*)*dataState;
    if ((*(unsigned char*)((char*)this + 4) & 2) != 0)
    {
        p = (int*)((char*)p + 4);
        pubsink(p);
    }
}
