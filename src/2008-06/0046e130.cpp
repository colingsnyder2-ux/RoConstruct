// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreTangentSpaceCalc.cpp

struct Tile {
    char data[64];
};

extern void copyTile(Tile* dst, const Tile* src);

static void copyBackward(Tile* first, Tile* last, Tile* destLast)
{
    while (last != first) {
        copyTile(destLast - 1, last - 1);
        --last;
        --destLast;
    }
}
