// from server: 57% by atomic.potato
extern "C" int __cdecl Call677e50(int);
extern "C" int Call67bc70(void *, int);
extern "C" int __cdecl Call63c310(int, int);

struct StopCommand
{
    int Unknown00;
    int Unknown04;
    int Unknown08;
    int Unknown0C;
    int Unknown10;
    int f(int);
};

int StopCommand::f(int value)
{
    int saved = Unknown0C;
    Call677e50(saved);
    int result = Call67bc70(&Unknown10, 1);
    return Call63c310(result, 2);
}
