//
// Created by hdefalt on 05.12.22.
//

#include "BoldAndItalic.h"
#include "../nlohmann/json.hpp"
#include "../Templater.h"

std::regex BoldAndItalic::regular = std::regex(R"((\*+)(\s*)([^\*]*)(\s*)(\*+))");


DocPart BoldAndItalic::findMatch(const std::string &markdown) {
    std::smatch m;
    std::regex_search(markdown, m, regular);
    return {m.position(), m.length()};
}

std::string BoldAndItalic::toHTML(const std::string &markdown) {
    std::smatch m;
    std::regex_search(markdown, m, regular);
    int type = m[1].length();
    if (type > m[5].length()) {
        type = m[5].length();
    }
    nlohmann::json data = nlohmann::json();
    data["val"] = m[3];
    switch (type) {
        case 1:
            return Templater::renderFormat("Italic.html", data);
        case 2:
            return Templater::renderFormat("Bold.html", data);
        default:
            return Templater::renderFormat("ItalicBold.html", data);
    }
}
