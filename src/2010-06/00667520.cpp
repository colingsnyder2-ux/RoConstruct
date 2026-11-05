// from server: 100% by tester
struct S
{
    void ActionStation(int* result);
    int pad[162];
};

void S::ActionStation(int* result)
{
    if (pad[162] == 1)
        return;

    *result = 0;
}
