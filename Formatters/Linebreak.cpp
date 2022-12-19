//
// Created by hdefalt on 16.12.22.
//

#include "Linebreak.h"
#include "../Templater.h"

std::regex Linebreak::regular  = std::regex("\n[\\s]*?\n");

DocPart Linebreak::findMatch(const std::string &markdown) {
    std::smatch m;
    std::regex_search(markdown, m, regular);
    return {m.position(), m.length()};
}

std::string Linebreak::toHTML(const std::string &markdown) {
    nlohmann::json data = nlohmann::json();
    return Templater::renderFormat("Linebreak.html", data);
}
