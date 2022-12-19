//
// Created by hdefalt on 10.12.22.
//

#include <iostream>
#include "DocumentConverter.h"
#include "../Parser.h"
#include "../Templater.h"

/**
 * converts a Markdown document to HTML document
 * @param markdown string of a markdown document
 * @return string of HTML document
 */
std::string DocumentConverter::convert(const std::string &markdown) {
    Parser parser = Parser();
    nlohmann::json data;
    data["val"] = parser.toHTML(markdown);
    return Templater::renderPage("doc.html", data);
}
