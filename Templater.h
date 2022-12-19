//
// Created by hdefalt on 08.12.22.
//

#ifndef REGEXMDTOHTML_TEMPLATER_H
#define REGEXMDTOHTML_TEMPLATER_H


#include <string>
#include "nlohmann/json.hpp"

/**
 * manager of  html templates
 */
class Templater {
public:
    static std::string renderFormat(const std::string &name, const nlohmann::json &data);

    static std::string renderPage(const std::string &name, const nlohmann::json &data);

    static std::string render(const std::string &fileName, const nlohmann::json &data);

    static void setDirs(const std::string &dirName);

private:
    static std::string formatDir;
    static std::string pageDir;
};


#endif //REGEXMDTOHTML_TEMPLATER_H
