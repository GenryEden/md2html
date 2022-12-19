//
// Created by hdefalt on 18.12.22.
//

#include <dirent.h>
#include <sys/stat.h>
#include <filesystem>
#include "RecursiveConverter.h"
#include "DirConverter.h"
#include "HTMLtoMDFileConverter.h"

/**
 * converts all files in directory and subdirectories and generate indexes for each directory
 *
 * @param from - directory where stored all the data to convert (with slash at end)
 * @param to - directory where to store all the converted data (with slash at end)
 */
void RecursiveConverter::convert(const std::string &from, const std::string &to) {
    DirConverter::toFile(from, to + "index.html");

    DIR *dir = opendir(from.data());
    if (dir == nullptr) {
        throw std::exception();
    }
    struct dirent *entry;

    while ((entry = readdir(dir)) != nullptr) {
        if (entry->d_name[0] == '.') {
            continue;
        }
        if (entry->d_type == DT_DIR) {
            std::filesystem::create_directories(to+entry->d_name+'/');
            convert(from + entry->d_name + '/', to + entry->d_name + '/');
        } else if (entry->d_type == DT_REG) {
            std::string name = entry->d_name;
            std::size_t found = name.find(".md");
            if (found != std::string::npos) {
                HTMLtoMDFileConverter::convert(from + name,
                                               to+name.substr(0, name.length() - 3) + ".html");
            }
        }
    }

}
