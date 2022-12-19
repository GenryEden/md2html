//
// Created by hdefalt on 16.12.22.
//

#include "DirConverter.h"
#include "../nlohmann/json.hpp"
#include "../Templater.h"
#include <dirent.h>
#include <cstring>
#include <regex>
#include <fstream>

/**
 * generates an HTML representation of direcory
 * @param dirName - name of directory to be represented
 * @return HTML representation of directory
 */
std::string DirConverter::convert(const std::string &dirName) {

    DIR *dir = opendir(dirName.data());
    if (dir == nullptr) {
        throw std::exception();
    }
    std::regex mdReg("(^\\.*).md");
    struct dirent *entry;

    nlohmann::json data;

    int dirCnt = 0;
    int fileCnt = 0;

    while ((entry = readdir(dir)) != nullptr) {
        if (entry->d_type == DT_DIR) {
            data["dirs"][dirCnt]["name"] = entry->d_name;
            data["dirs"][dirCnt]["link"] = entry->d_name;
            dirCnt++;
        } else if (entry->d_type == DT_REG) {
            if (entry->d_name[0] == '.') {
                continue;
            }
            std::string name = entry->d_name;
            std::size_t found = name.find(".md");
            if (found != std::string::npos) {
                data["files"][fileCnt]["name"] = name.substr(0, name.length()-3);
                data["files"][fileCnt]["link"] = name.substr(0, name.length()-3) + ".html";
                fileCnt++;
            }
        }
    }

    closedir(dir);

    return Templater::renderPage("dir.html", data);
}

/**
 * writes HTML representation of directory to file
 * @param dirName - name of directory to be represented
 * @param whereTo - name of file
 */
void DirConverter::toFile(const std::string &dirName, const std::string &whereTo) {
    std::ofstream of(whereTo);
    std::string res = DirConverter::convert(dirName);
    of << res;
    of.close();
}

