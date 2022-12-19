cmake_minimum_required(VERSION 3.24)
project(regexMDToHTML)

set(CMAKE_CXX_STANDARD 17)

add_executable(regexMDToHTML main.cpp Formatters/AbstractFormatter.h Formatters/LaTeX.cpp Formatters/LaTeX.h Formatters/Code.cpp Formatters/Code.h Formatters/Header.cpp Formatters/Header.h DocPart.h Formatters/BoldAndItalic.cpp Formatters/BoldAndItalic.h Formatters/URL.cpp Formatters/URL.h Formatters/Image.cpp Formatters/Image.h nlohmann/json.hpp inja.hpp Parser.cpp Parser.h Templater.cpp Templater.h PageConverter/DocumentConverter.cpp PageConverter/DocumentConverter.h FileConverter/HTMLtoMDFileConverter.cpp FileConverter/HTMLtoMDFileConverter.h Formatters/Linebreak.cpp Formatters/Linebreak.h FileConverter/DirConverter.cpp  FileConverter/DirConverter.h FileConverter/RecursiveConverter.cpp FileConverter/RecursiveConverter.h Formatters/Line.cpp Formatters/Line.h CLI11.hpp)
