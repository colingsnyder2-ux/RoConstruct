#define NATIVE_CONTENT_PROVIDER_TYPES_ONLY
#include "NativeContentProviderTrial.cpp"
#include "util/standardout.h"
#include <sstream>

namespace RBX {
void readContent(RequestCallback callback, RequestResult result, boost::shared_ptr<const std::string> text)
{
    try {
        std::istringstream input(*text);
        callback(result, input);
    } catch (std::exception& error) {
        StandardOut::singleton()->print(MESSAGE_ERROR, "ContentProvider callback exception: %s", error.what());
    }
}
}
