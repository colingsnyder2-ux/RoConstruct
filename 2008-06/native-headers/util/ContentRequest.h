#pragma once
#include <iosfwd>
#include <string>
#include <boost/function.hpp>
#include <boost/shared_ptr.hpp>

namespace RBX {
enum RequestResult { Waiting, Succeeded, Failed };
typedef boost::function<void(RequestResult, std::istream&)> RequestCallback;
void readContent(RequestCallback, RequestResult, boost::shared_ptr<const std::string>);
}
