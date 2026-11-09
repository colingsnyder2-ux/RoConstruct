// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Command {
    char storage[0xcc];
    Command(void*);
};

Command* __cdecl createCommand(void* argument)
{
    return new Command(argument);
}
