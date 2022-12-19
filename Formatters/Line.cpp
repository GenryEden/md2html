//
// Created by hdefalt on 18.12.22.
//

#include "Line.h"
#include "../Templater.h"
#include "../nlohmann/json.hpp"

std::regex Line::regular("\n{1}\\s*---\\s*\n{1}");

DocPart Line::findMatch(const std::string &markdown) {
    std::smatch m;
    std::regex_search(markdown, m, regular);
    return {m.position(), m.length()};
}

std::string Line::toHTML(const std::string &markdown) {
    return Templater::renderFormat("HLine.html", nlohmann::json());
}
