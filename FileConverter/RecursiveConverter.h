//
// Created by hdefalt on 18.12.22.
//

#ifndef REGEXMDTOHTML_RECURSIVECONVERTER_H
#define REGEXMDTOHTML_RECURSIVECONVERTER_H


#include <string>


/**
 * represents all of files and (sub)directories in HTML format
 */
class RecursiveConverter {
public:
    static void convert(const std::string &from, const std::string &to);
};


#endif //REGEXMDTOHTML_RECURSIVECONVERTER_H
