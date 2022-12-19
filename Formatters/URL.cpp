//
// Created by hdefalt on 06.12.22.
//

#include "URL.h"
#include "../nlohmann/json.hpp"
#include "../Templater.h"

std::regex URL::regular = std::regex(R"(\[([^\]]*?)\]\(([^\]]*?)\))");

DocPart URL::findMatch(const std::string &markdown) {
    std::smatch m;
    std::regex_search(markdown, m, regular);
    return {m.position(), m.length()};
}

std::string URL::toHTML(const std::string &markdown) {
    std::smatch m;
    std::regex_search(markdown, m, regular);
    nlohmann::json data = nlohmann::json();
    data["val"] = m[1];
    data["link"] = m[2];
    return Templater::renderFormat("URL.html", data);
}
