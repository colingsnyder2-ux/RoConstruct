// from server: 100% by king_originala
struct Helper { int padding[3]; int value; };
struct HelperMaker { Helper* makeHelper(); };
struct HelperDestroyer { void destroyHelper(); };
struct ContentProvider { int getCachedRemoteSourceLoadState(); };

int ContentProvider::getCachedRemoteSourceLoadState() {
    char buf[0x84];
    Helper* h = ((HelperMaker*)buf)->makeHelper();
    int result = h->value;
    ((HelperDestroyer*)buf)->destroyHelper();
    return result;
}
