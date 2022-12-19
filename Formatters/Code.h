//
// Created by hdefalt on 05.12.22.
//

#ifndef REGEXMDTOHTML_CODE_H
#define REGEXMDTOHTML_CODE_H


#include "AbstractFormatter.h"
#include "../DocPart.h"

/**
 * Context of format for Code block
 */
class Code : public AbstractFormatter {
public:
    DocPart findMatch(const std::string &markdown) override;

    std::string toHTML(const std::string &markdown) override;

private:
    static std::regex regular;
};


#endif //REGEXMDTOHTML_CODE_H
