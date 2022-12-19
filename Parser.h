//
// Created by hdefalt on 08.12.22.
//

#ifndef REGEXMDTOHTML_PARSER_H
#define REGEXMDTOHTML_PARSER_H


#include <string>
#include "Formatters/AbstractFormatter.h"

/**
 * Parser of markdown tags to HTML tags
 */
class Parser {
public:
    Parser();

    std::string toHTML(const std::string &markdown);

    virtual ~Parser();

private:
    int numOfFormatters;
    AbstractFormatter **formatters;
};


#endif //REGEXMDTOHTML_PARSER_H
