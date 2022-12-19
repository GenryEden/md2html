//
// Created by hdefalt on 05.12.22.
//

#ifndef REGEXMDTOHTML_BOLDANDITALIC_H
#define REGEXMDTOHTML_BOLDANDITALIC_H


#include "AbstractFormatter.h"

/**
 * Context of format for bold and/or italic
 */
class BoldAndItalic : public AbstractFormatter {
public:
    DocPart findMatch(const std::string &markdown) override;

    std::string toHTML(const std::string &markdown) override;

private:
    static std::regex regular;
};


#endif //REGEXMDTOHTML_BOLDANDITALIC_H
