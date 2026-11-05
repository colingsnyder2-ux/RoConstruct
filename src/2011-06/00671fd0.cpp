// from server: 47% by atomic.potato
extern "C" void __cdecl Target411f60();

struct S
{
    float pad[110];
    void ActionStation(float value);
};

void S::ActionStation(float value)
{
    if (value == pad[110] || value != value)
        return;

    pad[110] = value;
    Target411f60();
}
