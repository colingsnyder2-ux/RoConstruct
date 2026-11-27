// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct FMOD_CHANNEL;
extern "C" int __stdcall FMOD_Channel_GetUserData(FMOD_CHANNEL *, void **);
struct Item { void release(); };
int __stdcall callback(FMOD_CHANNEL *channel, int type, void *d1, void *d2)
{
    if (type == 0) {
        Item *item;
        FMOD_Channel_GetUserData(channel, (void **)&item);
        if (item)
            item->release();
    }
    return 0;
}