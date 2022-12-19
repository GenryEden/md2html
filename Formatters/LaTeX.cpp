//
// Created by hdefalt on 05.12.22.
//

#include "LaTeX.h"
#include "../nlohmann/json.hpp"
#include "../Templater.h"

std::regex LaTeX::regular = std::regex(R"((\${1,2})([^\$]*?)(\${1,2}))");

DocPart LaTeX::findMatch(const std::string &markdown) {
    std::smatch m;
    std::regex_search(markdown, m, regular);
    return {m.position(), m.length()};
}

std::string LaTeX::toHTML(const std::string &markdown) {
    std::smatch m;
    std::regex_search(markdown, m, regular);
    nlohmann::json data = nlohmann::json();
    data["val"] = m[2];
    int level = m[1].length() > m[3].length() ? m[3].length() : m[1].length();
    if (level == 1) {
        return Templater::renderFormat("LaTeXInline.html", data);
    } else {
        return Templater::renderFormat("LaTeX.html", data);
    }
}
