// from server: 100% by colin





struct DxUserInput
{
};

bool __cdecl isMouseButtonDown(int button, int state)
{
    switch (button)
    {
    case 0:
        return state == 0;
    case 1:
    case 2:
        return state == 0 || state == 1;
    case 3:
    case 4:
        return state == 0 || state == 3;
    case 5:
    case 6:
        return true;
    default:
        return false;
    }
}
