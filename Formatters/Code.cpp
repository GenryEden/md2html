//
// Created by hdefalt on 05.12.22.
//

#include <iostream>
#include "Code.h"
#include "../DocPart.h"
#include "../nlohmann/json.hpp"
#include "../Templater.h"

//std::regex Code::regular = std::regex("```([^\n]*)\n(.*?)```");
//std::regex Code::regular = std::regex("\n```([^\n]*)\n([.|\n|\\s]*?)\n");
std::regex Code::regular = std::regex("```([^\n]*)\n([^]*?)\n```");

DocPart Code::findMatch(const std::string &markdown) {
    std::smatch m;
    std::regex_search(markdown, m, regular);
    return {m.position(), m.length()};
}

std::string Code::toHTML(const std::string &markdown) {
    std::smatch m;
    std::regex_search(markdown, m, regular);
    nlohmann::json data = nlohmann::json();
    data["lang"] = m[1];
    data["val"] = m[2];
    return Templater::renderFormat("Code.html", data);
}