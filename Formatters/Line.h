//
// Created by hdefalt on 18.12.22.
//

#ifndef REGEXMDTOHTML_LINE_H
#define REGEXMDTOHTML_LINE_H


#include "AbstractFormatter.h"

/**
 * Context of format for line
 */
class Line: public AbstractFormatter {
public:
    DocPart findMatch(const std::string &markdown) override;

    std::string toHTML(const std::string &markdown) override;
private:
    static std::regex regular;
};


#endif //REGEXMDTOHTML_LINE_H
