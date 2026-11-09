// from server: 100% by atomic.potato
void handleSpecial();
void handleCommon();

void __stdcall dispatchById(unsigned int id)
{
    if (id == 0xc1ee14u) {
        handleSpecial();
        return;
    }
    if (id == 0xc1a904u || id == 0xc1a8e4u || id == 0xc1a924u) {
        handleCommon();
    }
}
