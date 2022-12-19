#include "Parser.h"
#include "FileConverter/RecursiveConverter.h"
#include "CLI11.hpp"
#include "Templater.h"

class set;

int main(int argc, char** argv) {
    CLI::App app{"Markdown to HTML converter"};
    std::string from = ".";
    std::string to = "../md2html";
    std::string templates = std::string(getenv("HOME")) + "/templates/";
    app.add_option("-f,--from", from, "A location of docs to convert");
    app.add_option("-d,--dest", to, "A destination of docs");
    app.add_option("-t,--templates", templates, "A location of HTML Inja templates");
    try {
        app.parse(argc, argv);
    } catch (const CLI::ParseError &e) {
        return app.exit(e);
    }
    if (from[from.length() - 1] != '/') {
        from += '/';
    }
    if (!std::filesystem::is_directory(from)) {
        std::cout << "The source directory doesn't exist" << std::endl;
        return 1;
    }
    if (!std::filesystem::is_directory(to)) {
        if (to[to.length() - 1] != '/') {
            to += '/';
        }
        std::filesystem::create_directories(to);
    }
    if (templates[templates.length() - 1] != '/' && std::filesystem::is_directory(templates)) {
        templates += '/';
    }
    Templater::setDirs(templates);
    RecursiveConverter::convert(from, to);
    return 0;
}