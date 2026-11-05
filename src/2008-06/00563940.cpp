// from server: 100% by king_originala
struct Helper {
    char padding[0x64];
    int field64;
};
struct HelperMaker { Helper* makeHelper(); };
struct HelperDestroyer { void destroyHelper(); };
struct ContentProvider { int getCachedRemoteSourceLoadState(); };

int ContentProvider::getCachedRemoteSourceLoadState() {
    char buf[0x84];
    HelperMaker* m = (HelperMaker*)buf;
    Helper* h = m->makeHelper();
    int result = h->field64;
    HelperDestroyer* d = (HelperDestroyer*)buf;
    d->destroyHelper();
    return result;
}
