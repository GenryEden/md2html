//
// Created by hdefalt on 06.12.22.
//

#ifndef REGEXMDTOHTML_URL_H
#define REGEXMDTOHTML_URL_H


#include "AbstractFormatter.h"

/**
 * Context of format for URLs
 */
class URL : public AbstractFormatter {
public:
    DocPart findMatch(const std::string &markdown) override;

    std::string toHTML(const std::string &markdown) override;

private:
    static std::regex regular;
};


#endif //REGEXMDTOHTML_URL_H
