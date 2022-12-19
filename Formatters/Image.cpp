//
// Created by hdefalt on 06.12.22.
//

#include "Image.h"
#include "../nlohmann/json.hpp"
#include "../Templater.h"

std::regex Image::regular = std::regex(R"(!\[(.*?)\]\((.*?)\))");

DocPart Image::findMatch(const std::string &markdown) {
    std::smatch m;
    std::regex_search(markdown, m, regular);
    return {m.position(), m.length()};
}

std::string Image::toHTML(const std::string &markdown) {
    std::smatch m;
    std::regex_search(markdown, m, regular);
    nlohmann::json data = nlohmann::json();
    data["alt"] = m[1];
    data["src"] = m[2];
    return Templater::renderFormat("Image.html", data);
}
