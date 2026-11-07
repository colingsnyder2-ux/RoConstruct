#pragma once
// >>> native-status (generated) -- do not edit >>>
// ContentRequest | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 0cd0bc7d | roc native-status --write
#include <iosfwd>
#include <string>
#include <boost/function.hpp>
#include <boost/shared_ptr.hpp>

namespace RBX {
enum RequestResult { Waiting, Succeeded, Failed };
typedef boost::function<void(RequestResult, std::istream&)> RequestCallback;
void readContent(RequestCallback, RequestResult, boost::shared_ptr<const std::string>);
}
