#include <g3d/platform.h>
#include <graphics3d.h>

using namespace G3D;

void printHelp();
bool isDirectory(const std::string& filename);
/** Adds a slash to a directory, if not already there. */
std::string maybeAddSlash(const std::string& in);
int main(int argc, char** argv);


void copyIfNewer(bool exclusions, std::string sourcespec, std::string destspec) {

    if (G3D::isDirectory(sourcespec)) {
        // Copy an entire directory.  Change the arguments so that
        // we copy the *contents* of the directory.

        sourcespec = maybeAddSlash(sourcespec);
        sourcespec = sourcespec + "*";
    }

    std::string path = filenamePath(sourcespec);

    Array<std::string> fileArray;
    Array<std::string> dirArray;

    getDirs(sourcespec, dirArray);
    getFiles(sourcespec, fileArray);

    destspec = maybeAddSlash(destspec);

    if (fileExists(destspec) && ! G3D::isDirectory(destspec)) {
        printf("A file already exists named %s.  Target must be a directory.", 
            destspec.c_str());
        exit(-2);
    }
    createDirectory(destspec);

    for (int f = 0; f < fileArray.length(); ++f) {
        if (! exclusions || (fileArray[f][0] != '~')) {
            std::string s = path + fileArray[f];
            std::string d = destspec + fileArray[f];
            if (true || fileIsNewer(s, d)) {
                printf("copy %s %s\n", s.c_str(), d.c_str());
                copyFile(s, d);
            }
        }
    }

    // Directories just get copied; we don't check their dates.
    // Recurse into the directories
    for (int d = 0; d < dirArray.length(); ++d) {
        if (! exclusions || (dirArray[d] != "CVS")) {
            copyIfNewer(exclusions, path + dirArray[d], destspec + dirArray[d]);
        }
    }
}



int main(int argc, char** argv) {

    if (((argc == 2) && (std::string("--help") == argv[1])) || (argc < 3) || (argc > 4)) {
        printHelp();
        return -1;
    } else {
        bool e = false;
        std::string s, d;
        if (std::string("--exclusions") == argv[1]) {
            e = true;
            s = argv[2];
            d = argv[3];
        } else {
            s = argv[1];
            d = argv[2];
        }

        copyIfNewer(e, s, d);
    }
    
    return 0;
}


void printHelp() {
    printf("COPYIFNEWER\n\n");
    printf("SYNTAX:\n\n");
    printf(" copyifnewer [--help] [--exclusions] <source> <destdir>\n\n");
    printf("ARGUMENTS:\n\n");
    printf("  --exclusions  If specified, exclude CVS and ~ files. \n\n");
    printf("  source   Filename or directory name (trailing slash not required).\n");
    printf("           May include standard Win32 wild cards in the filename.\n");
    printf("  dest     Destination directory, no wildcards allowed.\n\n");
    printf("PURPOSE:\n\n");
    printf("Copies files matching the source specification to the dest if they\n");
    printf("do not exist in dest or are out of date (according to the file system).\n\n");
    printf("Compiled: " __TIME__ " " __DATE__ "\n"); 
}


std::string maybeAddSlash(const std::string& sourcespec) {
    if (sourcespec.length() > 0) {
        char last = sourcespec[sourcespec.length() - 1];
        if ((last != '/') && (last != ':') && (last != '\\')) {
            // Add a trailing slash
            return sourcespec + "/";
        }
    }
    return sourcespec;
}
