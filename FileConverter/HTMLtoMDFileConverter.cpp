//
// Created by hdefalt on 14.12.22.
//

#include <fstream>
#include "HTMLtoMDFileConverter.h"
#include "../Parser.h"
#include "../PageConverter/DocumentConverter.h"

void HTMLtoMDFileConverter::convert(const std::string &from, const std::string &to) {
    std::ifstream f(from);
    std::string line;
    std::string test;
    while (f) {
        std::getline(f, line);
        if (!f) {
            break;
        }
        if (line[line.length() - 1] == '\r') {
            line = line.substr(0, line.length() - 1);
        }
        test += line + '\n';
    }
    auto ans = DocumentConverter::convert(test);
    f.close();
    std::ofstream of(to);
    of << ans;
    of.close();
}
