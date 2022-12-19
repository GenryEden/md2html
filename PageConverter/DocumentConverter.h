//
// Created by hdefalt on 10.12.22.
//

#ifndef REGEXMDTOHTML_DOCUMENTCONVERTER_H
#define REGEXMDTOHTML_DOCUMENTCONVERTER_H


#include <string>

/**
 * Converter of Markdown document to HTML
 */
class DocumentConverter {
public:
    static std::string convert(const std::string &markdown);
};


#endif //REGEXMDTOHTML_DOCUMENTCONVERTER_H
