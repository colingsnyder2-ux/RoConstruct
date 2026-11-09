// from server: 83% by atomic.potato
extern "C" void __cdecl Function_007f4929(const char*);

unsigned char& Global_00b7b47c = *(unsigned char*)0x00b7b47c;
int& Global_00b7b478 = *(int*)0x00b7b478;

void Function_0044dc70()
{
    if (!Global_00b7b47c)
    {
        Global_00b7b47c |= 1;
        Function_007f4929("8csm");
        Global_00b7b478 = 0;
    }
}
