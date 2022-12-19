//
// Created by hdefalt on 08.12.22.
//

#include "Templater.h"
#include "inja.hpp"

std::string Templater::formatDir = "/home/hdefalt/testplates/Formats/";
std::string Templater::pageDir = "/home/hdefalt/testplates/Pages/";

/**
 * renders data by a template at file
 *
 * @param fileName - name of file of template
 * @param data - data to render
 * @return rendered html
 */
std::string Templater::render(const std::string &fileName, const nlohmann::json &data) {
    inja::Environment env;
    inja::Template temp = env.parse_template(fileName);
    std::string res = env.render(temp, data);
    return res;
}

/**
 * renders a data by name of format context type
 *
 * @param name name of format context type (with extension)
 * @param data data to render
 * @return rendered html
 */
std::string Templater::renderFormat(const std::string &name, const nlohmann::json &data) {
    return render(formatDir + name, data);
}

/**
 * renders a data by name of page type
 *
 * @param name name of a page type (with extension)
 * @param data data to render
 * @return rendered html
 */
std::string Templater::renderPage(const std::string &name, const nlohmann::json &data) {
    return render(pageDir + name, data);
}

void Templater::setDirs(const std::string &dirName) {
    Templater::formatDir = dirName + "Formats/";
    Templater::pageDir = dirName + "Pages/";
}
