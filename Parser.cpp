//
// Created by hdefalt on 08.12.22.
//

#include <iostream>
#include "Parser.h"
#include "Formatters/Header.h"
#include "Formatters/BoldAndItalic.h"
#include "Formatters/Code.h"
#include "Formatters/Image.h"
#include "Formatters/LaTeX.h"
#include "Formatters/URL.h"
#include "Formatters/Linebreak.h"
#include "Formatters/Line.h"

Parser::Parser() {
    numOfFormatters = 8;
    formatters = new AbstractFormatter *[numOfFormatters];
    formatters[0] = new Header();
    formatters[1] = new BoldAndItalic();
    formatters[2] = new Code();
    formatters[3] = new Image();
    formatters[4] = new LaTeX();
    formatters[5] = new URL();
    formatters[6] = new Line();
    formatters[7] = new Linebreak();
}

/**
 * Converts Markdown tags to HTML
 *
 * @param markdown - string of markdown document
 *
 * @return string of the html tags (not a document, just tagged text)
 */
std::string Parser::toHTML(const std::string &markdown) {
    std::string ans = "";
    std::string nowParse = "\n \n" + markdown + "\n \n";
    while (true) {
        AbstractFormatter *firstFormatter = formatters[0];
        DocPart firstPart = formatters[0]->findMatch(nowParse);
        for (int i = 1; i < numOfFormatters; i++) {
            DocPart foundPart = formatters[i]->findMatch(nowParse);
            if (firstPart.start > foundPart.start) {
                firstPart = foundPart;
                firstFormatter = formatters[i];
            }
        }
        if (firstPart.len == 0) {
            break;
        }
        ans += nowParse.substr(0, firstPart.start);
        ans += firstFormatter->toHTML(nowParse);
        nowParse = nowParse.substr(firstPart.start + firstPart.len);
    }
    return ans;
}

Parser::~Parser() {
    for (int i = 0; i < numOfFormatters; i++) {
        delete formatters[i]; // FIXME
    }
    delete[] formatters;
}

