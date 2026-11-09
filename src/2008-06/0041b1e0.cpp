// from server: 100% by king_originala
struct Marshaller
{
    int dispatch(int message, int wparam, int lparam, int* handled);
    int execute(int window, int message, int wparam, int lparam,
                int* result, int handled);
};

int Marshaller::execute(int window, int message, int wparam, int lparam,
                        int* result, int handled)
{
    if (handled == 0 && message == 0x465)
    {
        *result = dispatch(0x465, wparam, lparam, &handled);
        return 1;
    }
    return 0;
}
