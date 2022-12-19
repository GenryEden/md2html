//
// Created by hdefalt on 05.12.22.
//

#ifndef REGEXMDTOHTML_LATEX_H
#define REGEXMDTOHTML_LATEX_H


#include <regex>
#include "AbstractFormatter.h"

/**
 * Context of format for LaTeX
 */
class LaTeX : public AbstractFormatter {
public:
    DocPart findMatch(const std::string &markdown) override;

    std::string toHTML(const std::string &markdown) override;

private:
    static std::regex regular;
};


#endif //REGEXMDTOHTML_LATEX_H
