//
// Created by hdefalt on 05.12.22.
//

#ifndef REGEXMDTOHTML_ABSTRACTFORMATTER_H
#define REGEXMDTOHTML_ABSTRACTFORMATTER_H


#include <string>
#include <regex>
#include "../DocPart.h"

/**
 * Abstract context of format
 */
class AbstractFormatter {
public:
    /**
     * finds first occurance of context in document
     * @param markdown document
     * @return params of occurance
     */
    virtual DocPart findMatch(const std::string &markdown) = 0;

    /**
     * converts first occurance to HTML tag
     * @param markdown document
     * @return string of html tagged part
     */
    virtual std::string toHTML(const std::string &markdown) = 0;
};


#endif //REGEXMDTOHTML_ABSTRACTFORMATTER_H
