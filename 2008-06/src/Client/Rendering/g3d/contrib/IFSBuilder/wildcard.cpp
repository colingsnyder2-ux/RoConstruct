/**
  @file IFSBuilder/wildcard.cpp

  Code for handling filenames with wild cards.

  @maintainer Morgan McGuire, matrix@graphics3d.com

  @created 2002-04-04
  @edited  2002-04-04
 */ 

#include <G3DAll.h>

bool hasWildcard(
    std::string str) {

    return
        (str.find('*') != std::string::npos) ||
        (str.find('?') != std::string::npos);
}


std::string getFilename(
    const std::string& filename) {

    // Find the last slash
    int slIndex = filename.rfind("\\");
    int tmp = filename.rfind("/");
    if (tmp > slIndex) {
        slIndex = tmp;
    }

    int extIndex = filename.rfind(".");
    if (extIndex == std::string::npos) {
        extIndex = filename.length();
    }

    std::string result;
    result.assign(filename, slIndex + 1, extIndex - slIndex - 1);

    return result;
}


std::string getPath(
    const std::string& filename) {

    // Find the last slash
    int slIndex = filename.rfind("\\");
    int tmp = filename.rfind("/");
    if (tmp > slIndex) {
        slIndex = tmp;
    }

    std::string result;
    if (slIndex == -1) {
        result = "./";
    } else {
        result.assign(filename, 0, slIndex + 1);
    }

    return result;
}


std::string getExtension(
    const std::string &x) {

	// Search backwards for the period
	int i = x.length() - 1;
	while ((i > 0) && (x.at(i) != '.')) {
		i--;
	}

	// Return everything to the right of the period.
	return (std::string)(x.c_str() + (i + 1));
}

