//
// Created by hdefalt on 05.12.22.
//

#include "Header.h"
#include "../nlohmann/json.hpp"
#include "../Templater.h"

std::regex Header::regular = std::regex("\n[\\s]*([#]+) (.*?)\n");

DocPart Header::findMatch(const std::string &markdown) {
    std::smatch m;
    std::regex_search(markdown, m, regular);
    return {m.position(), m.length() == 0 ? 0 : m.length() - 1};
}

std::string Header::toHTML(const std::string &markdown) {
    std::smatch m;
    std::regex_search(markdown, m, regular);
    int len = ((std::string) m[1]).size();
    std::string val = m[2];
    nlohmann::json data;
    data["len"] = len;
    data["val"] = val;
    return Templater::renderFormat("Header.html", data);
}
