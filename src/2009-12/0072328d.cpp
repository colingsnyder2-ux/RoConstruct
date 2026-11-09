// from server: 85% by atomic.potato
extern "C" void __cdecl sub_007F4878(int, int);

void __declspec(naked) f()
{
    sub_007F4878(0, 0);
}
