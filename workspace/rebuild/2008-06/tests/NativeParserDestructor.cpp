#include "v8xml/XmlSerializer.h"

void destroyNativeTextXmlParser(TextXmlParser* parser)
{
    parser->~TextXmlParser();
}
