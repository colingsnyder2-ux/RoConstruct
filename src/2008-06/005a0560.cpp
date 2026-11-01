// from server: 100% by king_originala
int __cdecl f(int a1)
{
    int* previous = *(int**)(a1 + 0x104);
    int* current = *(int**)((char*)previous + 0x104);
    while (*(int**)((char*)current + 0x104) != 0) {
        previous = current;
        current = *(int**)((char*)current + 0x104);
    }
    return *(int*)((char*)previous + 0x2e4);
}
