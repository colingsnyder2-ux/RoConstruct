// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/content-cache-inline
// >>> native-status (generated) -- do not edit >>>
// ContentProviderLoadContent | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by king_originala (deepseek:deepseek-chat)
// <<< native-status | src e279c3e8 | roc native-status --write
#include "util/NativeContentProvider.h"
#include "util/ImageContent.h"
#include "util/Http.h"
#include <algorithm>

namespace RBX {
ContentProvider::CachedContent* ContentProvider::loadContent(ContentId id, int mode, const RequestCallback* callback) {
    if (id.isNull()) return NULL;
    {
        boost::mutex::scoped_lock lock(contentCacheMutex);
        std::map<ContentId,CachedContent>::iterator found = contentCache.find(id);
        if (found != contentCache.end()) return &found->second;
    }
    if (id.isAsset()) {
        boost::shared_ptr<const std::string> filename(new std::string(findAsset(id)));
        if (filename->empty()) return NULL;
        boost::mutex::scoped_lock lock(contentCacheMutex);
        CachedContent& content = contentCache[id];
        content.filename = filename;
        return &content;
    } else {
        boost::shared_ptr<const std::string> filename(new std::string(findHashFile(id)));
        if (!filename->empty()) {
            boost::mutex::scoped_lock lock(contentCacheMutex);
            CachedContent& content = contentCache[id];
            content.filename = filename;
            return &content;
        }
    }
    if (id.isHttp()) {
        switch(mode) {
        case 1: {
            boost::mutex::scoped_lock lock(requestSync);
            if (!isUrlBad(id.c_str())) {
                std::list<ContentRequest>::iterator found = std::find(requestQueue.begin(),requestQueue.end(),id);
                if (found == requestQueue.end()) {
                    requestQueue.push_back(ContentRequest());
                    ContentRequest& request = requestQueue.back();
                    request.id = id;
                    if (callback) request.callbacks.push_back(*callback);
                } else if (callback) {
                    found->callbacks.push_back(*callback);
                }
            }
            requestProcessor->wake();
            break;
        }
        case 2: {
            boost::shared_ptr<std::string> text(new std::string);
            try {
                Http(id.toString()).get(*text);
            } catch (std::exception&) {
                boost::mutex::scoped_lock lock(requestSync);
                {
                    FailedUrl failed(id.c_str());
                    failedUrls.push_front(failed);
                }
                throw;
            }
            boost::mutex::scoped_lock lock(contentCacheMutex);
            CachedContent& content = contentCache[id];
            content.data = text;
            return &content;
        }
        }
    }
    return NULL;
}
}
