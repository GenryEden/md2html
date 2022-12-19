//
// Created by hdefalt on 16.12.22.
//

#ifndef REGEXMDTOHTML_LINEBREAK_H
#define REGEXMDTOHTML_LINEBREAK_H


#include "AbstractFormatter.h"

/**
 * Context of format for linebreak
 */
class Linebreak: public AbstractFormatter {
public:
    DocPart findMatch(const std::string &markdown) override;

    std::string toHTML(const std::string &markdown) override;
private:
    static std::regex regular;
};


#endif //REGEXMDTOHTML_LINEBREAK_H
