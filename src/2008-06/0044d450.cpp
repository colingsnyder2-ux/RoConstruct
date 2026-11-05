// from server: 100% by king_originala
extern char type_descriptor;
extern void __cdecl manage(void*, void**, int, int);

void __cdecl dispatch(void* source, void** destination, int operation)
{
    if (operation != 3)
    {
        int savedOperation = operation;
        reinterpret_cast<unsigned char*>(&operation)[0] = 0;
        manage(source, destination, savedOperation, operation);
    }
    else
    {
        *destination = &type_descriptor;
    }
}
