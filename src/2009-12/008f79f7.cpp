// from server: 59% by atomic.potato
extern "C" void __stdcall sub_008fb2b4(int);

extern "C" void __cdecl external_call(const char*, float, float, float);

void __stdcall func_008f79f7(const char* text, float a, float b, float c)
{
    sub_008fb2b4(1);
    external_call(text, a, b, c);
}
