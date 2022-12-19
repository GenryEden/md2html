//
// Created by hdefalt on 14.12.22.
//

#ifndef REGEXMDTOHTML_HTMLTOMDFILECONVERTER_H
#define REGEXMDTOHTML_HTMLTOMDFILECONVERTER_H

#include <string>

/**
 * Converts HTML file to MD file
 */
class HTMLtoMDFileConverter {
public:
    static void convert(const std::string & from, const std::string & to);
};


#endif //REGEXMDTOHTML_HTMLTOMDFILECONVERTER_H
