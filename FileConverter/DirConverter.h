//
// Created by hdefalt on 16.12.22.
//

#ifndef REGEXMDTOHTML_DIRCONVERTER_H
#define REGEXMDTOHTML_DIRCONVERTER_H


#include <string>

/**
 * a converter of directory to its html representation
 */
class DirConverter {
public:
    static std::string convert(const std::string &dirName);
    static void toFile(const std::string &dirName, const std::string &whereTo);
};


#endif //REGEXMDTOHTML_DIRCONVERTER_H
