//
// Created by hdefalt on 05.12.22.
//

#ifndef REGEXMDTOHTML_HEADER_H
#define REGEXMDTOHTML_HEADER_H


#include "AbstractFormatter.h"

/**
 * Context of format for headers
 */
class Header : public AbstractFormatter {
public:
    DocPart findMatch(const std::string &markdown) override;

    std::string toHTML(const std::string &markdown) override;

private:
    static std::regex regular;
};


#endif //REGEXMDTOHTML_HEADER_H
